#ifndef MODALIDADE_H
#define MODALIDADE_H

//#include <stdexcept>
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"

//using namespace std;

class Modalidade
{
    public:
        Modalidade(string nome, Equipe** participantes, int quantidade);
        virtual ~Modalidade();

        virtual string getNome();
        virtual Equipe** getEquipes();
        virtual int getQuantidadeDeEquipes();

        virtual void setResultado(Equipe** ordem);
        virtual bool temResultado();
        virtual TabelaComOrdem* getTabela();

        virtual void imprimir();

    protected:

    private:
        string nome;
        int quantidade;
        Equipe** participantes;
        Equipe** ordem1;

        bool resultado;
        TabelaComOrdem* tabelaOrdenada;
        TabelaComOrdem* tabela;
};

#endif // MODALIDADE_H
