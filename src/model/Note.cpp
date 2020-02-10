#include "Note.h"
#include "utils/Digest.h"

#include <QUuid>

Note::Note() : Note("", "") {
}

Note::Note(const QString &html, const QString &plainText) {
    id = QUuid::createUuid().toString();
    content = html;
    digest = Digest::digest(plainText);

    lastModifiedDate = creationDate = QDateTime::currentDateTime();
}

void Note::update(const QString &html, const QString &plainText) {
    content = html;
    digest = Digest::digest(plainText);

    lastModifiedDate = QDateTime::currentDateTime();
}
