#include "Tabela.h"


Tabela::Tabela(Equipe** participantes, int quantidade){
    if(quantidade < 2) throw new invalid_argument(" ");
    this-> participantes = participantes;
    this-> quantidade = quantidade;
}

Tabela::~Tabela()
{

}

/*int Tabela::getPosicao(Equipe* participante)
{
}*/

/*Equipe** Tabela::getEquipesEmOrdem()
{
}*/

int Tabela::getQuantidadeDeEquipes()
{
    return quantidade;
}

/*void Tabela::imprimir()
{
}*/


