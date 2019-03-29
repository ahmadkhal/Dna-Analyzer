#ifndef DNASEQUENCE_H_
#define DNASEQUENCE_H_

#include <string>
#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <exception>
#include "Nucleotide.h"
#include "AbstractDna.h"
#include <map>
#include <iterator>
#include <assert.h>
#include <vector>

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::exception;
using std::invalid_argument;
using std::map;
using std::bad_alloc;


class DnaSequence : public AbstractDna {
public:
    class Interval {

    public:

        explicit Interval(int from, int to) :
                from(from), to(to) {
        }

        int getFrom() const;

        int getTo() const;

    private:
        int from;
        int to;
    };

    DnaSequence(const char *dna_sequence);

    DnaSequence(const string &dna_sequence);

    DnaSequence(const DnaSequence &ds);

    DnaSequence &operator=(const DnaSequence &ds);

    DnaSequence &operator=(const char *str);

    DnaSequence &operator=(const string &str);

    Nucleotide operator[](size_t index) const;

    string getString() const;

    size_t size() const;

    DnaSequence slicing(size_t from, size_t to) const;

    DnaSequence pairing() const;

    int count(const DnaSequence &subSequence) const;

    Interval find(const DnaSequence &subSequence) const;

    const vector<DnaSequence::Interval> findAll(
            const DnaSequence &subSequence) const;

    vector<Interval> findAllConsensus() const;



    ~DnaSequence();


private:
    Nucleotide *aux_dna;
    size_t length;

    void init_and_allocate(const char *sequence);

};

bool operator!=(const DnaSequence &ds1, const DnaSequence &ds2);

inline size_t DnaSequence::size() const {
    return size();
}


inline string DnaSequence::getString() const {
    string str = "";
    for (int i = 0; i < length; i++) {
        str += aux_dna[i].getchar();
    }
    return str;

}

inline ostream &operator<<(ostream &out, const DnaSequence &ds) {

    out << ds.getString();


    return out;
}

inline bool operator==(const DnaSequence &ds1, const DnaSequence &ds2) {

    if (ds1.size() != ds2.size()) {
        return false;
    }
    return ds1.getString() == ds2.getString();


}


inline Nucleotide DnaSequence::operator[](size_t index) const {
    return aux_dna[index];

}

//----------------------------------------------
inline int DnaSequence::Interval::getFrom() const {
    return from;
}

inline int DnaSequence::Interval::getTo() const {
    return to;
}

#endif /* DNASEQUENCE_H_ */
