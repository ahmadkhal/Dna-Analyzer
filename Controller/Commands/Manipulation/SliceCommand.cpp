#include "SliceCommand.h"
#include"../../../Model/DnaAnalyzer.h"

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


string SliceCommand::execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) {

    ostringstream oss;
    ostringstream oss_name;
    size_t from = atoi(strs[2].c_str());
    size_t to = atoi(strs[3].c_str());
    size_t id;


    SharedPtr<DnaSequenceData> sp(dna_analyzer->getDnaSequenceByArg(strs[1]));
    DnaSequence sliced_dna = sp->getDnaSequence().slicing(from, to);
    if (strs.size() == 4) {
        sp->setDnaSequence(sliced_dna);
        oss << "[" << sp->getID() << "] " << sliced_dna << ": " << sp->getName();
    } else {
        string sliced_name;
        if (strs[5] == "@@") {

            sliced_name = choose_name(sp->getName(), dna_analyzer);

        } else {
            sliced_name = strs[3];
        }
        size_t sliced_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceData> new_sp(new DnaSequenceData(sliced_dna, sliced_name, sliced_id));
        dna_analyzer->pushNewSeq(sliced_id, sliced_name, new_sp);
        oss << *new_sp ;

    }
    return oss.str();
}