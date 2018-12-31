#ifndef DNAPROJECT_VIEW_H
#define DNAPROJECT_VIEW_H

#include <iostream>

using std::string;

class View {

public:
    View() {}

    virtual ~View() {}

    virtual void print(const string &str) const = 0;

    virtual string prompt() = 0;

    virtual void start() const = 0;

};


#endif //DNAPROJECT_VIEW_H
