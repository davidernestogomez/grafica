#include "graficos.h"
#include <iostream>
#include <QApplication>
#include <QtGui>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graficos w;
    int n,r;
    w.resize(400,400);

		  
		cout<<"ingrese el radio: ";
    cin>> r;
    cout<<endl;
    cout<<"ingrese el n° lados: ";
    cin>> n;

		

    w.parcial(n,r);

		

    w.render();
    w.show();




    return a.exec();
}
