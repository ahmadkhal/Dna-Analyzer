

#include "PairCommand.h"
#include "../../DnaAnalyzer.h"
#include <stdlib.h>
#include <sstream>


static string choose_name(const string &sequence_name) {
    size_t count = 0;
    ostringstream oss_name;
    do {
        oss_name.str("");
        ++count;
        oss_name << sequence_name << "_p" << count;
    } while (DnaAnalyzer::getInstance()->check_if_name_exist(oss_name.str()));
    return oss_name.str();
}

string PairCommand::execute(vector<string> &strs) {

    ostringstream oss;
    ostringstream oss_name;


    size_t id = atoi(strs[1].substr(1, strs[1].size()).c_str());
    cout << id<<"what the hell!"<<endl;
    DnaSequence pair_dna = DnaAnalyzer::getInstance()->getSequenceById(id)->getDnaSequence().pairing();
    SharedPtr<DnaSequenceMember> sp(DnaAnalyzer::getInstance()->getSequenceById(id));
    if (strs[2] != ":") {
        sp->setDnaSequence(pair_dna);
        oss << "[" << id << "] " << pair_dna << ": " << sp->getName();
    } else {
        string pair_name;
        if (strs[3] == "@@") {

             pair_name = choose_name(sp->getName());

        } else {
            pair_name = strs[3];
        }
        size_t pair_id = DnaAnalyzer::getInstance()->getNextCount();
        SharedPtr<DnaSequenceMember> new_sp(new DnaSequenceMember(pair_dna, pair_name, pair_id));
        DnaAnalyzer::getInstance()->pushNewSeq(pair_id, pair_name, new_sp);
        oss << "[" << pair_id << "] " << pair_dna << ": " << pair_name;

    }


}