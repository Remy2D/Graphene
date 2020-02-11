#include "SaveEventHandler.h"
#include "common/Logger.h"
#include "common/Configuration.h"
#include "src/utils/NoteListManager.h"

using Clock = std::chrono::steady_clock;

timer::SaveEventHandler::SaveEventHandler(NoteListManager* noteListManager) :
    noteListManager(noteListManager),
    delaySeconds(std::chrono::milliseconds(
            getConfiguration().getInt(config::PropertyKey::AUTOSAVE_DELAY_MILLISECONDS))) {
}

void timer::SaveEventHandler::rescheduleSaveEvent() {
    scheduled = true;
    scheduledTime = Clock::now();
}

bool timer::SaveEventHandler::shouldFireAutosave() {
    return (scheduledTime + delaySeconds < Clock::now());
}

void timer::SaveEventHandler::doSave() {
    noteListManager->saveCurrentNote();
    scheduled = false;
}

void timer::SaveEventHandler::save() {
    if (isScheduled()) {
        LOG_DEBUG("Saving on demand");
        doSave();
    }
}

void timer::SaveEventHandler::autosave() {
    if (isScheduled() && shouldFireAutosave()) {
        LOG_DEBUG("Autosave fired");
        doSave();
    }
}

bool timer::SaveEventHandler::isScheduled() const {
    return scheduled;
}
