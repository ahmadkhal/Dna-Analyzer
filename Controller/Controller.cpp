#include "Controller.h"
#include "DnaAnalyzer.h"
#include "CommandParser.h"
#include "../View/CLI.h"
#include <iostream>
#include <vector>

using namespace std;




DnaAnalyzer *DnaAnalyzer::m_ref = 0;

int main(int argc, char *argv[]) {
    Controller ctrl;
    CommandParser commandParser;
    CLI commandLine;
    string CommandOutputString;

    string cmdline;
    vector<string> arg_vector;
    while (1) {
        commandLine.startNewCommand();
        getline(cin, cmdline);
        arg_vector=commandParser.parse(cmdline, ' ');
        if(arg_vector[0]=="exit"){
            break;
        }
        CommandOutputString=DnaAnalyzer::getInstance()->getCmd(arg_vector[0])->exec(arg_vector);
        commandLine.print(CommandOutputString);
        arg_vector.clear();
    }
    cout<<"------ Good Bye ------"<<endl;
    return 0;
}