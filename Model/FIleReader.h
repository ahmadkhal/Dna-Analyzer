#ifndef DNAPROJECT_FILEREADER_H
#define DNAPROJECT_FILEREADER_H

#include <string>
#include "SharedPtr.h"
#include "dnaSequence.h"



using std::string;


class FileReader {
public:
    static string readFromFile(const string &path);
};

#endif //DNAPROJECT_FILEREADER_H
