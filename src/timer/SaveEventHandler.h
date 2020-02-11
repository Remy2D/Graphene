#ifndef GRAPHENE_SAVE_EVENT_HANDLER_H
#define GRAPHENE_SAVE_EVENT_HANDLER_H

#include <chrono>

class NoteListManager;

namespace timer {

class SaveEventHandler {

public:
    explicit SaveEventHandler(NoteListManager *noteListManager);

    void rescheduleSaveEvent();

    bool isScheduled() const;

    bool shouldFireAutosave();

    void save();

    void autosave();

private:
    void doSave();

    bool scheduled = false;
    std::chrono::time_point<std::chrono::steady_clock> scheduledTime;
    std::chrono::milliseconds delaySeconds;

    NoteListManager *noteListManager;
};

}  // namespace timer

#endif  // GRAPHENE_SAVE_EVENT_HANDLER_H
