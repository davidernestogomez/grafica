#include "graficos.h"

#include <QPainter>
#include <QLabel>
#include <QMainWindow>
#include <iostream>
#include <QtGui>
#define PI 3.1416

using namespace std;

Graficos::Graficos()
    :QMainWindow()

{

    label = new QLabel(this);
		qp = new QPainter();    
		imagen = QImage(400,400, QImage::Format_ARGB32);
    imagen.fill(Qt::white);//fondo blanco
    setCentralWidget(label);
    centrox = 200;
    centroy = 200;
    
		qp->begin(&imagen);

}

Graficos::~Graficos()
{
		qp->end();
}




void Graficos::render(){

    label->setPixmap(QPixmap::fromImage(imagen));
    label->show();

}

QPoint Graficos::coor(int x, int y){

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

return QPoint(x,y);

}


void Graficos::dibujar_pixel(int x, int y){

    
  
    qp->drawPoint(coor(x,y)); //dibujo el pixel
    


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

    return  QColor(imagen.pixel(coor(x,y)));
}


void Graficos::cuatro_conexa(int x ,int y, QColor target_color, QColor new_color){

    


    if(color(x,y) != target_color){

        return;
    }


    
    qp->setPen(QColor(new_color));
    qp->drawPoint(coor(x,y)); //dibujo el pixel
    

    cuatro_conexa(x-1,y,target_color,new_color);
    cuatro_conexa(x+1,y,target_color,new_color);
    cuatro_conexa(x,y+1,target_color,new_color);
    cuatro_conexa(x,y-1,target_color,new_color);

}






void Graficos::parcial(int n, int r){

    double rad=0.0,aumento_rad=0.0, x=0.0, y=0.0, antx=0.0, anty=0.0;
	   
	    
		aumento_rad = (2*PI) / n ; //divido 2*PI por el numero de lados para saber tamaño en radianes
                                                     // de cada "porcion"


    if(n == 1){

        dibujar_pixel(0,0);

    }else if(n == 2){
       

        qp->drawLine(coor(r,0), coor(0, 0)); //dibujo el pixel
       

    }else{

				
        while(rad <= 2*PI)
        {

						rad = rad + aumento_rad;	//sumo a rad la "porcion"					
						
						x = r * cos(rad); //convierto de polares a cartesianas
            y = r * sin(rad);	//convierto de polares a cartesianas
						
            qp->drawLine(coor(antx,anty), coor(x, y)); //dibujo el pixel

           antx = x;
					 anty = y;

            
            
					
 				}

        

        qp->drawLine(coor(x,y), coor(r, 0)); //dibujo el pixel
       	cuatro_conexa(1,1,Qt::white, Qt::yellow);


        }
}
