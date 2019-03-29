#ifndef DNAPROJECT_PAIRDECORATOR_H
#define DNAPROJECT_PAIRDECORATOR_H


#include "AbstractDna.h"
#include "../SharedPtr.h"
#include "Nucleotide.h"

class PairDecorator : public AbstractDna {

public:
    PairDecorator(SharedPtr<AbstractDna> dna) : m_dna(dna) {
    }

    size_t size() const {
        return m_dna->size();
    }

    Nucleotide operator[](size_t index) const {
        return (*m_dna)[index].pair();
    }

private:
    SharedPtr<AbstractDna> m_dna;

};

#endif //DNAPROJECT_PAIRDECORATOR_H
