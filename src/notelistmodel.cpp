#include "notelistmodel.h"
#include <iostream>

NoteListModel::NoteListModel(QObject *parent) : QAbstractListModel(parent) {
    NoteListModel::internalNoteList = {};
}

QModelIndex NoteListModel::addNote(Note *note) {
    int count = rowCount();
    beginInsertRows(QModelIndex(), count, count);
    internalNoteList << note;
    endInsertRows();

    return createIndex(count, 0);
}

Note *NoteListModel::getNote(int index) {
    if (index >= 0) {
        return internalNoteList.at(index);
    } else {
        return Q_NULLPTR;
    }
}

int &NoteListModel::getSelectedIndex() {
    return selectedIndex;
}

void NoteListModel::setSelectedIndex(int &index) {
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
        return internalNoteList.at(index.row())->getContent();
    }

    return QVariant();
}
