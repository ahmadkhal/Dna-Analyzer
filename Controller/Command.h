//
// Created by ahmad on 12/29/18.
//

#ifndef DNAPROJECT_COMMAND_H
#define DNAPROJECT_COMMAND_H

#include <string>
#include <vector>
#include "../Model/dnaSequence.h"
#include "dnaSequenceMember.h"
#include "../View/View.h"

using namespace std;

class Command {
public:
    virtual string exec(vector<string> &strs) = 0;

    virtual ~Command() {};


};

class NewCmd : public Command {
public:
    string exec(vector<string> &strs);

private:
};

#endif //DNAPROJECT_COMMAND_H
