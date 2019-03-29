#ifndef DNAPROJECT_DNAANALYZER_H
#define DNAPROJECT_DNAANALYZER_H


#include <map>
#include "DnaData/DnaSequenceData.h"
#include "SharedPtr.h"
#include "../Controller/Commands/CommandFactory.h"

class DnaStore {

public:
    DnaStore();

    size_t getNextCount();

    void pushNewSeq(const size_t id, const string &name, SharedPtr<DnaSequenceData> sp);

    SharedPtr<DnaSequenceData> getSequenceById(size_t id);

    SharedPtr<DnaSequenceData> getSequenceByName(const string &name);

    SharedPtr<DnaSequenceData> getDnaSequenceByArg(const string &str);

    bool check_if_name_exist(string name) const;

    vector<DnaSequenceData> get_all_the_sequences();


private:

    std::map<string, SharedPtr<DnaSequenceData> > m_seqs_by_name;
    std::map<size_t, SharedPtr<DnaSequenceData> > m_seqs_by_id;
    size_t m_seq_count;

};

//----------------------INLINE FUNCTIONS------------------------------------
inline size_t DnaStore::getNextCount() {
    return m_seq_count++;
}


inline SharedPtr<DnaSequenceData> DnaStore::getDnaSequenceByArg(const string &str) {
    if (str[0] == '#') {

        return m_seqs_by_id.at(atoi(str.substr(1, str.size()).c_str()));
    }
    return m_seqs_by_name.at(str.substr(1, str.size()));
}

inline void DnaStore::pushNewSeq(const size_t id, const string &name, SharedPtr<DnaSequenceData> sp) {
    m_seqs_by_name.insert(std::make_pair(name, sp));
    m_seqs_by_id.insert(std::make_pair(id, sp));
}


inline SharedPtr<DnaSequenceData> DnaStore::getSequenceById(size_t id) {
    return m_seqs_by_id.at(id);
}


inline SharedPtr<DnaSequenceData> DnaStore::getSequenceByName(const string &name) {
    return m_seqs_by_name.at(name);
}


inline bool DnaStore::check_if_name_exist(string name) const {

    return !(m_seqs_by_name.find(name) == m_seqs_by_name.end());

}

#endif //DNAPROJECT_DNAANALYZER_H
