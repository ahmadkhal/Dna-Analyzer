
#ifndef DNAPROJECT_MANIPULATIONCOMMAND_H
#define DNAPROJECT_MANIPULATIONCOMMAND_H


#include "../Command.h"

class ManipulationCommand : public Command {
public:
    string execute(vector<string> &strs) = 0;

private:
};


#endif //DNAPROJECT_MANIPULATIONCOMMAND_H
