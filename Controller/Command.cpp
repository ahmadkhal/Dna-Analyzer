//
// Created by ahmad on 12/29/18.
//
#include "DnaAnalyzer.h"
#include "Command.h"
void NewCmd::exec(vector<string> &strs) {
    string arg1 = strs[1];
    string arg2;
    size_t id = DnaAnalyzer::getInstance()->getNextCount();
    if (strs.size() == 3) {
        arg2 = strs[2];
    } else {
        arg2 = "seq" + id;
    }
    DnaSequence seq = DnaSequence(arg1);
    DnaSequenceMember m = DnaSequenceMember( seq,arg2,id);
    DnaAnalyzer::getInstance()->pushNewSeq(m);
    string str = "";
    View::getView()->print(str + "[id]" + " " + arg2 + arg1);
}
