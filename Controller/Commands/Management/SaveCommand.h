#ifndef DNAPROJECT_SAVECOMMAND_H
#define DNAPROJECT_SAVECOMMAND_H

#include "ManagementCommand.h"


class SaveCommand : public ManagementCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer);

private:
};

#endif //DNAPROJECT_SAVECOMMAND_H
