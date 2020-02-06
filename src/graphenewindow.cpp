#include <iostream>
#include "graphenewindow.h"
#include "build-graphene-debug/ui_graphenewindow.h"
#include "notelistmodel.h"
#include <QStringListModel>
#include <QtCore/QSortFilterProxyModel>

GrapheneWindow::GrapheneWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::GrapheneWindow) {

    // Create UI:
    ui->setupUi(this);

    // Create data:
    noteListModel = new NoteListModel(ui->noteListView);
    noteListModel->addNote(new Note(QString("test note")));

    //todo: try working with sort model, sort by date as separate column?
//    QSortFilterProxyModel* sortModel = new QSortFilterProxyModel(ui->noteListView);
//    sortModel->setSourceModel(noteListModel);
//    QMap<int, QVariant> dataValue;
//    dataValue[Qt::UserRole] = QVariant::fromValue(noteListModel->getNote(0));
//    noteListModel->setItemData(sortModel->index(0,0), dataValue);

    ui->noteListView->setModel(noteListModel);

    // Enable workspace:
    ui->textEdit->setFocus();
    setupSignalsSlots();
}

GrapheneWindow::~GrapheneWindow() {
    delete ui;
}

void GrapheneWindow::onDeleteButtonPressed() {
    std::cout << "Deleting note" << std::endl;
}

void GrapheneWindow::onAddNoteButtonPressed() {
    QString content = ui->textEdit->toPlainText();

    std::cout << "Inserting new note: " << content.toStdString() << std::endl;

    Note *note = new Note(content);
    noteListModel->addNote(note);

    ui->textEdit->clear();
    ui->textEdit->setFocus();
}

void GrapheneWindow::setupSignalsSlots() {
    connect(ui->deleteNoteButton, &QPushButton::pressed, this,
            &GrapheneWindow::onDeleteButtonPressed);

    connect(ui->addNoteButton, &QPushButton::pressed, this,
            &GrapheneWindow::onAddNoteButtonPressed);
}