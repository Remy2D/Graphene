#ifndef GRAPHENE_NOTE_LIST_REPOSITORY_H
#define GRAPHENE_NOTE_LIST_REPOSITORY_H

#include "model/NoteListModel.h"

namespace dao {

class NoteListRepository {
public:
    NoteListRepository();

    std::list<Note *> fetchNoteList();

private:
    QString fakeNote;
};

}  // namespace dao

#endif  // GRAPHENE_NOTE_LIST_REPOSITORY_H