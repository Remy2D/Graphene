#include "Note.h"
#include "utils/Digest.h"

#include <QUuid>

Note::Note() : Note("", "") {
}

Note::Note(const QString &html, const QString &plainText) {
    id = QUuid::createUuid();
    content = html;
    digest = Digest::digest(plainText);

    lastModifiedDate = creationDate = QDateTime::currentDateTime();
}

void Note::update(const QString &html, const QString &plainText) {
    content = html;
    digest = Digest::digest(plainText);

    lastModifiedDate = QDateTime::currentDateTime();
}

bool operator<(const Note &lhs, const Note &rhs) {
    return lhs.lastModifiedDate < rhs.lastModifiedDate;
}