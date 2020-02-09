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
    auto& oldNote = noteListModel->getNote(oldIndex);

    // todo: move digest:
    auto oldNoteDigest = textEdit->toPlainText();
    oldNoteDigest = oldNoteDigest.simplified();
    oldNoteDigest.truncate(20);

    oldNote.content = textEdit->toHtml();
    oldNote.digest = oldNoteDigest;

    noteListView->repaint();
    textEdit->repaint();

    LOG_DEBUG("Saved note " << oldIndex);
}

void NoteListManager::saveCurrentNote() {
    saveNote(noteListModel->getSelectedIndex());
}

NoteListManager::NoteListManager(NoteListModel* model, GrapheneTextEdit* textEdit, QListView* noteListView):
noteListModel(model), textEdit(textEdit), noteListView(noteListView) {
}
