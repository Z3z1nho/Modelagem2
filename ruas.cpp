#include "ruas.h"
#include <stdlib.h>
#include <math.h>

ruas::ruas()
{
    this->numCarros=3;
    this->numFaixas=4;
    this->comprimentoRua=100; // Em metros
    this->larguraRua=2.5*this->numFaixas;

    for(int i=0;i<this->numCarros;i++) // Inicializar as posições e faixas; choosefaixa deu ruim
    {
        carro aux;
        this->skyline.push_back(aux);
        this->skyline[i].setX(this->chooseX(i));
        this->skyline[i].setFaixa(this->chooseFaixa());
    }
}

        // FUNÇÕES PRIMÁRIAS //


void ruas::queOsJogosComecem()
{
    lookAround();
    takeDecision();
    makeDecision();
}

void ruas::lookAround()
{
    for(int i=0; i<this->skyline.size();i++)
    {
        this->skyline[i].cleanViz(); // Limpa a vizinhança da rodada passada
        for(int j=0;j<this->skyline.size();j++)
        {
            if(i!=j) // Comparar carros diferentes
            {
                double dist;
                dist=this->skyline[j].getX()-this->skyline[i].getX();

                if(this->skyline[i].getFaixa()-1<=this->skyline[j].getFaixa() &&
                   this->skyline[j].getFaixa()<=this->skyline[i].getFaixa()+1)
                { // Verifica se o j-ésimo carro esta na mesma faixa ou nas faixas laterais //
                    if(this->skyline[i].getFaixa()==this->skyline[j].getFaixa()) // Verifica se é a mesma faixa
                    {
                        if(this->skyline[i].getFrontRay()>=dist)
                        {
                            this->skyline[i].addViz(&this->skyline[j]);
                        }
                    }
                    else // Caso sejam as faixas laterais
                    {
                        if(this->skyline[i].getLateralRay()>=fabs(dist)) // função fabs pega o módulo de dist
                        {
                            this->skyline[i].addViz(&this->skyline[j]);
                        }
                    }
                }
            }
        }
    }
}

void ruas::takeDecision()
{
    for(int i=0; i<this->numCarros;i++)
    {
        skyline[i].soVai();
    }
}

void ruas::makeDecision()
{
    for(int i=0; i<this->numCarros;i++)
    {
        skyline[i].atua();
    }
}


        // FUNÇÕES SECUNDÁRIAS //

int ruas::chooseFaixa()
{
    double d=(double)rand()/RAND_MAX;
    if (d<0.25) return 1;
    else
    {
        if(d<0.5) return 2;
        else
        {
            if(d<0.75) return 3;
            else return 4;
        }
    }


    /* deu ruim preciso ver o que ta dando errado
    double d=(double) rand()/RAND_MAX;
    double l=1/this->numFaixas;
    for(int i=1;i<=this->numFaixas;i++)
    {
        if(d<=l) return i;
        else l=(i+1)*l;
    }*/
}

double ruas::chooseX(int i)
{
    double d=this->getComprimentoRua()*((double)rand()/RAND_MAX);
    this->skyline[i].setX(d);
    for(int j=0;j<this->skyline.size();j++)
    {
        if(i!=j)
        {
            if(this->skyline[i].getX()<=this->skyline[i].getX()+2 &&
               this->skyline[i].getX()-2<=this->skyline[i].getX()) // Carros com distâncias de +-2 metros entre eles
            {
                this->skyline[i].setX(d);
            }
            else
            {
                d=this->getComprimentoRua()*((double)rand()/RAND_MAX);
                j=0;
            }
        }
    }
    return d;
}

        // GETTERS //

carro ruas::getCar(int i)
{
    return this->skyline[i];
}

int ruas::getNumCarros() const
{
    return numCarros;
}

double ruas::getComprimentoRua() const
{
    return comprimentoRua;
}

double ruas::getLarguraRua() const
{
    return larguraRua;
}
