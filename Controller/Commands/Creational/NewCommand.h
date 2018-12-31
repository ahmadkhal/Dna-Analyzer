//
// Created by ahmad on 12/30/18.
//

#ifndef DNAPROJECT_NEWCOMMAND_H
#define DNAPROJECT_NEWCOMMAND_H

#include "CreationalCommand.h"

class NewCommand : public CreationalCommand {
public:
    string execute(vector<string> &strs);

private:
};
#endif //DNAPROJECT_NEWCOMMAND_H
