#ifndef GRAPHENE_NOTE_LIST_MODEL_H
#define GRAPHENE_NOTE_LIST_MODEL_H

#include "Note.h"
#include <QtCore/QAbstractItemModel>

class NoteListModel : public QAbstractListModel {

public:
    explicit NoteListModel(QObject *parent);

    int addNote(Note &note);

    void deleteNote(int index);

    Note &getNote(int index);

    void setSelectedIndex(int index);

    int getSelectedIndex();

    void resetModel();

    bool hasIndex(int index);

    /// From QAbstractItemModel:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

private:
    QList<Note> internalNoteList;
    int selectedIndex = 0;
};

#endif  // GRAPHENE_NOTE_LIST_MODEL_H
