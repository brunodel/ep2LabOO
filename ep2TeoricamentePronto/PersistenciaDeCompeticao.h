#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H

#include "CompeticaoMultimodalidades.h"
#include "CompeticaoSimples.h"

class PersistenciaDeCompeticao
{
    public:
        PersistenciaDeCompeticao();
        virtual ~PersistenciaDeCompeticao();

        Competicao* carregar(string arquivo);
        void salvar(string arquivo, Competicao* c);

    protected:

    private:

        Competicao* minhaCompeticao;
        Equipe* minhaEquipe;
        Modalidade* minhaModalidade;
        int quantidadeEquipes;
        int numeroModalidades;
        Equipe** equipes;
        string nomeEquipe;
        string nomeCompeticao;
        string nomeModalidade;
        bool resultado;
        int quantidadeEquipesParticipantes;
        bool m;
};

#endif // PERSISTENCIADECOMPETICAO_H
