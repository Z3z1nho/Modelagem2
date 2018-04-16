#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter bolinha;
    bolinha.begin(this);
    bolinha.setPen(QColor(255,0,255));
    bolinha.setBrush(QColor(255,0,0));

    int Tx=this->geometry().width();
//    int Ty=this->geometry().height();
   double fx=(double)Tx/paralela.getComprimentoRua();
//   double fy=(double)Ty/paralela.getLarguraRua();

    for(int i=0;i<paralela.getNumCarros();i++)
    {
        carro aux=paralela.getCar(i);
        double x=aux.getX(),y=100+20*aux.getFaixa();
        x*=fx;
//        y=y*fy*paralela.getLarguraRua();
        bolinha.drawEllipse(QPointF(x,y),4,4);
    }

    bolinha.end();
}

void Dialog::on_pushButtonVai_clicked()
{
    this->paralela.queOsJogosComecem();
    this->repaint();
}
