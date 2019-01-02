#ifndef DNAPROJECT_SHOWCOMMAND_H
#define DNAPROJECT_SHOWCOMMAND_H


#include "ControlCommand.h"

class ListCommand : public ControlCommand {
public:
    string execute(vector<string> &strs);

private:
};

#endif //DNAPROJECT_SHOWCOMMAND_H
