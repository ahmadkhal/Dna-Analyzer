//
// Created by ahmad on 12/30/18.
//

#ifndef DNAPROJECT_SAVECOMMAND_H
#define DNAPROJECT_SAVECOMMAND_H
#include "ManagementCommand.h"
#include "../../DnaAnalyzer.h"

class SaveCommand : public ManagementCommand {
public:
    string execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer);

private:
};
#endif //DNAPROJECT_SAVECOMMAND_H
