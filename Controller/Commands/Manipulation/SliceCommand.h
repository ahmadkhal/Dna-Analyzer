
#include "ManipulationCommand.h"

#ifndef __DNAPROJECT_SLICECOMMAND_H
#define DNAPROJECT_SLICECOMMAND_H





class SliceCommand : public ManipulationCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer);

private:
};
#endif //DNAPROJECT_SLICECOMMAND_H












