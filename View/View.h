#ifndef DNAPROJECT_VIEW_H
#define DNAPROJECT_VIEW_H

#include <iostream>

using namespace std;

class View {
private:
    static View *v;

    View() {}

public:
    void startNewCommand() const {
        cout << "cmd >>";
    }

    void print(const string& str) const {
        cout << str << endl;
    }

    static View *getView() {
        if (!v) {
            v = new View();
        }
        return v;
    }
};


#endif //DNAPROJECT_VIEW_H
