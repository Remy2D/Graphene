#include <iostream>
#include "graphenewindow.h"
#include "build-graphene-debug/ui_graphenewindow.h"
#include "notelistmodel.h"
#include <QStringListModel>

GrapheneWindow::GrapheneWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::GrapheneWindow) {

    // Create UI:
    ui->setupUi(this);

    // Create data:
    noteListModel = new NoteListModel();
    ui->noteListView->setModel(noteListModel);

    // Enable workspace:
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

    Note *note = new Note();
    this->noteListModel->addNote(note);

//    auto *model = new QStringListModel(this);
//
//    model->setStringList({ui->textEdit->toPlainText()});
//
//    ui->noteListView->setModel(model);
////    ui->noteListView->model()->setData(model);

    ui->textEdit->clear();
    ui->textEdit->setFocus();
}

void GrapheneWindow::setupSignalsSlots() {
    connect(ui->deleteNoteButton, &QPushButton::pressed, this,
            &GrapheneWindow::onDeleteButtonPressed);

    connect(ui->addNoteButton, &QPushButton::pressed, this,
            &GrapheneWindow::onAddNoteButtonPressed);
}