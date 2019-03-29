
#include"ReplaceCommand.h"
#include"../../../Model/DnaStore.h"
#include "../../../Model/DnaData/ReplaceDecorator.h"



string ReplaceCommand::execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer) {
    ostringstream oss;

    SharedPtr<DnaSequenceData> sp(dna_analyzer->getDnaSequenceByArg(strs[1]));
    std::map<size_t, string> replacement_map;
    size_t i;

    for (i = 2; i < strs.size(); i += 2) {
        replacement_map[atoi(strs[i].c_str())] = (strs[i + 1])[0];


        if (strs[i] == ":") {
            break;
        }
    }

    SharedPtr<AbstractDna> sd = SharedPtr<AbstractDna>(new ReplaceDecorator(sp->getDnaSequence(), replacement_map));

    if (strs.size() == i) {

        sp->setDnaSequence(sd);
        oss << "[" << sp->getID() << "] " << sp->getString() << ": " << sp->getName();
    } else {
        string replaced_name;
        if (strs[i + 1] == "@@") {

            replaced_name = ManipulationCommand::choose_name(sp->getName(), dna_analyzer,"_r");

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