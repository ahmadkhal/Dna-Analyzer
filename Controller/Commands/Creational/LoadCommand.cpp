

#include <cstdlib>
#include <sstream>
#include "LoadCommand.h"

#include "../../../Model/SharedPtr.h"
#include "../../../Model/DnaStore.h"
#include "../../../Model/FileWriter.h"
#include "../../../Model/FIleReader.h"


string LoadCommand::execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer) {
    ostringstream oss;
    string arg2;
    if (strs.size() == 3) {
        arg2 = strs[2];
    } else {
        size_t found = strs[1].find(".");
        arg2 = strs[1].substr(0, found);
    }
    string sequence_string = FileReader::readFromFile(strs[1]);
    size_t id = dna_analyzer->getNextCount();
    SharedPtr<DnaSequenceData> sp(new DnaSequenceData(SharedPtr<DnaSequence>(new DnaSequence(sequence_string)), arg2, id));
    dna_analyzer->pushNewSeq(id, arg2, sp);
    size_t sequence_size = sequence_string.size();
    if (sequence_string.size() > 40) {
        sequence_string =sp->formatted_string();
                sequence_string.substr(0, 32) + "..." + sequence_string.substr(sequence_size - 3, sequence_size);
    }
    oss << "[" << id << "] " << arg2 << ": " << sequence_string;

    return oss.str();


}