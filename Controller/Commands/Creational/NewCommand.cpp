#include "../../DnaAnalyzer.h"
#include "NewCommand.h"
#include <sstream>

string NewCommand::execute(vector<string> &strs) {
    string arg1 = strs[1];
    string arg2;
    ostringstream arg2_string_stream;
    size_t id = DnaAnalyzer::getInstance()->getNextCount();
    if (strs.size() == 3) {
        arg2_string_stream << strs[2];
    } else {
        arg2_string_stream << "seq" << id;
    }

    SharedPtr<DnaSequenceMember> sp(new DnaSequenceMember(DnaSequence(arg1), arg2_string_stream.str(), id));
    DnaAnalyzer::getInstance()->pushNewSeq(id, arg2_string_stream.str(),sp);
    ostringstream oss;
    oss << "[" << id << "] " << arg2_string_stream.str() << " " << arg1;
    return oss.str();

}
