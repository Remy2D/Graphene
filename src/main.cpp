#include "src/window/graphenewindow.h"
#include <QApplication>
//#include <QDir>
#include <QtGlobal>

int main(int argc, char *argv[])
{
//    Q_INIT_RESOURCE(resources);

    QApplication a(argc, argv);
    GrapheneWindow w;
    w.show();

    return a.exec();
}
