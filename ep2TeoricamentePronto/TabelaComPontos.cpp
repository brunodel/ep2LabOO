#include "TabelaComPontos.h"

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade) : Tabela(participantes, quantidade)
{
    vetPontos = new vector<int>();
    for(int i = 0; i < quantidade; i++){
        vetPontos -> push_back(0);
    }
    todasZero = true;
    ordem = new Equipe*[quantidade];
}

TabelaComPontos::~TabelaComPontos()
{

}

int TabelaComPontos::getPontos(Equipe* participante)
{
    for(int j = 0; j < quantidade; j++){
        if(participantes[j] == participante){
            //return vetPontos[j];
            return (*vetPontos)[j];
        }
    }
    throw new invalid_argument(" ");

}

void TabelaComPontos::pontuar(Equipe* participante, int pontos)
{
    todasZero = false;
    bool ehParticipante = false;
    for(int i = 0; i < quantidade; i++){
        if(participantes[i] -> getNome() == participante -> getNome()){
            ehParticipante = true;
            (*vetPontos)[i] = (*vetPontos)[i] + pontos;
        }
    }
    if(ehParticipante == false) throw new invalid_argument("Equipe invalida");
}

int TabelaComPontos::getPosicao(Equipe* participante)
{
    posicao = quantidade;
    for(int j = quantidade-1; j >= 0; j--){
        if(getPontos(participante) > getPontos(participantes[j])){
            posicao = posicao - 1;
        }
    }
    return posicao;
}

Equipe** TabelaComPontos::getEquipesEmOrdem()
{
    //ordem = participantes;
    for(int i = 0; i < quantidade; i++) {
            numero = getPosicao(participantes[i]);
            ordem[numero - 1] = participantes[i];
    }
    return ordem;
}

void TabelaComPontos::imprimir()
{
    getEquipesEmOrdem();
    if(todasZero){
        for(int j = 0; j < quantidade; j++) {
            cout << "\t" << participantes[j]->getNome() << endl;
        }
    }
    else{
        for(int j = 0; j < quantidade; j++) {
            cout << "\t" << j + 1 << "o " << ordem[j] -> getNome() << " (" << getPontos(ordem[j]) << ")" << endl;
        }
    }
}
