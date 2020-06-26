#include "Competicao.h"

Competicao::Competicao(string nome, Equipe** equipes, int quantidade)
{
    if(quantidade < 2) throw new invalid_argument(" ");
    this -> nome = nome;
    this -> equipes = equipes;
    this -> quantidade = quantidade;
}

Competicao::~Competicao()
{
    //dtor
}

string Competicao::getNome()
{
    return nome;
}

Equipe** Competicao::getEquipes()
{
    return equipes;
}

int Competicao::getQuantidadeDeEquipes()
{
    return quantidade;
}

/*Tabela* Competicao::getTabela()
{

}

void Competicao::imprimir()
{

}*/
