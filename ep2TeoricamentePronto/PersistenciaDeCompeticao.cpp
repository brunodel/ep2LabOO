#include "PersistenciaDeCompeticao.h"
#include <fstream>
#include <stdexcept>

using namespace std;

PersistenciaDeCompeticao::PersistenciaDeCompeticao()
{

}

PersistenciaDeCompeticao::~PersistenciaDeCompeticao()
{

}

Competicao* PersistenciaDeCompeticao::carregar(string arquivo)
{
    ifstream input;
    input.open(arquivo);
    if (input.fail()) throw new invalid_argument(" ");
    input >> quantidadeEquipes;
    equipes = new Equipe*[quantidadeEquipes];

    for (int i = 0; i < quantidadeEquipes; i++) {
        string tempNome;
        input >> tempNome;
        equipes[i] = new Equipe(tempNome);
    }

    input >> nomeCompeticao;
    input >> m;

    if(m) {
        minhaCompeticao = new CompeticaoMultimodalidades(nomeCompeticao, equipes, quantidadeEquipes);
        CompeticaoMultimodalidades* competicaoM = dynamic_cast<CompeticaoMultimodalidades*>(minhaCompeticao);
        input >> numeroModalidades;
        for (int nMod = 0; nMod < numeroModalidades; nMod++) {
            input >> nomeModalidade;
            input >> resultado;
            input >> quantidadeEquipesParticipantes;

            list<string>* nomeEquipesPartipantes = new list<string>();
            Equipe** equipesParticipantes = new Equipe*[quantidadeEquipesParticipantes];

            for (int i = 0; i < quantidadeEquipesParticipantes; i++){
                input >> nomeEquipe;
                nomeEquipesPartipantes -> push_back(nomeEquipe);
            }
            for (int i = 0; i < quantidadeEquipesParticipantes; i++) {
                for (int j = 0; j < quantidadeEquipes; j++){
                        if (equipes[j] -> getNome() == nomeEquipesPartipantes -> front())
                            equipesParticipantes[i] = equipes[j];
                }
                nomeEquipesPartipantes -> pop_front();
            }
            Modalidade* tempMod = new  Modalidade(nomeModalidade, equipesParticipantes, quantidadeEquipes);
            if(resultado) {
                tempMod->setResultado(equipesParticipantes);
            }
            competicaoM -> adicionar(tempMod);
        }
    input.close();
    return competicaoM;
    }

    else {
        input >> nomeModalidade;
        input >> resultado;
        input >> quantidadeEquipesParticipantes;

        list<string>* nomeEquipesPartipantes = new list<string>();
        Equipe** equipesParticipantes = new Equipe*[quantidadeEquipesParticipantes];
        for (int i = 0; i < quantidadeEquipesParticipantes; i++){
            input >> nomeEquipe;
            nomeEquipesPartipantes -> push_back(nomeEquipe);
        }
        for (int i = 0; i < quantidadeEquipesParticipantes; i++) {
              for (int j = 0; j < quantidadeEquipes; j++){
                if (equipes[j] -> getNome() == nomeEquipesPartipantes -> front())
                equipesParticipantes[i] = equipes[j];
              }

            nomeEquipesPartipantes -> pop_front();
        }
        minhaModalidade = new Modalidade(nomeModalidade, equipesParticipantes, quantidadeEquipes);
        if(resultado) {
            minhaModalidade -> setResultado(equipesParticipantes);
        }
        minhaCompeticao = new CompeticaoSimples(nomeCompeticao, equipes, quantidadeEquipes, minhaModalidade);
    }
    input.close();
    return minhaCompeticao;
}

void PersistenciaDeCompeticao::salvar(string arquivo, Competicao* c)
{
    ofstream output;

    output.open(arquivo, ios_base::app);

    if (output.fail()) throw new invalid_argument(" ");

    output << c -> getQuantidadeDeEquipes() << " ";
    for(int i = 0; i < c -> getQuantidadeDeEquipes(); i++) {
        minhaEquipe = c -> getEquipes()[i];
        output << minhaEquipe -> getNome() << " ";
    }
    output << " " << endl;
    output << c -> getNome() << endl;

    CompeticaoSimples *c1 = dynamic_cast<CompeticaoSimples*>(c);
    if(c1 != NULL){
        output << "0" << endl;
        minhaModalidade = c1 -> getModalidade();
        output << minhaModalidade -> getNome() << endl;
        if(minhaModalidade -> temResultado()){
            output << "1" << " "; }
        else {
            output << "0" << " "; }
        quantidadeEquipes = minhaModalidade -> getQuantidadeDeEquipes();
        output << quantidadeEquipes << " ";
        for(int i = 0; i < quantidadeEquipes; i++) {
            output << (minhaModalidade->getEquipes()[i]) -> getNome() << " ";
        }
    }

    CompeticaoMultimodalidades *c2 = dynamic_cast<CompeticaoMultimodalidades*>(c);
    if(c2 != NULL){
        output << "1" << endl;
        numeroModalidades = (c2 -> getModalidades()) -> size();
        output << numeroModalidades << endl;

        list<Modalidade*>::iterator j = (c2 -> getModalidades()) -> begin();
        while (j != (c2 -> getModalidades()) -> end()) {
            output << (*j)->getNome() << endl;
            minhaModalidade = *j;
            if(minhaModalidade -> temResultado()) {
                output << "1" << " ";
            }
            else {
                output << "0" << " ";
            }
            output << minhaModalidade -> getQuantidadeDeEquipes() << " ";
            for(int i = 0; i < minhaModalidade -> getQuantidadeDeEquipes(); i++){
                output << (minhaModalidade -> getEquipes()[i])->getNome() << " ";
            }
            output << " " << endl;
            j++;
        }
    }
    output.close();
}
