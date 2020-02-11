#include "NoteListManager.h"
#include "common/Logger.h"
#include "utils/Digest.h"

NoteListManager::NoteListManager(NoteListModel *model,
                                 GrapheneTextEdit *textEdit,
                                 QListView *noteListView,
                                 dao::NoteListRepository &noteListRepository) :
        noteListModel(model), textEdit(textEdit), noteListView(noteListView),
        noteListRepository(noteListRepository) {
}

void NoteListManager::loadNote(int newIndex) {
    noteListModel->setSelectedIndex(newIndex);

    textEdit->clear();
    textEdit->setHtml(noteListModel->getNote(newIndex).content);

    LOG_DEBUG("Loaded note " << newIndex);
}

void NoteListManager::saveCurrentNote() {
    auto &note = noteListModel->getCurrentNote();

    note.update(textEdit->toHtml(), textEdit->toPlainText());
    noteListRepository.updateNote(note);

    LOG_DEBUG("Saved note: " << note.digest.toStdString());

    noteListModel->resetModel();
}

void NoteListManager::deleteCurrentNote() {
    int currentIndex = noteListModel->getSelectedIndex();

    noteListRepository.deleteNote(noteListModel->getNote(currentIndex));
    noteListModel->deleteNote(currentIndex);
    LOG_DEBUG("Deleted note " << currentIndex);

    selectAnotherNote(currentIndex);
}

void NoteListManager::populateModel(QList<Note> notes) {
    for (auto note : notes) {
        noteListModel->addNote(note);
    }
    noteListModel->resetModel();
    loadNote(0);
}

void NoteListManager::addNote() {
    saveCurrentNote();
    Note note;
    auto newIndex = noteListModel->addNote(note);
    loadNote(newIndex);
}

void NoteListManager::selectAnotherNote(int oldIndex) {
    if (noteListModel->hasIndex(oldIndex)) {
        loadNote(oldIndex);
        LOG_DEBUG("Loaded next note ");
        return;
    } else if (noteListModel->hasIndex(oldIndex - 1)) {
        loadNote(oldIndex - 1);
        LOG_DEBUG("Loaded previous note ");
        return;
    }

    Note note;
    noteListModel->addNote(note);
    loadNote(0);
    LOG_DEBUG("Model empty, loaded new note");
}
