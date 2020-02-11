#ifndef GRAPHENE_BIND_H
#define GRAPHENE_BIND_H

#include <QString>
#include <QDateTime>
#include <QUuid>

void bind(QString& string, const QUuid& time);
void bind(QString& string, const QDateTime& time);
void bind(QString& string, const QString& param);

#endif  // GRAPHENE_BIND_H
