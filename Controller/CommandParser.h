
#ifndef DNAPROJECT_COMMANDPARSER_H
#define DNAPROJECT_COMMANDPARSER_H

#include <vector>
#include<string>

using std::vector;
using std::string;

class CommandParser {

public:
    vector<string> parse(const string &txt, char ch);


};

#endif //DNAPROJECT_COMMANDPARSER_H
