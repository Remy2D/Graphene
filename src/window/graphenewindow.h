#ifndef GRAPHENEWINDOW_H
#define GRAPHENEWINDOW_H

#include "src/dao/NoteListRepository.h"
#include "src/model/NoteListModel.h"
#include "src/window/NoteListManager.h"
#include "src/window/TextEditManager.h"

#include <QKeyEvent>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGroupBox>
#include <QPushButton>
#include <vector>
#include <QToolButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QSettings>
#include <QSplitter>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QProgressDialog>
#include <QAction>
#include <QScrollBar>
#include <QShortcut>
#include <QTextStream>
#include <QScrollArea>
#include <QProgressDialog>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QList>
#include <QWidgetAction>

class Ui_GrapheneWindow;

class GrapheneWindow : public QMainWindow {
Q_OBJECT

public:
    explicit GrapheneWindow(QWidget *parent = nullptr);

    ~GrapheneWindow() override;

private:
    Ui_GrapheneWindow *ui;
//    Ui::graphenewindow *ui;
    NoteListModel *noteListModel;
    NoteListManager *noteListManager;
    dao::NoteListRepository noteListRepository;

    void setupSignalsSlots();

    void keyReleaseEvent(QKeyEvent *ev) override;

private slots:

    void onDeleteButtonPressed();

    void onAddNoteButtonPressed();

    void onCheckListButtonPressed();

    void onViewNoteSelected(const QModelIndex &index);

};

#endif  // GRAPHENEWINDOW_H
