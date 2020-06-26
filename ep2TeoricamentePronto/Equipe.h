#ifndef EQUIPE_H
#define EQUIPE_H

#include <stdexcept>
#include <iostream>

using namespace std;

class Equipe
{
    public:
        Equipe(string nome);
        virtual ~Equipe();

        virtual string getNome();
        virtual void imprimir();

    protected:

    private:
        string nome;
};

#endif // EQUIPE_H
