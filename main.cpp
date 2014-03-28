#include "graficos.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graficos w;

    w.resize(400,400);
    w.puntoMedioCirculo(67);
    w.puntoMedioCirculo(80);
    w.puntoMedioCirculo(150);

    w.cuatro_conexa(0,0,Qt::white, Qt::red);
    w.cuatro_conexa(70,0,Qt::white, Qt::blue);
    w.cuatro_conexa(81,0,Qt::white, Qt::yellow);

    w.render();
    w.show();

    return a.exec();
}
