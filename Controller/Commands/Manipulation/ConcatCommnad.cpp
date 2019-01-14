#include "ConcatCommand.h"
#include"../../../Model/DnaAnalyzer.h"
#include "../../../Model/DnaData/ConcatDecorator.h"

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

    SharedPtr<DnaSequenceData> sp(dna_analyzer->getDnaSequenceByArg(strs[1]));

    size_t i;
    vector<SharedPtr<AbstractDna> > concat_vector;

    for (i = 1; i < strs.size(); ++i) {
        if (strs[i] == ":") {
            break;
        }
        concat_vector.push_back(dna_analyzer->getDnaSequenceByArg(strs[i])->getDnaSequence());

    }

    SharedPtr<AbstractDna> sd = SharedPtr<AbstractDna>(new ConcatDecorator(concat_vector));
    if (strs.size() == i) {
        sp->setDnaSequence(sd);
        oss << *sp;
    } else {
        string replaced_name;
        if (strs[i+1 ] == "@@") {

            replaced_name = choose_name(sp->getName(), dna_analyzer);

        } else {
            replaced_name = strs[i + 1].substr(1, strs[3].size());
        }
        size_t replaced_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceData> new_sp(new DnaSequenceData(sd, replaced_name, replaced_id));
        dna_analyzer->pushNewSeq(replaced_id, replaced_name, new_sp);
        oss << *new_sp;

    }
    return oss.str();
}