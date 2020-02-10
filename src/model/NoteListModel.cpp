#include "NoteListModel.h"

NoteListModel::NoteListModel(QObject *parent) : QAbstractListModel(parent) {
}

int NoteListModel::addNote(Note &note) {
    int count = rowCount();
    beginInsertRows(QModelIndex(), internalNoteList.length(), internalNoteList.length());
    internalNoteList.append(note);
    endInsertRows();

    return count;
}

void NoteListModel::deleteNote(int index) {
    beginRemoveRows(QModelIndex(), internalNoteList.length(), internalNoteList.length());
    internalNoteList.removeAt(index);
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

void NoteListModel::resetModel() {
    // todo: this emits a signal to QListView, find a better way to do this
    beginInsertRows(QModelIndex(), internalNoteList.length(), internalNoteList.length());
    endInsertRows();
}

bool NoteListModel::hasIndex(int index) {
    return index >= 0 && index < rowCount();
}
