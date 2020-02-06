#ifndef GRAPHENE_NOTELISTMODEL_H
#define GRAPHENE_NOTELISTMODEL_H

#include <QtCore/QAbstractItemModel>
#include <src/model/note.h>

class NoteListModel : public QAbstractItemModel {

public:
    NoteListModel() = default;

    ~NoteListModel() = default;

    void addNote(Note *note);

    Note *getNote(int &index);

    void setSelectedIndex(int &index);

    int &getSelectedIndex();

    QModelIndex index(int row, int column, const QModelIndex &parent) const override;

    QModelIndex parent(const QModelIndex &child) const override;

    int rowCount(const QModelIndex &parent) const override;

    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

private:
    QList<Note *> noteList;
    int selectedIndex;
};

#endif //GRAPHENE_NOTELISTMODEL_H
