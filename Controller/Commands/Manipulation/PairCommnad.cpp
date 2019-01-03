

#include "PairCommand.h"
#include "../../DnaAnalyzer.h"
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


    size_t id = atoi(strs[1].substr(1, strs[1].size()).c_str());

    DnaSequence pair_dna = dna_analyzer->getSequenceById(id)->getDnaSequence().pairing();
    SharedPtr<DnaSequenceMember> sp(dna_analyzer->getSequenceById(id));
    if (strs[2] != ":") {
        sp->setDnaSequence(pair_dna);
        oss << "[" << id << "] " << pair_dna << ": " << sp->getName();
    } else {
        string pair_name;
        if (strs[3] == "@@") {

            pair_name = choose_name(sp->getName(), dna_analyzer);

        } else {
            pair_name = strs[3];
        }
        size_t pair_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceMember> new_sp(new DnaSequenceMember(pair_dna, pair_name, pair_id));
        dna_analyzer->pushNewSeq(pair_id, pair_name, new_sp);
        oss << "[" << pair_id << "] " << pair_dna << ": " << pair_name;

    }
    return oss.str();

}