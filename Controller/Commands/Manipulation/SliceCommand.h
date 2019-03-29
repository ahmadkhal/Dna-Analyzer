

#ifndef DNAPROJECT_SLICECOMMAND_H
#define DNAPROJECT_SLICECOMMAND_H

#include "ManipulationCommand.h"




class SliceCommand : public ManipulationCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer);


};
#endif //DNAPROJECT_SLICECOMMAND_H












