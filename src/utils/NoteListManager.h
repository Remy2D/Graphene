#ifndef GRAPHENE_NOTE_LIST_MANAGER_H
#define GRAPHENE_NOTE_LIST_MANAGER_H

#include "dao/NoteListRepository.h"
#include "model/NoteListModel.h"
#include "text/GrapheneTextEdit.h"

#include <QtWidgets/QListView>

class NoteListManager {
public:
    explicit NoteListManager(NoteListModel* model, GrapheneTextEdit* textEdit, QListView* noteListView, dao::NoteListRepository& noteListRepository);
    void addNote();
    void saveCurrentNote();
    void loadNote(int newIndex);
    void deleteCurrentNote();
    void populateModel(QList<Note> notes);

private:
    void selectAnotherNote(int oldIndex);
    NoteListModel *noteListModel;
    QListView *noteListView;
    GrapheneTextEdit *textEdit;
    dao::NoteListRepository& noteListRepository;
};

#endif  // GRAPHENE_NOTE_LIST_MANAGER_H
