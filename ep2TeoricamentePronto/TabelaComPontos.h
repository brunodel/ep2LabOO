#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H

#include "Tabela.h"
#include <vector>

class TabelaComPontos : public Tabela {
    public:
        TabelaComPontos(Equipe** participantes, int quantidade);
        virtual ~TabelaComPontos();

        int getPontos (Equipe* participante);
        void pontuar (Equipe* participante, int pontos);

        virtual int getPosicao (Equipe* participante);
        virtual Equipe** getEquipesEmOrdem();
        virtual void imprimir();

    protected:

    private:
        vector<int>* vetPontos;
        int posicao;
        int posicaoNoVetor;
        bool todasZero;
        int numero;

};

#endif // TABELACOMPONTOS_H
