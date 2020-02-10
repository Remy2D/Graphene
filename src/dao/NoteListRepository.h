#ifndef GRAPHENE_NOTE_LIST_REPOSITORY_H
#define GRAPHENE_NOTE_LIST_REPOSITORY_H

#include "model/NoteListModel.h"

#include <QtSql>

namespace dao {

    class NoteListRepository {
    public:
        NoteListRepository();

        std::list<Note> fetchNoteList();

        void updateNote(const Note &note);

        void deleteNote(const Note &note);

    private:
        void dbFileExists(const std::string &databasePath);

        void dbConnected(const std::string &databasePath);

        void dbInitialized();

        Note buildNote(const QSqlQuery &query);

        QSqlQuery execute(const QString &statement);

        QSqlDatabase db;
    };

}  // namespace dao

#endif  // GRAPHENE_NOTE_LIST_REPOSITORY_H
