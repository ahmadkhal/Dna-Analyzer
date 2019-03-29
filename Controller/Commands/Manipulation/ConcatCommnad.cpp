#include "ConcatCommand.h"
#include"../../../Model/DnaStore.h"
#include "../../../Model/DnaData/ConcatDecorator.h"


string ConcatCommand::execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer) {


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
        string concat_name;
        if (strs[i+1 ] == "@@") {

            concat_name = ManipulationCommand::choose_name(sp->getName(), dna_analyzer,"_c");

        } else {
            concat_name = strs[i + 1].substr(1, strs[3].size());
        }
        size_t concat_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceData> new_sp(new DnaSequenceData(sd, concat_name, concat_id));
        dna_analyzer->pushNewSeq(concat_id, concat_name, new_sp);
        oss << *new_sp;

    }
    return oss.str();
}