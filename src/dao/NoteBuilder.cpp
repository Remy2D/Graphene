#include "NoteBuilder.h"
#include "model/Note.h"
#include <QVariant>
#include <QUuid>

NoteBuilder &NoteBuilder::id(const QVariant& id) {
    note.id=id.toUuid().toString(QUuid::StringFormat::WithBraces);
    return *this;
}

NoteBuilder &NoteBuilder::creationDate(const QVariant& creationDate) {
    note.creationDate = QDateTime::fromSecsSinceEpoch(creationDate.toInt());
    return *this;
}

NoteBuilder &NoteBuilder::lastModifiedDate(const QVariant& lastModifiedDate) {
    note.creationDate = QDateTime::fromSecsSinceEpoch(lastModifiedDate.toInt());
    return *this;
}

NoteBuilder &NoteBuilder::content(const QVariant& content) {
    note.content = QString::fromStdString(boost::replace_all_copy(content.toString().toStdString(), "\'\'", "\'"));
    return *this;
}

NoteBuilder &NoteBuilder::digest(const QVariant& digest) {
    note.digest = QString::fromStdString(boost::replace_all_copy(digest.toString().toStdString(), "\'\'", "\'"));
    return *this;
}

Note NoteBuilder::build() {
    return note;
}
