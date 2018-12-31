#include "FIleReader.h"
#include <exception>
#include <fstream>
using std::ifstream;
using std::string;

string FileReader::readFromFile(const string &path) {
    string str;
    ifstream infile(path.c_str());

    if (!infile.is_open()) {
        throw invalid_argument("Unable to open file");
    }

    getline(infile, str);
    infile.close();
    if (str == "") {

        throw invalid_argument("File is empty");
    }

    return str;


}







