#include "NoteListModel.h"

NoteListModel::NoteListModel(QObject *parent) : QAbstractListModel(parent) {
}

QModelIndex NoteListModel::addNote(Note &note) {
    int count = rowCount();
    beginInsertRows(QModelIndex(), count, count);
    internalNoteList << note;
    endInsertRows();

    return createIndex(count, 0);
}

void NoteListModel::deleteNote(int index) {
    beginRemoveRows(QModelIndex(), index, index);
    internalNoteList.removeAt(index);
    selectedIndex = 0;
    endRemoveRows();
}

Note &NoteListModel::getNote(int index) {
    return internalNoteList[index];
}

int NoteListModel::getSelectedIndex() {
    return selectedIndex;
}

void NoteListModel::setSelectedIndex(int index) {
    selectedIndex = index;
}

/// From QAbstractItemModel:
int NoteListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)

    return internalNoteList.length();
}

QVariant NoteListModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= internalNoteList.count()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        return internalNoteList.at(index.row()).digest;
    }

    return QVariant();
}
