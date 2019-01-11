

#include "PairCommand.h"
#include "../../../Model/DnaAnalyzer.h"
#include <stdlib.h>
#include <sstream>


static string choose_name(const string &sequence_name, SharedPtr<DnaAnalyzer> dna_analyzer) {
    size_t count = 0;
    ostringstream oss_name;
    do {
        oss_name.str("");
        ++count;
        oss_name << sequence_name << "_p" << count;
    } while (dna_analyzer->check_if_name_exist(oss_name.str()));
    return oss_name.str();
}

string PairCommand::execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) {

    ostringstream oss;
    ostringstream oss_name;
    size_t id;


    SharedPtr<DnaSequenceData> sp(dna_analyzer->getDnaSequenceByArg(strs[1]));
    DnaSequence seq_after_pair = sp->getDnaSequence().pairing();
    if (strs.size() == 2) {
        sp->setDnaSequence(seq_after_pair);
        oss << *sp;
    } else {
        string paired_name;
        if (strs[3] == "@@") {

            paired_name = choose_name(sp->getName(), dna_analyzer);


        } else {
            paired_name= strs[3];
        }
        size_t paired_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceData> new_sp(new DnaSequenceData(seq_after_pair, paired_name, paired_id));
        dna_analyzer->pushNewSeq(paired_id, paired_name, new_sp);
        oss << *new_sp ;

    }
    return oss.str();
}