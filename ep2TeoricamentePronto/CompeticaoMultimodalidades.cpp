#include "CompeticaoMultimodalidades.h"

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade) : Competicao(nome, equipes, quantidade)
{
    this -> nome = nome;
    this -> quantidade = quantidade;
    this -> equipes = equipes;
    modalidades = new list<Modalidade*>();
}

vector<int>* CompeticaoMultimodalidades::criterioDePontos;

CompeticaoMultimodalidades::~CompeticaoMultimodalidades()
{
}

void CompeticaoMultimodalidades::adicionar(Modalidade* m)
{
    modalidades -> push_back(m);
}

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades()
{
    return modalidades;
}

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos)
{
    if(pontos->size() < 3) throw invalid_argument(" ");
    criterioDePontos = pontos;

}

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao)
{
    unsigned int a = posicao;
    if(posicao <= 0 || a > criterioDePontos->size()){
        return 0;
    }
    return (*criterioDePontos)[posicao - 1];
}

Tabela* CompeticaoMultimodalidades::getTabela()
{
    pontosFinal = new vector<int>({13, 10, 8, 7, 5, 4, 3, 2, 1});
    setPontuacao(pontosFinal);
    minhaTabela = new TabelaComPontos(equipes, quantidade);

    list<Modalidade*>::iterator ite  = modalidades->begin();
    while(ite != modalidades->end()){
        Modalidade* minhaMod = (*ite);
        TabelaComOrdem* tabOrdem = minhaMod -> getTabela();

        for (int i = 0; i < quantidade; i++){
            try {
                int posicao = tabOrdem -> getPosicao(equipes[i]);
                minhaTabela -> pontuar(equipes[i], getPontoPorPosicao(posicao));
            } catch (logic_error *e) {
            }
        }
    ite++;

    }
    return minhaTabela;
}

void CompeticaoMultimodalidades::imprimir()
{
    cout << nome << endl;
    tabela = getTabela();
    tabela -> imprimir();
}
