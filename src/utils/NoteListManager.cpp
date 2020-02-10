#include "NoteListManager.h"
#include "common/Logger.h"
#include "utils/Digest.h"

void NoteListManager::loadNote(int newIndex) {
    int currentIndex = noteListModel->getSelectedIndex();
    LOG_DEBUG("Switching notes: " << currentIndex << " -> " << newIndex);

    noteListModel->setSelectedIndex(newIndex);

    textEdit->clear();
    textEdit->setText(noteListModel->getNote(newIndex).content);

    noteListView->repaint();
    textEdit->repaint();
    LOG_DEBUG("Loaded note " << newIndex);
}

void NoteListManager::saveNote(int oldIndex) {
    auto &oldNote = noteListModel->getNote(oldIndex);

    oldNote.update(textEdit->toHtml(), textEdit->toPlainText());
    noteListModel->resetModel();

    LOG_DEBUG("Saved note " << oldIndex);
}

void NoteListManager::saveCurrentNote() {
    saveNote(noteListModel->getSelectedIndex());
}

NoteListManager::NoteListManager(NoteListModel *model,
                                 GrapheneTextEdit *textEdit,
                                 QListView *noteListView) :
        noteListModel(model), textEdit(textEdit), noteListView(noteListView) {
}

void NoteListManager::deleteCurrentNote() {
    int currentIndex = noteListModel->getSelectedIndex();

    noteListModel->deleteNote(currentIndex);
    LOG_DEBUG("Deleted note " << currentIndex);

    if (noteListModel->hasIndex(currentIndex)) {
        loadNote(currentIndex);
        LOG_DEBUG("Loaded next note ");
        return;
    } else if (noteListModel->hasIndex(currentIndex - 1)) {
        loadNote(currentIndex - 1);
        LOG_DEBUG("Loaded previous note ");
        return;
    }

    Note note;
    noteListModel->addNote(note);
    loadNote(0);

    LOG_DEBUG("Model empty, loaded new note");
}
