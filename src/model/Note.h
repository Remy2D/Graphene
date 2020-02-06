#ifndef GRAPHENE_NOTE_H
#define GRAPHENE_NOTE_H

#include <QDateTime>
#include <QObject>
#include <boost/algorithm/string.hpp>

class Note : public QObject {

public:
    explicit Note(const QString &content);

    const QString &getId() const {
        return id;
    }

    void setId(const QString &_id) {
        id = _id;
    }

    const QDateTime &getCreationDate() const {
        return creationDate;
    }

    void setCreationDate(const QDateTime &newCreationDate) {
        creationDate = newCreationDate;
    }

    const QDateTime &getLastModifiedDate() const {
        return lastModifiedDate;
    }

    void setLastModifiedDate(const QDateTime &newModifiedDate) {
        lastModifiedDate = newModifiedDate;
    }

    const QString &getContent() const {
        return content;
    }

    const QString &getDigest() const {
        return digest;
    }

    void setContent(const QString &newContent) {
        content = newContent;
    }

    void setDigest(const QString &newDigest) {
        digest = newDigest;
    }

private:
    QString id;
    QDateTime creationDate;
    QDateTime lastModifiedDate;
    QString content;
    QString digest;
};

#endif //GRAPHENE_NOTE_H
