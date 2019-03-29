#ifndef DNAPROJECT_NEWCOMMAND_H
#define DNAPROJECT_NEWCOMMAND_H

#include "CreationalCommand.h"

class NewCommand : public CreationalCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer);

private:
};

#endif //DNAPROJECT_NEWCOMMAND_H
