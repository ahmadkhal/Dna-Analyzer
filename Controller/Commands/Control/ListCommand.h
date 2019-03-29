#ifndef DNAPROJECT_SHOWCOMMAND_H
#define DNAPROJECT_SHOWCOMMAND_H


#include "ControlCommand.h"

class ListCommand : public ControlCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer);

private:
};

#endif //DNAPROJECT_SHOWCOMMAND_H
