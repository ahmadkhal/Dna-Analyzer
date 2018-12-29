//
// Created by ahmad on 12/29/18.
//

#include <iostream>
using namespace std;

#ifndef DNAPROJECT_VIEW_H
#define DNAPROJECT_VIEW_H

class View {
private:
    static View *v;
    View() {}

public:
    void startNewCommand() const {
        cout << "cmd >>";
    }

    void print(string str) const {
        cout << str << endl;
    }
    static View* getView() {
        if (!v) {
            v = new View();
        }
        return v;
    }
};


#endif //DNAPROJECT_VIEW_H
