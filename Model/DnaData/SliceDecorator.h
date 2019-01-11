#ifndef DNAPROJECT_SLICEDECORATOR_H
#define DNAPROJECT_SLICEDECORATOR_H


#include "AbstractDnaData.h"

class SliceDecorator : public AbstractDnaDecorator {

public:
    SliceDecorator(AbstractDnaData *dna_data, size_t from, size_t to) : AbstractDnaDecorator(dna_data) {

    }

    void manipulate() {
        m_dna_data->manipulate();
        m_dna_data->

    }
};

#endif //DNAPROJECT_SLICEDECORATOR_H
