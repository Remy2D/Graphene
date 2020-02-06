#ifndef GRAPHENE_NOTELISTMODEL_H
#define GRAPHENE_NOTELISTMODEL_H

#include <QtCore/QAbstractItemModel>
#include <src/model/note.h>

class NoteListModel : public QAbstractListModel {

public:
    NoteListModel(QObject *parent);

    QModelIndex addNote(Note *note);

    Note *getNote(int index);

    void setSelectedIndex(int &index);

    int &getSelectedIndex();

    /// From QAbstractItemModel:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

private:
    QList<Note *> internalNoteList;
    int selectedIndex = 0;
};

#endif //GRAPHENE_NOTELISTMODEL_H
