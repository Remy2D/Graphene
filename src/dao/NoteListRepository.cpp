#include "Bind.h"
#include "NoteListRepository.h"
#include "common/Configuration.h"
#include "common/Logger.h"
#include "NoteBuilder.h"

#include <iostream>
#include <QString>
#include <list>
#include <boost/filesystem/operations.hpp>

dao::NoteListRepository::NoteListRepository() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    auto databasePath = getConfiguration().getPath(config::PropertyKey::DATABASE_FILE_PATH);

    dbFileExists(databasePath);
    dbConnected(databasePath);
    dbInitialized();
}

void dao::NoteListRepository::dbFileExists(const std::string &databasePath) {
    if (!boost::filesystem::exists(databasePath)) {
        std::ofstream dbFile(databasePath);
        dbFile.open(databasePath, std::ios::out);
        dbFile.flush();
        dbFile.close();
    }
}

void dao::NoteListRepository::dbConnected(const std::string &databasePath) {
    db.setDatabaseName(QString::fromStdString(databasePath));

    if (db.open()) {
        LOG_INFO("Connected to database");
    } else {
        LOG_ERROR("Unable to connect to database: " << databasePath);
        throw std::exception();
    }
}

void dao::NoteListRepository::dbInitialized() {
    execute(R"(
        CREATE TABLE IF NOT EXISTS notes (
                          id UUID PRIMARY KEY,
                          creation_date INTEGER NOT NULL,
                          last_modified_date INTEGER NOT NULL,
                          content TEXT,
                          digest TEXT
        );
    )");
}

std::list<Note> dao::NoteListRepository::fetchNoteList() {
    auto query = execute(R"(
        SELECT * FROM notes;
    )");

    std::list<Note> list;
    while (query.next()) {
        list.push_back(buildNote(query));
    }

    return list;
}

void dao::NoteListRepository::updateNote(const Note &note) {
    auto queryTemplate = QString::fromStdString(R"(
    INSERT OR REPLACE INTO notes (
            id,
            creation_date,
            last_modified_date,
            content,
            digest
            ) VALUES ('%1', %2, %3, '%4', '%5');
    )");

    bind(queryTemplate, note.id);
    bind(queryTemplate, note.creationDate);
    bind(queryTemplate, note.lastModifiedDate);
    bind(queryTemplate, note.content);
    bind(queryTemplate, note.digest);

    execute(queryTemplate);
}

void dao::NoteListRepository::deleteNote(const Note &note) {
    auto queryTemplate = QString::fromStdString(R"(DELETE FROM notes WHERE id='%1')");

    bind(queryTemplate, note.id);
    execute(queryTemplate);
}

QSqlQuery dao::NoteListRepository::execute(const QString &statement) {
    QSqlQuery query;

    bool success = query.exec(statement);

    if (success) {
        return query;
    } else {
        LOG_ERROR("Error executing query: " << statement.toStdString());
        throw std::exception();
    }
}

Note dao::NoteListRepository::buildNote(const QSqlQuery &query) {
    NoteBuilder nb;
    return nb.id(query.value("id"))
            .creationDate(query.value("creation_date"))
            .lastModifiedDate(query.value("last_modified_date"))
            .content(query.value("content"))
            .digest(query.value("digest"))
            .build();
}
