#include "Nucleotide.h"

ostream &operator<<(ostream &out, const Nucleotide &s) {
    out << s.dna_sequence;
    return out;
}

Nucleotide::Nucleotide() {
    dna_sequence = 0;
}

Nucleotide::Nucleotide(char c) {

    if (c != 'A' && c != 'C' && c != 'T' && c != 'G') {
        throw std::invalid_argument("Invalid dna character");
    }
    this->dna_sequence = c;
}

bool operator==(const Nucleotide &n1, const Nucleotide &n2) {
    if (n1.dna_sequence == n2.dna_sequence) {
        return true;
    }
    return false;
}

bool operator!=(const Nucleotide &n1, const Nucleotide &n2) {
    return !(n1 == n2);
}
