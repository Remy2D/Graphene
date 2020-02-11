#include "graphenewindow.h"
#include "build-graphene/ui_graphenewindow.h"
#include <QStringListModel>
#include <QtGui/QTextDocumentFragment>

GrapheneWindow::GrapheneWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui_GrapheneWindow) {

    // Create UI:
    ui->setupUi(this);

    // Create model:
    noteListModel = new NoteListModel(ui->noteListView);

    ui->noteListView->setModel(noteListModel);
    noteListManager = new NoteListManager(noteListModel, ui->textEdit, ui->noteListView,
                                          noteListRepository);

    noteListManager->populateModel(noteListRepository.fetchNoteList());

    //Timers:
    saveEventHandler = new timer::SaveEventHandler(noteListManager);
    ui->textEdit->setSaveEventHandler(saveEventHandler);

    saveEventTimer = new QTimer();
    connect(saveEventTimer, SIGNAL(timeout()), SLOT(autosave()));
    saveEventTimer->start();

    // Enable workspace:
    ui->textEdit->setFocus();
    ui->textEdit->setMouseTracking(true);
    ui->textEdit->moveCursor(QTextCursor::End);

    setupSignalsSlots();
}

GrapheneWindow::~GrapheneWindow() {
    noteListManager->saveCurrentNote();

    saveEventTimer->stop();
    delete saveEventTimer;
    delete saveEventHandler;
    delete noteListModel;
    delete noteListManager;
    delete ui;
}

void GrapheneWindow::onDeleteButtonPressed() {
    noteListManager->deleteCurrentNote();
}

void GrapheneWindow::keyReleaseEvent(QKeyEvent *ev) {
    saveEventHandler->rescheduleSaveEvent();
    //todo: check letters, numbers, printables in general; backspaces
}

void GrapheneWindow::onAddNoteButtonPressed() {
    noteListManager->addNote();

    ui->textEdit->clear();
    ui->textEdit->setFocus();
    ui->noteListView->repaint();
}

void GrapheneWindow::onCheckListButtonPressed() {
    ui->textEdit->insertCheckedListNode();
    saveEventHandler->rescheduleSaveEvent();
}

void GrapheneWindow::onViewNoteSelected(const QModelIndex &index) {
    saveEventHandler->save();
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

void GrapheneWindow::autosave() {
    saveEventHandler->autosave();
}
