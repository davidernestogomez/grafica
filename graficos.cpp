#include "graficos.h"
#include <QPainter>
#include <QLabel>
#include <QMainWindow>
#include <QtGui>
#include <iostream>

using namespace std;

Graficos::Graficos()
    :QMainWindow()

{
    label = new QLabel(this);
    imagen = QImage(400,400, QImage::Format_ARGB32);
    imagen.fill(Qt::white);//fondo blanco
    setCentralWidget(label);
    centrox = 200;
    centroy = 200;

    fuerzaBrutaCirculo(67);
    puntoMedioCirculo(80);

    cuatro_conexa(1,1,Qt::red, Qt::white);

    render();

}

Graficos::~Graficos()
{

}

void Graficos::render(){

    label->setPixmap(QPixmap::fromImage(imagen));
    label->show();

}


void Graficos::dibujar_pixel(int x, int y){

    if(x >=0){

        x = centrox + abs(x);

    }else if(x < 0){

        x = centrox - abs(x);
    }

    if(y >= 0){

        y = centroy - abs(y);

    }else if(y < 0){

        y = centrox + abs(y);
    }




    p.begin(&imagen);
    p.drawPoint(x, y); //dibujo el punto
    p.end();


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

        }
        else
        {
            d = d + 2*(x-y) + 5;
            x = x + 1;
            y = y - 1;
        }

    puntos_Circulo(x,y);

    }

}


void Graficos::fuerzaBrutaLinea(int _x1,int _y1,int _x2,int _y2)
{


    double x1,x2,y1,y2 ;
    x1 = (double)_x1;
    x2 = (double)_x2;
    y1 = (double)_y1;
    y2 = (double)_y2;

    double y = 0, m = 0, b = 0;
    m = (y2 - y1)/(x2 - x1); //pendiente
    b = y1 - (m * x1);       //interseccion con y

    for(int x=_x1;x<_x2;x++)
    {
        y = ( m * x )+ b;

        dibujar_pixel(x , (int)round(y) );

    }
}


void Graficos::dda(int _x1,int _y1,int _x2,int _y2)
{

    double x1,x2,y1,y2 ;
    x1 = (double)_x1;
    x2 = (double)_x2;
    y1 = (double)_y1;
    y2 = (double)_y2;


    double y = y1;
    double m = (y2 - y1)/(x2 - x1);

    for(int x=_x1;x<_x2;x++){

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

    dx = (double)(x2 - x1) / d ;
    dy = (double)(y2 - y1) / d;
    x  = (double)x1 + 0.5 * signo(dx);
    y = (double)y1 + 0.5 * signo(dy);

    for(int i=1;i<d;i++)
    {
        dibujar_pixel((int)round(x),(int)round(y));
        x = (double)x + dx;
        y = (double)y + dy;
        //i = i + 1;
    }


}


double Graficos::signo(double x){

    if(x<0){

        return -1.0;

    }else{

        return 1.0;
    }

}

QColor Graficos::color(int x, int y){

    QColor color(imagen.pixel(x,y));

    return color;
}


void Graficos::cuatro_conexa(int x ,int y, QColor target_color, QColor new_color){

    if( color(x,y) != target_color){
        cout<<"4-conexa"<<endl;
        return;
    }



    new_color = target_color;

    cuatro_conexa(x-1,y,target_color,new_color);
    cuatro_conexa(x+1,y,target_color,new_color);
    cuatro_conexa(x,y+1,target_color,new_color);
    cuatro_conexa(x,y-1,target_color,new_color);
    cout<<"4-conexa"<<endl;
}






