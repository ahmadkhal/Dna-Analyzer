#ifndef DNAPROJECT_RENAMECOMMAND_H
#define DNAPROJECT_RENAMECOMMAND_H


#include "ManagementCommand.h"


class RenameCommand : public ManagementCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer);

private:
};
#endif //DNAPROJECT_RENAMECOMMAND_H
