#ifndef DNAPROJECT_DNASEQUENCEMEMBER_H
#define DNAPROJECT_DNASEQUENCEMEMBER_H

#include <sstream>
#include "../dnaSequence.h"
#include "AbstractDnaData.h"


class DnaSequenceData : public AbstractDnaData {
public:


    DnaSequenceData(DnaSequence seq, const string name, size_t id) : m_seq(seq), m_name(name), m_id(id) {

    }

    string formatted_string() const;

    void manipulate() {
        cout << "We got here" << endl;
    }

    const DnaSequence &getDnaSequence() const;

    void setDnaSequence(const DnaSequence &ds);

    string getName() const;

    size_t getID() const;

private:
    DnaSequence m_seq;
    string m_name;
    size_t m_id;

};


ostream &operator<<(ostream &os, const DnaSequenceData &dnaSequenceMember);

inline const DnaSequence &DnaSequenceData::getDnaSequence() const {
    return m_seq;
}

inline void DnaSequenceData::setDnaSequence(const DnaSequence &ds) {
    m_seq = ds;
}

inline string DnaSequenceData::getName() const {
    return m_name;
}

inline size_t DnaSequenceData::getID() const {
    return m_id;
}


#endif //DNAPROJECT_DNASEQUENCEMEMBER_H