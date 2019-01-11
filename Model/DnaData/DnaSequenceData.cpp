#include "DnaSequenceData.h"


ostream &operator<<(ostream &os, const DnaSequenceData &dnaSequenceMember) {
    os << "[" << dnaSequenceMember.getID() << "] " << dnaSequenceMember.getName() << ":"
       << dnaSequenceMember.formatted_string();
    return os;
}

string DnaSequenceData::formatted_string() const {
    std::ostringstream oss;
    oss << m_seq;
    string sequence_string = oss.str();
    size_t sequence_size = sequence_string.size();
    if (sequence_size > 40) {
        return sequence_string.substr(0, 32) + "..." + sequence_string.substr(sequence_size - 3, sequence_size);
    }
    return sequence_string;
}