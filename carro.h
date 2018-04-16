#ifndef CARRO_H
#define CARRO_H
#include <vector>

using namespace std;
// mudando
class carro
{
public:
    carro();
    vector <carro *> viz;

    // MÉTODOS //
    void cleanViz();
    void addViz(carro *aux);
    void soVai();
    void atua();

    // GETTERS SETTERS //

    void setX(double value);
    void setFaixa(int value);
    int getFaixa() const;
    double getX() const;
    double getFrontRay() const;
    double getLateralRay() const;

private:
    bool ligeirinho;
    int faixa; // faixa e x serão escolhidos no construtor do ambiente
    double frontRay,lateralRay; // alertaVermelho
    double x,vx,a,desa;

    // MÉTODOS //
//    bool chooseLigeirinho();
    void vaiAcelerando();
    void desacelera();
    void desaceleraSuave();
    void mudaFaixa();
    double menorDistFrente();   
};

#endif // CARRO_H
