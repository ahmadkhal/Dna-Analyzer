#ifndef DNAPROJECT_REPLACEDECORATOR_H
#define DNAPROJECT_REPLACEDECORATOR_H
#include "AbstractDna.h"
#include "../SharedPtr.h"
#include "../Nucleotide.h"

class ReplaceDecorator : public AbstractDna {

public:
    ReplaceDecorator(SharedPtr<AbstractDna> dna,vector<>) : m_dna(dna) {
    }

    size_t size() const {
        return m_dna->size();
    }

    Nucleotide operator[](size_t index) const {
        return (*m_dna)[index].;
    }

private:
    SharedPtr<AbstractDna> m_dna;

};

#endif //DNAPROJECT_REPLACEDECORATOR_H
