#include "ConcatCommand.h"

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

string ConcatCommand::execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) {


    ostringstream oss;

    SharedPtr<DnaSequenceMember> sp(dna_analyzer->getDnaSequenceByArg(strs[1]));

    size_t i;
    string concat_str = dna_analyzer->getDnaSequenceByArg(strs[1])->getDnaSequence().getString();

    for (i = 2; i < strs.size() - 2; ++i) {
        concat_str += dna_analyzer->getDnaSequenceByArg(strs[i])->getDnaSequence().getString();
    }

    if (strs[i] != ":") {
        concat_str += dna_analyzer->getDnaSequenceByArg(strs[i])->getDnaSequence().getString();
        concat_str += dna_analyzer->getDnaSequenceByArg(strs[i + 1])->getDnaSequence().getString();

        sp->setDnaSequence(DnaSequence(concat_str));
        oss << "[" << sp->getID() << "] " << concat_str << ": " << sp->getName();
    } else {
        string replaced_name;
        if (strs[i + 1] == "@@") {

            replaced_name = choose_name(sp->getName(), dna_analyzer);

        } else {
            replaced_name = strs[i + 1].substr(1, strs[3].size());
        }
        size_t replaced_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceMember> new_sp(new DnaSequenceMember(DnaSequence(concat_str), replaced_name, replaced_id));
        dna_analyzer->pushNewSeq(replaced_id, replaced_name, new_sp);
        oss << *new_sp;

    }
    return oss.str();
}