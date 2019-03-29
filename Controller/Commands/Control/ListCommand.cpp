
#include "ListCommand.h"
#include "../../../Model/DnaStore.h"


string ListCommand::execute(vector<string> &strs, SharedPtr<DnaStore> dna_analyzer) {
    ostringstream oss;
    vector<DnaSequenceData> members_vec = dna_analyzer->get_all_the_sequences();

    for (vector<DnaSequenceData>::iterator it = members_vec.begin(); it != members_vec.end(); ++it) {
        oss << *it;
        if (it != members_vec.end() - 1) {
            oss << endl;
        }
    }
    return oss.str();
}
