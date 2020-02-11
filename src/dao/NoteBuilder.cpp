#include "HtmlSerializer.h"
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
    note.content = HtmlSerializer::deserialize(content.toString());
    return *this;
}

NoteBuilder &NoteBuilder::digest(const QVariant& digest) {
    note.digest = HtmlSerializer::deserialize(digest.toString());
    return *this;
}

Note NoteBuilder::build() {
    return note;
}
