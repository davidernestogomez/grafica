#ifndef GRAFICOS_H
#define GRAFICOS_H

#include <QWidget>
#include <QPainter>

class Graficos : public QWidget
{
    Q_OBJECT

public:
    Graficos(QWidget *parent = 0);
    ~Graficos();
    void fuerzaBruta(int r);
    void puntoMedioCirculo(int r);

protected:
    void paintEvent(QPaintEvent * event);
    void dibujar_pixel(int x,int y);
    void puntos_Circulo(int x, int y);



private:
    int centrox;
    int centroy;

};

#endif // GRAFICOS_H
