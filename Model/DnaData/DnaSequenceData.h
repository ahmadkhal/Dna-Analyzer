#ifndef DNAPROJECT_DNASEQUENCEMEMBER_H
#define DNAPROJECT_DNASEQUENCEMEMBER_H

#include <sstream>
#include "dnaSequence.h"

#include "../SharedPtr.h"


class DnaSequenceData {
public:


    DnaSequenceData(SharedPtr<AbstractDna> seq, const string name, size_t id) : m_seq(seq), m_name(name), m_id(id) {
    }

    string formatted_string() const;


    SharedPtr<AbstractDna> getDnaSequence();

    void setDnaSequence(SharedPtr<AbstractDna> ds);

    string getString() {
        string str = "";
        for (size_t ind = 0; ind < m_seq->size(); ind++) {
            str += (*m_seq)[ind].getchar();
        }
        return str;
    }

    string getName() const;

    size_t getID() const;

private:
    SharedPtr<AbstractDna> m_seq;
    string m_name;
    size_t m_id;

};


ostream &operator<<(ostream &os, const DnaSequenceData &dnaSequenceMember);

inline SharedPtr<AbstractDna> DnaSequenceData::getDnaSequence() {
    return m_seq;
}

inline void DnaSequenceData::setDnaSequence(SharedPtr<AbstractDna> ds) {
    m_seq = ds;
}

inline string DnaSequenceData::getName() const {
    return m_name;
}

inline size_t DnaSequenceData::getID() const {
    return m_id;
}


#endif //DNAPROJECT_DNASEQUENCEMEMBER_H