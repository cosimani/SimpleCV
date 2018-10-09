#include <QApplication>
#include "visor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Visor visor;
    visor.showMaximized();

    return a.exec();
}



