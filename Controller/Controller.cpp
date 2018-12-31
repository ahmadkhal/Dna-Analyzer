#include "Controller.h"
#include "DnaAnalyzer.h"
#include "CommandParser.h"
#include "../View/CLI.h"
#include "../Model/UniquePtr.h"
#include <iostream>
#include <vector>

using namespace std;




DnaAnalyzer *DnaAnalyzer::m_ref = 0;

int main(int argc, char *argv[]) {
    Controller ctrl;
    CommandParser commandParser;
    UniquePtr<View> view( new CLI());

    string CommandOutputString;

    string cmdline;
    string result;
    vector<string> arg_vector;
    while (1) {
        view->start();
        getline(cin, cmdline);
        arg_vector=commandParser.parse(cmdline, ' ');
        if(arg_vector[0]=="exit"){
            break;
        }
      result=DnaAnalyzer::getInstance()->getCmd(arg_vector[0])->execute(arg_vector);
        view->print(result);
        arg_vector.clear();
    }
    cout<<"------ Good Bye ------"<<endl;
    return 0;
}