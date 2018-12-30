
#include "DnaAnalyzer.h"
#include "Command.h"
#include <sstream>
string NewCmd::exec(vector<string> &strs) {
    string arg1 = strs[1];
    string arg2;
    ostringstream arg2_string_stream;
    size_t id = DnaAnalyzer::getInstance()->getNextCount();
    if (strs.size() == 3) {
        arg2_string_stream<< strs[2];
    } else {
        arg2_string_stream<< "seq"<<id;
    }
    DnaSequence seq = DnaSequence(arg1);
    DnaSequenceMember m = DnaSequenceMember(seq, arg2_string_stream.str(), id);
    DnaAnalyzer::getInstance()->pushNewSeq(m);
    ostringstream oss;

    oss<<"[" << id << "] "<< arg2_string_stream.str()<<" " + arg1;

    return oss.str();
}
