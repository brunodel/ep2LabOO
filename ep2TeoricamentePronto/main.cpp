#include <iostream>
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"
#include "PersistenciaDeCompeticao.h"

using namespace std;
void salvarPrograma(PersistenciaDeCompeticao* persistencia, Competicao* competicao);

int main()
{
    char desejaCarregar, tipoCompeticao, temResultado;
    PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();
    string arquivo;
    string nomeEquipe, copiaNomeEquipe, nomeCompeticao, copiaNomeCompeticao, nomeModalidade, copiaNomeModalidade;
    int quantidadeEquipes, copiaQuantidadeEquipes, quantidadeModalidade, nDaEquipe;
    Equipe* equipe;
    Competicao* competicao;
    CompeticaoMultimodalidades* competicaoM;
    Modalidade* modalidade;
    Equipe** equipes;
    Equipe** ordem;

    cout << "Deseja carregar uma competicao (s/n)? ";
    cin >> desejaCarregar;
    cout << " " << endl;

    if (desejaCarregar == 's') {
        cout << "Digite o nome do arquivo: ";
        cin >> arquivo;
        competicao = persistencia ->carregar(arquivo);
        competicao -> imprimir();
    }

    else if (desejaCarregar == 'n') {
        cout << "Informe a quantidade de equipes: ";
        cin >> quantidadeEquipes;
        copiaQuantidadeEquipes = quantidadeEquipes;
        equipes = new Equipe*[copiaQuantidadeEquipes];
        for(int i = 0; i < copiaQuantidadeEquipes; i++) {
            cout << "Informe o nome da equipe " << i + 1 << ": ";
            cin >> nomeEquipe;
            copiaNomeEquipe = nomeEquipe;
            equipe = new Equipe(copiaNomeEquipe);
            equipes[i] = equipe;
        }
        cout << " " << endl;
        cout << "Informe o nome da competicao: ";
        cin >> nomeCompeticao;
        copiaNomeCompeticao = nomeCompeticao;

        cout << "Competicao simples (s) ou multimodalidades (m): ";
        cin >> tipoCompeticao;
        cout << " " << endl;

        if(tipoCompeticao == 's'){
            cout << "Informe o nome da modalidade: ";
            cin >> nomeModalidade;
            copiaNomeModalidade = nomeModalidade;
            modalidade = new Modalidade(copiaNomeModalidade, equipes, copiaQuantidadeEquipes);
            competicao = new CompeticaoSimples(copiaNomeCompeticao, equipes, copiaQuantidadeEquipes, modalidade);
            cout << "Tem resultado (s/n): ";
            cin >> temResultado;
            if(temResultado == 's'){
                ordem = new Equipe*[copiaQuantidadeEquipes];
                for(int i = 0; i < quantidadeEquipes; i++) {
                    cout << "Informe a equipe " << i + 1 << "a colocada: ";
                    cin >> nDaEquipe;
                    //copiaNomeEquipe = nomeEquipe;
                    /*for(int j = 0; j < quantidadeEquipes; j++){
                        if(equipes[j]->getNome() == copiaNomeEquipe){
                            equipe = equipes[j];
                        }
                    }*/
                    ordem[i] = equipes[nDaEquipe - 1];
                }
                modalidade -> setResultado(ordem);
                cout << " " << endl;
                salvarPrograma(persistencia, competicao);
                competicao -> imprimir();
            }
            else if(temResultado == 'n'){
                    salvarPrograma(persistencia, competicao);
                    competicao -> imprimir();
            }
        }

        else if(tipoCompeticao == 'm'){
            cout << "Informe a quantidade de modalidades: ";
            cin >> quantidadeModalidade;
            competicaoM = new CompeticaoMultimodalidades(copiaNomeCompeticao, equipes, copiaQuantidadeEquipes);
            for(int i = 0; i < quantidadeModalidade; i++){
                cout << "Informe o nome da modalidade " << i + 1 << ": ";
                cin >> nomeModalidade;
                copiaNomeModalidade = nomeModalidade;
                modalidade = new Modalidade(copiaNomeModalidade, equipes, copiaQuantidadeEquipes);
                competicaoM -> adicionar(modalidade);
                cout << "Tem resultado (s/n): ";
                cin >> temResultado;
                if(temResultado == 's'){
                    ordem = new Equipe*[copiaQuantidadeEquipes];
                    for(int j = 0; j < quantidadeEquipes; j++) {
                        cout << "Informe a equipe " << j + 1 << "a colocada: ";
                        cin >> nDaEquipe;
                        ordem[j] = equipes[nDaEquipe - 1];
                    }
                    modalidade -> setResultado(ordem);
                }
                cout << " " << endl;
            }
            salvarPrograma(persistencia, competicaoM);
            cout << " " << endl;
            competicaoM -> imprimir();
        }
    }

    return 0;
}

void salvarPrograma(PersistenciaDeCompeticao* persistencia, Competicao* competicao)
{
    char desejaSalvar;
    string arquivoSalvar, copiaArquivoSalvar;

    cout << "Deseja salvar a competicao (s/n)? ";
    cin >> desejaSalvar;
    if(desejaSalvar == 's') {
            cout << "Digite o nome do arquivo: " ;
            cin >> arquivoSalvar;
            copiaArquivoSalvar = arquivoSalvar;
            persistencia -> salvar(copiaArquivoSalvar, competicao);
    }
    else if(desejaSalvar == 'n'){
    }
}
