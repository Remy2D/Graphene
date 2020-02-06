//
// Created by remy on 22.05.19.
//

#ifndef GRAPHENE_TIMERSERVICE_H
#define GRAPHENE_TIMERSERVICE_H


#include <QtCore/QTimer>

class TimerService {

public:
    TimerService();
    void assureDefaultNoteSaveTimerLaunched();

private:
    int DEFAULT_SAVE_TIMEOUT_MS = 500;
    QTimer* timer = new QTimer();
};


#endif //GRAPHENE_TIMERSERVICE_H
