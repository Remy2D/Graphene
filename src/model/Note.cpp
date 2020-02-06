#include "Note.h"

Note::Note(const QString &content_) {
    lastModifiedDate = QDateTime::currentDateTime();
    content = content_;
}