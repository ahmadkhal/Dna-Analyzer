//
//#include "RenameCommand.h"
//
//string RenameCommand::execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer) {
//    size_t id = atoi(strs[1].substr(1,strs.size()).c_str());
//
//    SharedPtr<A> sp(dna_analyzer->getSequenceById(id));
//    ostringstream oss;
//
//    string arg2;
//
//    if (strs.size() == 3) {
//        arg2 = strs[2];
//    } else {
//        arg2 = sp->getName() + ".rawdna";
//    }
//    oss << sp->getDnaSequence();
//    FileWriter::writeToFile(arg2, oss.str());
//    return oss.str();
//}
//
//
//
//
//
//
//}
