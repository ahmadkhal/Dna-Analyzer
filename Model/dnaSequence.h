#ifndef DNASEQUENCE_H_
#define DNASEQUENCE_H_

#include <string>
#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <exception>
#include <fstream>
#include "Nucleotide.h"
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
using std::ofstream;
using std::ifstream;


class DnaSequence {
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

    DnaSequence(const Nucleotide &dns);

    DnaSequence(const DnaSequence &ds);

    DnaSequence &operator=(const Nucleotide &ds);

    DnaSequence &operator=(const DnaSequence &ds);

    DnaSequence &operator=(const char *str);

    DnaSequence &operator=(const string &str);

    Nucleotide &operator[](int ind);

    Nucleotide operator[](int ind) const;

    DnaSequence slicing(int from, int to) const;

    DnaSequence pairing() const;

    vector<DnaSequence> readFromFile(const char *path) const;

    void writeToFile(const char *path) const;

    int count(const DnaSequence &subSequence) const;

    Interval find(const DnaSequence &subSequence) const;

    const vector<DnaSequence::Interval> findAll(
            const DnaSequence &subSequence) const;

    vector<Interval> findAllConsensus() const;

    int getLength() const;

    ~DnaSequence();

    friend ostream &operator<<(ostream &out, const DnaSequence &s);

    friend bool operator==(const DnaSequence &ds1, const DnaSequence &ds2);

private:
    Nucleotide *aux_dna;
    int length;

    void init_and_allocate(const char *sequence);

};

bool operator!=(const DnaSequence &ds1, const DnaSequence &ds2);

inline int DnaSequence::getLength() const {

    return length;

}

//----------------------------------------------
inline int DnaSequence::Interval::getFrom() const {
    return from;
}

inline int DnaSequence::Interval::getTo() const {
    return to;
}

#endif /* DNASEQUENCE_H_ */
