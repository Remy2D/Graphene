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

bool timer::SaveEventHandler::shouldFireSave() {
    if (scheduled && scheduledTime + delaySeconds < Clock::now()) {
        LOG_DEBUG("Autosave fired");
        scheduled = false;
        return true;
    }

    return false;
}

void timer::SaveEventHandler::autosave() {
    if (shouldFireSave()) {
        noteListManager->saveCurrentNote();
    }
}
