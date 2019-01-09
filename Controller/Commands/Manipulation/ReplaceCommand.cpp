
#include"ReplaceCommand.h"


static string choose_name(const string &sequence_name, SharedPtr<DnaAnalyzer> dna_analyzer) {
    size_t count = 0;
    ostringstream oss_name;
    do {
        oss_name.str("");
        ++count;
        oss_name << sequence_name << "_s" << count;
    } while (dna_analyzer->check_if_name_exist(oss_name.str()));
    return oss_name.str();
}

string ReplaceCommand::execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) {
    ostringstream oss;

    SharedPtr<DnaSequenceMember> sp(dna_analyzer->getDnaSequenceByArg(strs[1]));
    string dna_sequence_str = sp->getDnaSequence().getString();
    size_t i;

    for (i = 2; i < strs.size() - 2; i += 2) {
        dna_sequence_str[atoi(strs[i].c_str())] = (strs[i + 1])[0];
    }
    DnaSequence replaced_seq=DnaSequence(dna_sequence_str);
    if (strs[i ] != ":") {
        dna_sequence_str[atoi(strs[i].c_str())] = (strs[i +1])[0];

        sp->setDnaSequence(replaced_seq);
        oss << "[" << sp->getID() << "] " << dna_sequence_str << ": " << sp->getName();
    } else {
        string replaced_name;
        if (strs[i+1] == "@@") {

            replaced_name= choose_name(sp->getName(), dna_analyzer);

        } else {
            replaced_name = strs[i+1].substr(1,strs[3].size());
        }
        size_t replaced_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceMember> new_sp(new DnaSequenceMember(replaced_seq, replaced_name, replaced_id));
        dna_analyzer->pushNewSeq(replaced_id, replaced_name, new_sp);
        oss << *new_sp ;

    }
    return oss.str();
}