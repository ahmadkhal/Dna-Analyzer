#ifndef DNAPROJECT_FILEWRITER_H
#define DNAPROJECT_FILEWRITER_H

#include <string>
#include "DnaData/dnaSequence.h"
#include <fstream>
using std::ofstream;
using std::string;


class FileWriter {
public:
    static void writeToFile(const string &path, const string& str_to_write);
};


#endif //DNAPROJECT_FILEWRITER_H
