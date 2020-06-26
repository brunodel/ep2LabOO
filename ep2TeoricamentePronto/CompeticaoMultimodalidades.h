#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

#include "Competicao.h"
#include <vector>
#include <list>



class CompeticaoMultimodalidades : public Competicao
{
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();

        void adicionar(Modalidade* m);
        virtual list<Modalidade*>* getModalidades();    //mudei para virtual

        static void setPontuacao(vector<int>* pontos);
        static int getPontoPorPosicao(int posicao);

        Tabela* getTabela();
        void imprimir();

    protected:

    private:
        list<Modalidade*>* modalidades;
        //vector<int>* pontuacao;
        TabelaComPontos* minhaTabela;
        Tabela* tabela;
        //int vetPontos;
        static vector<int>* criterioDePontos;
        vector<int>* pontosFinal;
};

#endif // COMPETICAOMULTIMODALIDADES_H
