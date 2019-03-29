#include "SliceCommand.h"
#include"../../../Model/DnaStore.h"
#include"../../../Model/DnaData/SliceDecorator.h"




string SliceCommand::execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer) {

    ostringstream oss;
    ostringstream oss_name;
    size_t from = atoi(strs[2].c_str());
    size_t to = atoi(strs[3].c_str());
    size_t id;
    SharedPtr<DnaSequenceData> sp(dna_analyzer->getDnaSequenceByArg(strs[1]));

    SharedPtr<AbstractDna> sd = SharedPtr<AbstractDna>(new SliceDecorator(sp->getDnaSequence(), from, to));
    if (strs.size() == 4) {
        sp->setDnaSequence(sd);


        oss << "[" << sp->getID() << "] " << sp->getName() << ": " <<sp->getString();

    } else {
        string sliced_name;
        if (strs[5] == "@@") {

            sliced_name =ManipulationCommand::choose_name(sp->getName(), dna_analyzer,"_s");

        } else {
            sliced_name = strs[3];
        }
        size_t sliced_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceData> new_sp(new DnaSequenceData(sd, sliced_name, sliced_id));
        dna_analyzer->pushNewSeq(sliced_id, sliced_name, new_sp);
        oss << *new_sp;

    }

    return oss.str();
}