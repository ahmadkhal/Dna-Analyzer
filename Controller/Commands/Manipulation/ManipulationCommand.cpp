#include "ManipulationCommand.h"
#include "../../../Model/DnaAnalyzer.h"




string ManipulationCommand::choose_name(const string &sequence_name, SharedPtr<DnaAnalyzer> dna_analyzer, string postfix) {
    size_t count = 0;
    ostringstream oss_name;
    do {
        oss_name.str("");
        ++count;
        oss_name << sequence_name << postfix << count;
    } while (dna_analyzer->check_if_name_exist(oss_name.str()));
    return oss_name.str();
}