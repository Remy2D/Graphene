#include "notelistmodel.h"

void NoteListModel::addNote(Note *note) {
    noteList << note;
}

Note *NoteListModel::getNote(int &index) {
    if (index >= 0) {
        return noteList.at(index);
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
QModelIndex NoteListModel::index(int row, int column, const QModelIndex &parent) const {
    return QModelIndex();
}

QModelIndex NoteListModel::parent(const QModelIndex &child) const {
    return QModelIndex();
}

int NoteListModel::rowCount(const QModelIndex &parent) const {
    return noteList.length();
}

int NoteListModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant NoteListModel::data(const QModelIndex &index, int role) const {
    return QVariant();
}
