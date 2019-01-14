#ifndef DNAPROJECT_NUCLEOTIDE_H
#define DNAPROJECT_NUCLEOTIDE_H

#include<iostream>
#include <exception>
using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::ostream;


class Nucleotide {
    char m_char;

public:
    Nucleotide();

    Nucleotide(char c);

    char getchar() const;
    Nucleotide pair();

    friend ostream &operator<<(ostream &out, const Nucleotide &s);

    friend bool operator==(const Nucleotide &n1, const Nucleotide &n2);
};



bool operator!=(const Nucleotide &n1, const Nucleotide &n2);

inline char Nucleotide::Nucleotide::getchar() const {
    return m_char;
}


#endif //DNAPROJECT_NUCLEOTIDE_H
