#ifndef DNAPROJECT_DUPCOMMAND_H
#define DNAPROJECT_DUPCOMMAND_H


#include "CreationalCommand.h"


class DupCommand : public CreationalCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer);


};
#endif //DNAPROJECT_DUPCOMMAND_H
