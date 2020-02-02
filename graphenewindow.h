#ifndef GRAPHENEWINDOW_H
#define GRAPHENEWINDOW_H

#include <QMainWindow>

namespace Ui {
class GrapheneWindow;
}

class GrapheneWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GrapheneWindow(QWidget *parent = nullptr);
    ~GrapheneWindow();

private:
    Ui::GrapheneWindow *ui;
};

#endif // GRAPHENEWINDOW_H
