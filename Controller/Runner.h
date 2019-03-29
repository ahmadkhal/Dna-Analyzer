
#ifndef DNAPROJECT_RUNNER_H
#define DNAPROJECT_RUNNER_H


#include "../Model/SharedPtr.h"
#include "Controller.h"

class Runner{
public:
    explicit Runner();
    void run();

private:
    SharedPtr<Controller> controller;
};
#endif //DNAPROJECT_RUNNER_H
