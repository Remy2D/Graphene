#include "graphenewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GrapheneWindow w;
    w.show();

    return a.exec();
}
