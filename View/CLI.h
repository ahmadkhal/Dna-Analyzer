#ifndef DNAPROJECT_CLI_H
#define DNAPROJECT_CLI_H


#include "View.h"

class CLI : public View {
public:
    CLI();

    ~CLI();

    void print(const string &s) const;

    void start()const;

    string prompt();
};


#endif //DNAPROJECT_CLI_H
