#include "NoteListManager.h"
#include "common/Logger.h"

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

    // todo: move digest:
    auto oldNoteDigest = textEdit->toPlainText();
    oldNoteDigest = oldNoteDigest.simplified();
    oldNoteDigest.truncate(20);

    oldNote.content = textEdit->toHtml();
    oldNote.digest = oldNoteDigest;

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

    Note note("");
    noteListModel->addNote(note);
    loadNote(0);

    LOG_DEBUG("Model empty, loaded new note");
}
