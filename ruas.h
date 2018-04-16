#ifndef RUAS_H
#define RUAS_H
#include "carro.h"
#include <vector>

using namespace std;

class ruas
{
public:
    ruas();

    // MÉTODOS //
    void queOsJogosComecem();

    // GETTERS //
    carro getCar(int i);
    int getNumCarros() const;
    double getComprimentoRua() const;
    double getLarguraRua() const;

private:
    vector <carro> skyline;

    int numCarros,numFaixas;
    double comprimentoRua, larguraRua;

    // MÉTODOS //

    int chooseFaixa();
    double chooseX(int i);
    void lookAround();
    void takeDecision();
    void makeDecision();
};

#endif // RUAS_H
