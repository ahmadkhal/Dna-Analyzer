#ifndef DNAPROJECT_CONCATCOMMAND_H
#define DNAPROJECT_CONCATCOMMAND_H

#include "ManipulationCommand.h"

class ConcatCommand : public ManipulationCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer);


};

#endif //DNAPROJECT_CONCATCOMMAND_H
