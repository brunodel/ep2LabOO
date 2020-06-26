#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H

//#include <stdexcept>
#include "Tabela.h"
//using namespace std;

class TabelaComOrdem : public Tabela {
    public:
        TabelaComOrdem(Equipe** participantes, int quantidade);
        virtual ~TabelaComOrdem();
        void setResultado (Equipe** ordem);

        virtual int getPosicao (Equipe* participante);
        virtual Equipe** getEquipesEmOrdem();
        virtual void imprimir();

    protected:

    private:
        bool ordenou;
};

#endif // TABELACOMORDEM_H
