//
// Created by ahmad on 12/30/18.
//

#include "FileWriter.h"

void FileWriter::writeToFile(const string &path, const string &str_to_write) {
    ofstream out_file(path.c_str());
    if (!out_file.is_open()) {
        throw invalid_argument("Unable to open file");
    }
    out_file << str_to_write << endl;
    out_file.close();

}
