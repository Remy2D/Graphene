#ifndef GRAPHENE_NOTE_H
#define GRAPHENE_NOTE_H

#include <QDateTime>
#include <QObject>
#include <boost/algorithm/string.hpp>

struct Note {

    Note();
    explicit Note(const QString &html, const QString &plainText);

    void update(const QString &html, const QString &plainText);

    QString id;
    QDateTime creationDate;
    QDateTime lastModifiedDate;
    QString content;
    QString digest;
};

#endif //GRAPHENE_NOTE_H
