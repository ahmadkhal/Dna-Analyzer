#ifndef DNAPROJECT_DNAANALYZER_H
#define DNAPROJECT_DNAANALYZER_H

#include "../Model/dnaSequence.h"
#include "dnaSequenceMember.h"
#include <map>
#include "Command.h"
#include "../Model/SharedPtr.h"

class DnaAnalyzer {

public:
    size_t getNextCount() {
        return m_seq_count++;
    }

    static DnaAnalyzer *getInstance() {
        if (!m_ref) {
            m_ref = new DnaAnalyzer();
        }
        return m_ref;
    }

    SharedPtr<Command>& getCmd(const string &cmd) {
        return m_first.at(cmd);
    }

    void pushNewSeq(const DnaSequenceMember &d) {
        m_sequences.push_back(d);
    }

private:
    DnaAnalyzer() {
        m_seq_count = 1;
        m_first.insert(std::make_pair("new", SharedPtr<Command>(new NewCmd())));

    }

    static DnaAnalyzer *m_ref;
    std::map<string, SharedPtr<Command> > m_first;
    vector<DnaSequenceMember> m_sequences;
    size_t m_seq_count;


};

#endif //DNAPROJECT_DNAANALYZER_H
