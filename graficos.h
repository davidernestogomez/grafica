#ifndef GRAFICOS_H
#define GRAFICOS_H

#include <QtGui>
#include <QLabel>
#include <qmainwindow.h>

class Graficos : public QMainWindow
{
    Q_OBJECT

public:
    Graficos();
    ~Graficos();
    void fuerzaBrutaCirculo(int r);
    void puntoMedioCirculo(int r);
    void fuerzaBrutaLinea(int x1, int y1, int x2, int y2);
    void dda(int x1, int y1, int x2, int y2);
    void ddaSimetrico(int x1, int y1, int x2, int y2);
    void cuatro_conexa(int x ,int y, QColor colorn, QColor colorv);
    void render();
    void parcial(int n,int radio);

protected:

    QPoint coor(int x, int y);
    QColor color(int x, int y );
    void dibujar_pixel(int x, int y);
    void mifuncion2(int x1, int y1, int x2, int y2);
    void puntos_Circulo(int x, int y);
    double signo(double x);

private:

    QLabel *label;
		QPainter *qp;    
		QImage imagen;
    int centrox;
    int centroy;
    




};

#endif // GRAFICOS_H
