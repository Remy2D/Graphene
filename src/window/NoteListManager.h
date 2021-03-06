#ifndef GRAPHENE_NOTE_LIST_MANAGER_H
#define GRAPHENE_NOTE_LIST_MANAGER_H

#include "model/NoteListModel.h"
#include "text/GrapheneTextEdit.h"

#include <QtWidgets/QListView>

class NoteListManager {
public:
    explicit NoteListManager(NoteListModel* model, GrapheneTextEdit* textEdit, QListView* noteListView);
    void saveNote(int oldIndex);
    void saveCurrentNote();
    void loadNote(int newIndex);

private:
    NoteListModel *noteListModel;
    QListView *noteListView;
    GrapheneTextEdit *textEdit;
};

#endif  // GRAPHENE_NOTE_LIST_MANAGER_H
