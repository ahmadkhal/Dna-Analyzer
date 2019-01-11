#ifndef DNAPROJECT_ABSTRACTDNADATA_H
#define DNAPROJECT_ABSTRACTDNADATA_H

#include <string>

using std::string;

class AbstractDnaData {
public:
    virtual void manipulate() = 0;
};


class AbstractDnaDecorator : public AbstractDnaData {
public:
    AbstractDnaDecorator(AbstractDnaData *dna_data) : m_dna_data(dna_data) {}

    void manipulate() { m_dna_data->manipulate(); }

protected:
    AbstractDnaData *m_dna_data;
};





#endif //DNAPROJECT_ABSTRACTDNADATA_H
