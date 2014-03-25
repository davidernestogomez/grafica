#include "graficos.h"
#include <QPainter>
#include <cmath>
#include <iostream>

using namespace std;

Graficos::Graficos(QWidget *parent)
    : QWidget(parent)
{
centrox = 200;
centroy = 200;
}

Graficos::~Graficos()
{

}

void Graficos::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);


    fuerzaBruta(40);
    puntoMedioCirculo(70);



}


void Graficos::dibujar_pixel(int x, int y){

    QPainter qp(this);
    QPen pen(Qt::black, 1, Qt::SolidLine);
    qp.setPen(pen);

    if(x<0 && y>0)
    {

        x = centrox - abs(x);
        y = centroy - abs(y);

    }
    else if(x>0 && y>0)
    {
        x = centrox + abs(x);
        y = centroy - abs(y);

    }
    else if(x<0 && y<0)
    {

        x = centrox - abs(x);
        y = centroy + abs(y);
    }
    else if(x>0 && y<0)
    {

        x = centrox + abs(x);
        y = centroy + abs(y);
    }

    qp.drawPoint(x,y);





}


void Graficos::fuerzaBruta(int r)
{
    double y1,y2;
    for(int x=-r;x<r;x++)
    {
        y1 = sqrt((r*r) - (x*x));
        y2 = - sqrt((r*r) - (x*x));
        dibujar_pixel(x, (int)round(y1));
        dibujar_pixel(x, (int)round(y2));

    }

}


void Graficos::puntos_Circulo(int x, int y)
{
    dibujar_pixel(x,y);
    dibujar_pixel(y,x);
    dibujar_pixel(y,-x);
    dibujar_pixel(x,-y);
    dibujar_pixel(-x,-y);
    dibujar_pixel(-y,-x);
    dibujar_pixel(-y,x);
    dibujar_pixel(-x,y);

}





void Graficos::puntoMedioCirculo(int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 1 - r;
    puntos_Circulo(x,y);

    while(y > x){

        if(d < 0)
        {
            d = d + 2*x + 3;
            x = x + 1;
        }else
        {
            d = d + 2*(x-y) + 5;
            x = x + 1;
            y = y - 1;
        }

    puntos_Circulo(x,y);

    }

}

