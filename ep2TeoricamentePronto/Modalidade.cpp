#include "Modalidade.h"


Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade) {
    if(quantidade < 2) throw new invalid_argument(" ");
    this-> nome = nome;
    this-> participantes = participantes;
    this-> quantidade = quantidade;
    resultado = false;
}

string Modalidade::getNome()
{
    return nome;
}

Equipe** Modalidade::getEquipes()
{
    return participantes;
}

int Modalidade::getQuantidadeDeEquipes()
{
    return quantidade;
}

void Modalidade::setResultado(Equipe** ordem)
{
    participantes = ordem;
    resultado = true;
}

bool Modalidade::temResultado()
{
    return resultado;
}

TabelaComOrdem* Modalidade::getTabela()
{
    tabelaOrdenada = new TabelaComOrdem(participantes, quantidade);
    if(temResultado()){
        tabelaOrdenada->setResultado(participantes);
    }
    return tabelaOrdenada;
}

void Modalidade::imprimir()
{
    cout << "Modalidade: " << nome << endl;
    tabela = getTabela();
    tabela -> imprimir();
    //getTabela() -> imprimir();
}

Modalidade::~Modalidade()
{

}
