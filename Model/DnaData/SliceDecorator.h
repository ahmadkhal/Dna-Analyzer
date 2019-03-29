#ifndef DNAPROJECT_SLICEDECORATOR_H
#define DNAPROJECT_SLICEDECORATOR_H


#include "AbstractDna.h"


class SliceDecorator : public AbstractDna {

public:
    SliceDecorator(IDnaPtr dna, size_t from, size_t to) : m_dna(dna),
                                                          m_from(from), m_to(to) {
    }

    size_t size() const {
        return m_to - m_from;
    }

    Nucleotide operator[](size_t index) const {
        return (*m_dna)[m_from + index];
    }

private:
    IDnaPtr m_dna;
    size_t m_from;
    size_t m_to;
};

#endif //DNAPROJECT_SLICEDECORATOR_H