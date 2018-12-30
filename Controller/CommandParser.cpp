#include "CommandParser.h"


vector<string> CommandParser::parse(const string &txt, char ch) {
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    vector<string> argv;
    // Decompose statement
    while (pos < txt.size()) {
        argv.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    argv.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

    if (*(argv.end()-1) == "") {
        argv.pop_back();

    }
    return argv;
}
