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

void Graficos::plano(){

    QPainter qp(this);
    QPen pen(Qt::black, 1, Qt::SolidLine);
    qp.setPen(pen);
    qp.drawLine(centrox,centroy,200,0);
    qp.drawLine(centrox,centroy,0,200);
    qp.drawLine(centrox,centroy,400,200);
    qp.drawLine(centrox,centroy,200,400);

}



void Graficos::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    plano();
    fuerzaBrutaCirculo(40);
    puntoMedioCirculo(70);
    dda(0,0,100,100);
    ddaSimetrico(-10,50,100,100);
    ddaSimetrico(20,-80,30,100);
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


void Graficos::fuerzaBrutaCirculo(int r)
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


void Graficos::fuerzaBrutaLinea(int x1,int y1,int x2,int y2)
{
    double y;
    double m = (y1 - y2)/(x1 - x2); //pendiente
    double b = y1 - (m * x1);       //interseccion con y

    for(int x=x1;x<x2;x++)
    {
        y = m * x + b;
        dibujar_pixel(x , (int)round(y) );
    }
}


void Graficos::dda(int x1,int y1,int x2,int y2)
{
    double y =(double) y1;
    double m = (y1 - y2)/(x1 - x2);

    for(int x=x1;x<x2;x++){

    y = y + m;
    dibujar_pixel(x, (int)round(y));

    }



}


void Graficos::ddaSimetrico(int x1,int y1,int x2,int y2)
{
    int d;
    double dx,dy,x,y;

    if(abs(x2 - x1) > abs(y2 - y1))
    {
        d = abs(x2 - x1);
    }
    else
    {
        d = abs(y2 - y1);
    }

    dx = (x2 - x1) / d ;
    dy = (y2 - y1) / d;
    x  = x1 + 0.5 * signo(dx);
    y = y1 + 0.5 * signo(dy);

    for(int i=1;i<d;i++)
    {
        dibujar_pixel((int)round(x),(int)round(y));
        x = x + dx;
        y = y + dy;
        //i = i + 1;
    }


}


int Graficos::signo(double x){

    if(x<0){

        return -1;
    }else{

        return 1;
    }

}



