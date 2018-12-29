#include "Controller.h"
#include "DnaAnalyzer.h"
#include <iostream>
#include <vector>
using namespace std;

size_t split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while(pos < txt.size()) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}
View* View::v = 0;
DnaAnalyzer* DnaAnalyzer::m_ref = 0;

int main(int argc, char *argv[]) {
    Controller ctrl;
//    char line[1024];
//    char *str[100];
//    int len;
    //ctrl.GetView().Init();
    string cmdline;
    vector<string> strs;
    while (1) {
        View::getView()->startNewCommand();
        getline(cin, cmdline);
        split(cmdline, strs, ' ');
        DnaAnalyzer::getInstance()->getCmd(strs[0])->exec(strs);

//        for (int i = 0; i < strs.size(); ++i) {
//            cout << strs[i] << " ";
//        }
//        cout << endl;
        //command = hashmap(cmd)
        //res = command.exec
        //ctrl.GetView().Show();
    }
    return 0;
}