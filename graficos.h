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
    void fuerzaBrutaCirculo(int r);
    void puntoMedioCirculo(int r);
    void fuerzaBrutaLinea(int x1, int y1, int x2, int y2);
    void dda(int x1, int y1, int x2, int y2);
    void ddaSimetrico(int x1, int y1, int x2, int y2);

protected:
    void paintEvent(QPaintEvent * event);
    void dibujar_pixel(int x,int y);
    void puntos_Circulo(int x, int y);
    void plano();
    int signo(double x);

private:
    int centrox;
    int centroy;

};

#endif // GRAFICOS_H
