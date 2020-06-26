#include "TabelaComOrdem.h"

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade) : Tabela(participantes, quantidade) {
    ordenou = false;
}

TabelaComOrdem::~TabelaComOrdem()
{
    //dtor
}
void TabelaComOrdem::setResultado(Equipe** ordem)
{
    ordenou = true;
    participantes = ordem;
}

int TabelaComOrdem::getPosicao(Equipe* participante){
    if(ordenou == false) throw new logic_error("");
    bool taAqui = false;
    for(int i = 0; i < quantidade; i++){
        if(participantes[i] -> getNome() == participante -> getNome()){
            taAqui = true;
            return i + 1;
        }
    }

    if(taAqui == false) throw new invalid_argument(" ");
}

Equipe** TabelaComOrdem::getEquipesEmOrdem()
{
    if(ordenou == false) throw new logic_error(" ");
    return participantes;
}

void TabelaComOrdem::imprimir()
{
    if(ordenou){
        for(int i = 0; i < quantidade; i++){
            cout << "\t" << i + 1 << "o " << participantes[i]->getNome() << endl;
        }
    }
    else {
        for(int j = 0; j < quantidade; j++){
            cout << "\t" << participantes[j]->getNome() << endl;
        }
    }
}
