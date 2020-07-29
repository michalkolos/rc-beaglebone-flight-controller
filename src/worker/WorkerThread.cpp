//
// Created by kolos on 7/27/20.
//

#include "WorkerThread.h"

void WorkerThread::workerFunction() {
    while(threadRunning){ task(); }
}

bool WorkerThread::startThread() {
    if(threadRunning) { return false; }

    workerThread = std::thread(&WorkerThread::workerFunction, this);
    threadRunning = true;

    return true;
}

bool WorkerThread::stopThread() {

    threadRunning = false;

    return true;
}

WorkerThread::WorkerThread(bool startWorker) {
    if(startWorker) { startThread(); }
}

WorkerThread::~WorkerThread() {
    stopThread();
    workerThread.join();
}

