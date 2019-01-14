#include "DupCommand.h"
#include"../../../Model/DnaAnalyzer.h"
string DupCommand::execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) {
    string arg1 = dna_analyzer->getDnaSequenceByArg(strs[1])->getString();
    string arg2;
    ostringstream arg2_string_stream;

    size_t id = dna_analyzer->getNextCount();
    if (strs.size() == 3) {
        arg2_string_stream << strs[2];
    } else {
        arg2_string_stream << "seq" << id;
    }

    SharedPtr<DnaSequenceData> sp(new DnaSequenceData(SharedPtr<DnaSequence>(new DnaSequence(arg1)), arg2_string_stream.str(), id));
    dna_analyzer->pushNewSeq(id, arg2_string_stream.str(), sp);
    ostringstream oss;
    oss << "[" << id << "] " << arg2_string_stream.str() << " " << arg1;
    return oss.str();
}

