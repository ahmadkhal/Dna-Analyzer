#ifndef DNAPROJECT_LOADCOMMAND_H
#define DNAPROJECT_LOADCOMMAND_H


#include "CreationalCommand.h"

class LoadCommand : public CreationalCommand {
public:
    string execute(vector<string> &strs);

private:
};


#endif //DNAPROJECT_LOADCOMMAND_H
