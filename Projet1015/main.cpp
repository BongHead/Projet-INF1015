#include "GameWindow.h"
#include <QtWidgets/QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    w.show();
    return a.exec();
}
