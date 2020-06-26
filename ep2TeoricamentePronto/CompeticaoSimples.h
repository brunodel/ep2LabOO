#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H

#include "Competicao.h"

class CompeticaoSimples : public Competicao
{
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
        virtual ~CompeticaoSimples();

        virtual Modalidade* getModalidade(); //botei virtual

        Tabela* getTabela();
        void imprimir();

    protected:
        Modalidade* m;
        //Tabela* minhaTabela;

    private:
};

#endif // COMPETICAOSIMPLES_H
