#include "DnaSequenceMember.h"


 ostream &operator<<(ostream &os, const DnaSequenceMember &dnaSequenceMember) {
    os << "[" << dnaSequenceMember.getID() << "] " << dnaSequenceMember.getName() << ": "
       << dnaSequenceMember.formated_string();
    return os;
}

