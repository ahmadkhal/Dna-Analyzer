#ifndef DNAPROJECT_PAIRCOMMAND_H
#define DNAPROJECT_PAIRCOMMAND_H


#include "ManipulationCommand.h"


class PairCommand : public ManipulationCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer);

};

#endif //DNAPROJECT_PAIRCOMMAND_H
