#ifndef DNAPROJECT_CONCATDECORATOR_H
#define DNAPROJECT_CONCATDECORATOR_H


#include "AbstractDna.h"
#include "../SharedPtr.h"
#include "../Nucleotide.h"

class ConcatDecorator : public AbstractDna {

public:
    ConcatDecorator(vector<SharedPtr<AbstractDna> > dna_vector) : m_dna_vector(dna_vector) {
    }

    size_t size() const {
        size_t size = 0;
        for (size_t i = 0; i < m_dna_vector.size(); i++) {
            size += m_dna_vector[i]->size();
        }
        return size;
    }

    Nucleotide operator[](size_t index) const {
        size_t size = 0;
        for (size_t i = 0; i < m_dna_vector.size(); i++) {
            size += m_dna_vector[i]->size();
            if (index < size) {
                return (*(m_dna_vector[i]))[index - (size-m_dna_vector[i]->size())];
            }

        }
    }

private:

    vector<SharedPtr<AbstractDna> > m_dna_vector;

};


#endif //DNAPROJECT_CONCATDECORATOR_H
