#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "ruas.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    ruas paralela;

protected:
    void paintEvent(QPaintEvent *e);
private slots:
    void on_pushButtonVai_clicked();
};

#endif // DIALOG_H
