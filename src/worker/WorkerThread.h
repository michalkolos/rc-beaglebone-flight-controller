//
// Created by kolos on 7/27/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_WORKERTHREAD_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_WORKERTHREAD_H


#include <thread>

class WorkerThread {
private:
    std::thread workerThread;
    bool threadRunning = false;
    void workerFunction();

protected:
    virtual void task() = 0;
    virtual void cleanup();
    bool startThread();
    bool stopThread();

public:
    WorkerThread(bool startWorker);

    virtual ~WorkerThread();

};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_WORKERTHREAD_H
