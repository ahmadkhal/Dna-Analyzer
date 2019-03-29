#ifndef DNAPROJECT_REPLACEDECORATOR_H
#define DNAPROJECT_REPLACEDECORATOR_H

#include "AbstractDna.h"
#include "../SharedPtr.h"
#include "Nucleotide.h"
#include <vector>
#include <map>
#include <exception>

using std::vector;
using std::map;

class ReplaceDecorator : public AbstractDna {

public:
    ReplaceDecorator(SharedPtr<AbstractDna> dna, map<size_t,string > replacement_map) : m_dna(dna),
                                                                                   m_replacement_map(replacement_map) {
    }

    size_t size() const {
        return m_dna->size();
    }

    Nucleotide operator[](size_t index) const {
       try{
          string nuc= m_replacement_map.at(index);
           return Nucleotide((nuc.c_str())[0]);
       }catch(const std::exception& ex){
           return Nucleotide((*m_dna)[index]);
       }
    }

private:
    SharedPtr<AbstractDna> m_dna;
    std::map<size_t,string> m_replacement_map;
};

#endif //DNAPROJECT_REPLACEDECORATOR_H
