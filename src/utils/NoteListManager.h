#ifndef GRAPHENE_NOTE_LIST_MANAGER_H
#define GRAPHENE_NOTE_LIST_MANAGER_H

#include "dao/NoteListRepository.h"
#include "model/NoteListModel.h"
#include "text/GrapheneTextEdit.h"

#include <QtWidgets/QListView>

class NoteListManager {
public:
    explicit NoteListManager(NoteListModel* model, GrapheneTextEdit* textEdit, QListView* noteListView, dao::NoteListRepository& noteListRepository);
    void saveNote(int oldIndex);
    void saveCurrentNote();
    void loadNote(int newIndex);
    void deleteCurrentNote();

private:
    NoteListModel *noteListModel;
    QListView *noteListView;
    GrapheneTextEdit *textEdit;
    dao::NoteListRepository& noteListRepository;
};

#endif  // GRAPHENE_NOTE_LIST_MANAGER_H
