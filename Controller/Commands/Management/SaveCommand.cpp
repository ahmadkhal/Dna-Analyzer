#include "../../../Model/DnaAnalyzer.h"
#include "SaveCommand.h"
#include "../../../Model/FileWriter.h"
#include <sstream>

string SaveCommand::execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) {
    size_t id = atoi(strs[1].substr(1,strs.size()).c_str());

    SharedPtr<DnaSequenceData> sp(dna_analyzer->getSequenceById(id));
    ostringstream oss;

    string arg2;

    if (strs.size() == 3) {
        arg2 = strs[2];
    } else {
        arg2 = sp->getName() + ".rawdna";
    }
    oss << sp->getDnaSequence();
    FileWriter::writeToFile(arg2, oss.str());
    return oss.str();
}
