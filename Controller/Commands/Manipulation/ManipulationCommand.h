
#ifndef DNAPROJECT_MANIPULATIONCOMMAND_H
#define DNAPROJECT_MANIPULATIONCOMMAND_H


#include <sstream>
#include "../Command.h"

class ManipulationCommand : public Command {
public:
    string choose_name(const string &sequence_name, SharedPtr<DnaStore> dna_analyzer, string postfix);


};




#endif //DNAPROJECT_MANIPULATIONCOMMAND_H



