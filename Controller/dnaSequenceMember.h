//
// Created by ahmad on 12/29/18.
//

#ifndef DNAPROJECT_DNASEQUENCEMEMBER_H
#define DNAPROJECT_DNASEQUENCEMEMBER_H

#include "../Model/dnaSequence.h"

class DnaSequenceMember {
public:





    DnaSequenceMember(DnaSequence &seq, string name, size_t id) : m_seq(seq), m_name(name), m_id(id) {

    }

    DnaSequence getDnaSequence() const {
        return m_seq;
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


#endif //DNAPROJECT_DNASEQUENCEMEMBER_H
