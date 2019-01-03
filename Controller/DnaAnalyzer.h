#ifndef DNAPROJECT_DNAANALYZER_H
#define DNAPROJECT_DNAANALYZER_H

#include "../Model/dnaSequence.h"
#include <map>

#include "../Model/SharedPtr.h"
#include "DnaSequenceMember.h"


class DnaAnalyzer {

public:
    size_t getNextCount() {
        return m_seq_count++;
    }


    void pushNewSeq(const size_t id, const string &name, SharedPtr<DnaSequenceMember> sp) {
        m_seqs_by_name.insert(std::make_pair(name, sp));
        m_seqs_by_id.insert(std::make_pair(id, sp));
    }

    SharedPtr<DnaSequenceMember> getSequenceById(size_t id) {
        return m_seqs_by_id.at(id);
    }

    SharedPtr<DnaSequenceMember> getSequenceByName(const string &name) {
        return m_seqs_by_name.at(name);
    }

    bool check_if_name_exist(string name) const {

        return !(m_seqs_by_name.find(name) == m_seqs_by_name.end());

    }

    vector<DnaSequenceMember> get_all_the_sequences() {
        vector<DnaSequenceMember> all_the_sequences_vec;
        for (std::map<size_t, SharedPtr<DnaSequenceMember> >::iterator it = m_seqs_by_id.begin();
             it != m_seqs_by_id.end(); ++it) {
            all_the_sequences_vec.push_back(*(it->second));


        }
        return all_the_sequences_vec;
    }

    DnaAnalyzer() {
        m_seq_count = 1;

    }

private:


    static DnaAnalyzer *m_ref;

    std::map<string, SharedPtr<DnaSequenceMember> > m_seqs_by_name;
    std::map<size_t, SharedPtr<DnaSequenceMember> > m_seqs_by_id;
    size_t m_seq_count;


};

#endif //DNAPROJECT_DNAANALYZER_H
