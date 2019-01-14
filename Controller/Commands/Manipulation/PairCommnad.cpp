

#include "PairCommand.h"
#include "../../../Model/DnaAnalyzer.h"
#include "../../../Model/DnaData/PairDecorator.h"
#include <stdlib.h>
#include <sstream>




string PairCommand::execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) {

    ostringstream oss;
    ostringstream oss_name;
    size_t id;


    SharedPtr<DnaSequenceData> sp(dna_analyzer->getDnaSequenceByArg(strs[1]));

    SharedPtr<AbstractDna> sd = SharedPtr<AbstractDna>(new PairDecorator(sp->getDnaSequence()));


    if (strs.size() == 2) {
        sp->setDnaSequence(sd);
        oss << *sp;
    } else {
        string paired_name;
        if (strs[3] == "@@") {

            paired_name = ManipulationCommand::choose_name(sp->getName(), dna_analyzer,"_p");


        } else {
            paired_name = strs[3];
        }
        size_t paired_id = dna_analyzer->getNextCount();
        SharedPtr<DnaSequenceData> new_sp(new DnaSequenceData(sd, paired_name, paired_id));
        dna_analyzer->pushNewSeq(paired_id, paired_name, new_sp);
        oss << *new_sp;

    }
    return oss.str();
}