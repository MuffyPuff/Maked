#include <QCoreApplication>
#include <QTextStream>
#include "game.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    Resources test;
    test.distrubuteResources();
    test.outputResources();
    return a.exec();
}
