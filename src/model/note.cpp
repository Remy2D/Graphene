#include "note.h"

Note::Note(const QString &content) {
    Note::lastModifiedDate = QDateTime::currentDateTime();
    Note::content = content;
}