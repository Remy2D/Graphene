#ifndef GRAPHENE_NOTE_H
#define GRAPHENE_NOTE_H

#include <QDateTime>
#include <QObject>

class Note : public QObject {

public:
    Note();

    const QString &getId() const {
        return id;
    }

    void setId(const QString &id) {
        Note::id = id;
    }

    const QDateTime &getCreationDate() const {
        return creationDate;
    }

    void setCreationDate(const QDateTime &creationDate) {
        Note::creationDate = creationDate;
    }

    const QDateTime &getLastModifiedDate() const {
        return lastModifiedDate;
    }

    void setLastModifiedDate(const QDateTime &lastModifiedDate) {
        Note::lastModifiedDate = lastModifiedDate;
    }

    const QString &getContent() const {
        return content;
    }

    void setContent(const QString &content) {
        Note::content = content;
    }

    const QString &getTitle() const {
        return title;
    }

    void setTitle(const QString &title) {
        Note::title = title;
    }

private:
    QString id;
    QDateTime creationDate;
    QDateTime lastModifiedDate;
    QString title;
    QString content;
};

#endif //GRAPHENE_NOTE_H
