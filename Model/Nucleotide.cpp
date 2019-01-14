#include "Nucleotide.h"

ostream &operator<<(ostream &out, const Nucleotide &s) {
    out << s.m_char;
    return out;
}

Nucleotide::Nucleotide() {
    m_char = 0;
}

Nucleotide::Nucleotide(char c) {

    if (c != 'A' && c != 'C' && c != 'T' && c != 'G') {
        throw std::invalid_argument("Invalid dna character");
    }
    this->m_char = c;
}

bool operator==(const Nucleotide &n1, const Nucleotide &n2) {
    if (n1.m_char == n2.m_char) {
        return true;
    }
    return false;
}

bool operator!=(const Nucleotide &n1, const Nucleotide &n2) {
    return !(n1 == n2);
}


Nucleotide Nucleotide::pair() {

    if (m_char == 'T')
        return Nucleotide('A');
    else if (m_char == 'A')
        return Nucleotide('T');
    else if (m_char == 'G')
        return Nucleotide('C');
    else
        return Nucleotide('G');

}
