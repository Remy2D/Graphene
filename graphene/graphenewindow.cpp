#include "graphenewindow.h"
#include "ui_graphenewindow.h"

GrapheneWindow::GrapheneWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GrapheneWindow)
{
    ui->setupUi(this);
}

GrapheneWindow::~GrapheneWindow()
{
    delete ui;
}
