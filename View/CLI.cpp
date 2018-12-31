#include "CLI.h"


CLI::CLI() {

}

CLI::~CLI() {

}

void CLI::print(const string &s) const {
    std::cout << s << std::endl;
}

void CLI::start()const{
    std::cout << "cmd>>";
}

string CLI::prompt() {
    string cmdLine;
    std::getline(std::cin, cmdLine);
    return cmdLine;
}