#include "graficos.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graficos w;
    w.repaint();
    w.resize(400,400);

    w.show();

    return a.exec();
}
