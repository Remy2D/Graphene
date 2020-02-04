#include <iostream>
#include "graphenewindow.h"
#include "ui_graphenewindow.h"

GrapheneWindow::GrapheneWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::GrapheneWindow) {
    ui->setupUi(this);
    setupSignalsSlots();
}

GrapheneWindow::~GrapheneWindow() {
    delete ui;
}

void GrapheneWindow::onSaveButtonPressed() {
    std::cout << "dd" << std::flush;
}

void GrapheneWindow::setupSignalsSlots() {
    connect(ui->SaveButton, &QPushButton::pressed, this, &GrapheneWindow::onSaveButtonPressed);
}