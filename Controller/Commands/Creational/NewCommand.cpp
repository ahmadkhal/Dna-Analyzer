
#include "NewCommand.h"
#include <sstream>
#include"../../../Model/DnaStore.h"


string NewCommand::execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer) {
    string arg1 = strs[1];
    string arg2;
    ostringstream arg2_string_stream;
    size_t id = dna_analyzer->getNextCount();
    if (strs.size() == 3) {
        arg2_string_stream << strs[2];
    } else {
        arg2_string_stream << "seq" << id;
    }
    SharedPtr<AbstractDna> dna_sp(new DnaSequence(arg1));

    SharedPtr<DnaSequenceData> sp(new DnaSequenceData(dna_sp, arg2_string_stream.str(), id));

    dna_analyzer->pushNewSeq(id, arg2_string_stream.str(),sp);
    ostringstream oss;
    oss << "[" << id << "] " << arg2_string_stream.str() << " " << arg1;
    return oss.str();

}
