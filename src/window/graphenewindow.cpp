#include "graphenewindow.h"
#include "build-graphene-debug/ui_graphenewindow.h"
#include "src/model/NoteListModel.h"
#include <QStringListModel>
#include <QtGui/QTextDocumentFragment>
#include <src/common/Logger.h>

GrapheneWindow::GrapheneWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui_GrapheneWindow) {

    // Create UI:
    ui->setupUi(this);

    // Create model:
    noteListModel = new NoteListModel(ui->noteListView);

    ui->noteListView->setModel(noteListModel);

    noteListManager = new NoteListManager(noteListModel, ui->textEdit, ui->noteListView);

    for (auto note : noteListRepository.fetchNoteList()) {
        noteListModel->addNote(note);
    }

    //todo: assure there is at least 1:
    noteListManager->loadNote(0);

    // Enable workspace:
    ui->textEdit->setFocus();
    ui->textEdit->setMouseTracking(true);
    ui->textEdit->moveCursor(QTextCursor::End);

    setupSignalsSlots();
}

GrapheneWindow::~GrapheneWindow() {
    delete ui;

    //todo: fire autosave in destructors:
    delete noteListModel;
    delete noteListManager;
}

void GrapheneWindow::onDeleteButtonPressed() {
    LOG_DEBUG("Raw note html: \n" << ui->textEdit->toHtml().toStdString());
//    noteListModel->deleteNote(noteListModel->getSelectedIndex());
//    std::cout << "Deleted note" << std::endl;
}

void GrapheneWindow::keyReleaseEvent(QKeyEvent *ev) {
    noteListManager->saveNote(noteListModel->getSelectedIndex());

    //todo: check letters, numbers, printables in general; backspaces
    //launch timer
        //save
        //update digest
}

void GrapheneWindow::onAddNoteButtonPressed() {
//    QString content = ui->textEdit->toPlainText();
    //saveCurrent
    //switch to new at the end

    Note note("");
    noteListModel->addNote(note);

    ui->textEdit->clear();
    ui->textEdit->setFocus();
    ui->noteListView->repaint();
}

void GrapheneWindow::onCheckListButtonPressed() {
    ui->textEdit->insertCheckedListNode();
}

void GrapheneWindow::onViewNoteSelected(const QModelIndex &index) {
    noteListManager->saveCurrentNote();
    noteListManager->loadNote(index.row());
}

void GrapheneWindow::setupSignalsSlots() {
    connect(ui->deleteNoteButton, &QPushButton::pressed, this,
            &GrapheneWindow::onDeleteButtonPressed);

    connect(ui->addNoteButton, &QPushButton::pressed, this,
            &GrapheneWindow::onAddNoteButtonPressed);

    connect(ui->noteListView, &QListView::clicked, this,
            &GrapheneWindow::onViewNoteSelected);

    connect(ui->checkListButton, &QPushButton::pressed, this,
            &GrapheneWindow::onCheckListButtonPressed);
}
