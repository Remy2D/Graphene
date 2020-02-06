#include <iostream>
#include "graphenewindow.h"
#include "build-graphene-debug/ui_graphenewindow.h"

GrapheneWindow::GrapheneWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::GrapheneWindow) {
    ui->setupUi(this);
    ui->textEdit->setFocus();
    setupSignalsSlots();
}

GrapheneWindow::~GrapheneWindow() {
    delete ui;
}

void GrapheneWindow::onDeleteButtonPressed() {
    std::cout << "delete" << std::endl;
}

void GrapheneWindow::onAddNoteButtonPressed() {
    std::cout << "new note" << std::endl;
}

void GrapheneWindow::setupSignalsSlots() {
    connect(ui->deleteNoteButton, &QPushButton::pressed, this, &GrapheneWindow::onDeleteButtonPressed);
    connect(ui->addNoteButton, &QPushButton::pressed, this, &GrapheneWindow::onAddNoteButtonPressed);
}