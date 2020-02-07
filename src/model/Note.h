#ifndef GRAPHENE_NOTE_H
#define GRAPHENE_NOTE_H

#include <QDateTime>
#include <QObject>
#include <boost/algorithm/string.hpp>

struct Note {

    explicit Note(const QString &content);

    QString id;
    QDateTime creationDate;
    QDateTime lastModifiedDate;
    QString content;
    QString digest;
};

#endif //GRAPHENE_NOTE_H
