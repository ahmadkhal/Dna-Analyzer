#include "DnaStore.h"


DnaStore::DnaStore() : m_seq_count(1) {}


    vector<DnaSequenceData> DnaStore::get_all_the_sequences() {
        vector<DnaSequenceData> all_the_sequences_vec;
        for (std::map<size_t, SharedPtr<DnaSequenceData> >::iterator it = m_seqs_by_id.begin();
             it != m_seqs_by_id.end(); ++it) {
            all_the_sequences_vec.push_back(*(it->second));


        }
        return all_the_sequences_vec;
    }