#ifndef GRAPHENE_TEXT_EDIT_MANAGER_H
#define GRAPHENE_TEXT_EDIT_MANAGER_H

#include "model/NoteListModel.h"
#include "text/GrapheneTextEdit.h"

class TextEditManager {
public:
    TextEditManager(NoteListModel* model, GrapheneTextEdit* textEdit);
    void saveNote(int index);
    void loadNote(int index);

private:
    void clear();

    NoteListModel noteListModel;
    GrapheneTextEdit textEdit;
};

#endif  // GRAPHENE_TEXT_EDIT_MANAGER_H