//
// Created by ahmad on 12/29/18.
//

#ifndef DNAPROJECT_COMMAND_H
#define DNAPROJECT_COMMAND_H

#include <string>
#include <vector>
#include "../../Model/SharedPtr.h"

class DnaAnalyzer;

using namespace std;

class Command {
public:


    virtual string execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) = 0;

    virtual ~Command() {};


};


#endif //DNAPROJECT_COMMAND_H




