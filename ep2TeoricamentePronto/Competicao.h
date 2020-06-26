#ifndef COMPETICAO_H
#define COMPETICAO_H

#include "Modalidade.h"

class Competicao
{
    public:
        Competicao(string nome, Equipe** equipes, int quantidade);
        virtual ~Competicao();

        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();

        virtual Tabela* getTabela() = 0;
        virtual void imprimir() = 0;

    protected:
        string nome;
        Equipe** equipes;
        int quantidade;

    private:
};

#endif // COMPETICAO_H
