#include "carro.h"
#include <stdlib.h>
#include <math.h>

carro::carro()
{
    this->vx=20;
    a=3;
    desa=10;
    lateralRay=10*((double)rand()/RAND_MAX);
    frontRay=15*((double)rand()/RAND_MAX);
//    alertaVermelho=4*((double)rand()/RAND_MAX);
//   ligeirinho=chooseLigeirinho();
}

void carro::soVai()
{
    double menorDist=menorDistFrente();
    if(this->x>100) this->x-=100; // Volta para o inicio da tela; Cond contorno

    if(menorDist>this->frontRay/2) {this->vaiAcelerando();}
    else {this->mudaFaixa();}

    while(this->vx>menorDist+2) // Evitar teleporte
    {
        this->desaceleraSuave();
    }
}

void carro::atua()
{
    this->x+=this->vx;
}

void carro::vaiAcelerando()
{
    this->vx+=this->a;
    if(this->vx>30) this->vx=30;
}

void carro::desacelera()
{
    this->vx-=this->desa;
    if(this->vx<0) this->vx=0;
}

void carro::desaceleraSuave()
{
    this->vx-=1;
    if(this->vx<0) this->vx=0;
}

void carro::mudaFaixa()
{
    double distancia=this->lateralRay; // distancia é a variável que guarda a menor distância do carro lateral
    int guardaFaixa=this->faixa;

    for(int i=0; i<this->viz.size();i++)
    {
        carro aux=*viz[i];
        double d;
        int faixaViz=aux.faixa;
        if(this->faixa!=faixaViz)
        {
            d=aux.x - this->x;
            d=fabs(d);
            if(d<=distancia)
            {
                guardaFaixa=faixaViz;
                distancia=d;
            }
        }
    }

    if(distancia<=lateralRay/2) this->faixa=guardaFaixa;
    else this->desacelera();
}

        // FUNÇÕES SECUNDÁRIAS //

double carro::menorDistFrente() // Seleciona o carro mais próximo na mesma faixa
{
    double dist=this->frontRay;
    if (this->viz.size()==0) return dist;
    for(int i=0;i<viz.size();i++) // Compara com todos os carros da vizinhança
    {
        double d;
        carro aux=*viz[i];
        if(aux.getFaixa()==this->faixa) // Queremos a distância do carro da frente
        {
            d=aux.getX()-this->x;
            if(d>0 && d<dist)
            {
                dist=d;
            }
        }
    }
    return dist;
}

/*
bool carro::chooseLigeirinho()
{
    double d=rand()/RAND_MAX;
    if(d>0.6) return true;
    else return false;
}
*/

void carro::cleanViz()
{
    this->viz.clear();
}

void carro::addViz(carro *aux)
{
    this->viz.push_back(aux);
}

        // GETTERS SETTERS //

void carro::setX(double value)
{
    x = value;
}

void carro::setFaixa(int value)
{
    faixa = value;
}

double carro::getFrontRay() const
{
    return frontRay;
}

double carro::getLateralRay() const
{
    return lateralRay;
}

double carro::getX() const
{
    return x;
}

int carro::getFaixa() const
{
    return faixa;
}
