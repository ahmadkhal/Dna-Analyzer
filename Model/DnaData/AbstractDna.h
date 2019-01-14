#ifndef DNAPROJECT_ABSTRACTDNA_H
#define DNAPROJECT_ABSTRACTDNA_H


#include "../SharedPtr.h"

class AbstractDna {
public:
    virtual Nucleotide operator[](size_t index) const = 0;

    virtual ~AbstractDna() {};

    virtual size_t size() const = 0;
};


inline  ostream& operator<<(ostream& os,SharedPtr<AbstractDna> sp_dna){
    for(size_t i=0;i<sp_dna->size();i++){
        os<<(*sp_dna)[i].getchar();
    }
    return os;
}
#endif //DNAPROJECT_ABSTRACTDNA_H
