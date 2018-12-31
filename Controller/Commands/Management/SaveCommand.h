//
// Created by ahmad on 12/30/18.
//

#ifndef DNAPROJECT_SAVECOMMAND_H
#define DNAPROJECT_SAVECOMMAND_H
#include "ManagementCommand.h"

class SaveCommand : public ManagementCommand {
public:
    string execute(vector<string> &strs);

private:
};
#endif //DNAPROJECT_SAVECOMMAND_H
