
#include "ListCommand.h"
#include "../../DnaAnalyzer.h"


string ListCommand::execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) {
    ostringstream oss;
    vector<DnaSequenceMember> members_vec = dna_analyzer->get_all_the_sequences();

    for (vector<DnaSequenceMember>::iterator it = members_vec.begin(); it != members_vec.end(); ++it) {
        oss << *it;
        if (it != members_vec.end() - 1) {
            oss << endl;
        }
    }
    return oss.str();
}
