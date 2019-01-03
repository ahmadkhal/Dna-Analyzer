#ifndef DNAPROJECT_DNASEQUENCEMEMBER_H
#define DNAPROJECT_DNASEQUENCEMEMBER_H

#include <sstream>
#include "../Model/dnaSequence.h"

class DnaSequenceMember {
public:


    DnaSequenceMember(DnaSequence seq, const string name, size_t id) : m_seq(seq), m_name(name), m_id(id) {

    }

    string formated_string() const {
        std::ostringstream oss;
        oss << m_seq;
        string sequence_string = oss.str();
        size_t sequence_size = sequence_string.size();
        if (sequence_size > 40) {
            return sequence_string.substr(0, 32) + "..." + sequence_string.substr(sequence_size - 3, sequence_size);
        }
        return sequence_string;
    }

    const DnaSequence &getDnaSequence() const {
        return m_seq;
    }

    void setDnaSequence(const DnaSequence &ds) {
        m_seq = ds;
    }

    string getName() const {
        return m_name;
    }

    size_t getID() const {
        return m_id;
    }

private:
    DnaSequence m_seq;
    string m_name;
    size_t m_id;

};


 ostream &operator<<(ostream &os, const DnaSequenceMember &dnaSequenceMember);




#endif //DNAPROJECT_DNASEQUENCEMEMBER_H