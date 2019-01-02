#ifndef DNAPROJECT_DNAANALYZER_H
#define DNAPROJECT_DNAANALYZER_H

#include "../Model/dnaSequence.h"
#include <map>
#include "Commands/Command.h"
#include "../Model/SharedPtr.h"
#include "DnaSequenceMember.h"
#include "Commands/Creational/NewCommand.h"
#include "Commands/Management/SaveCommand.h"
#include "Commands/Creational/LoadCommand.h"
#include "Commands/Manipulation/PairCommand.h"
#include "Commands/Control/ListCommand.h"

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

    SharedPtr<Command> &getCmd(const string &cmd) {
        return m_commands.at(cmd);
    }

    void pushNewSeq(const size_t id, const string &name, SharedPtr<DnaSequenceMember> sp) {
        m_seqs_by_name.insert(std::make_pair(name, sp));
        m_seqs_by_id.insert(std::make_pair(id, sp));
    }

    SharedPtr<DnaSequenceMember> getSequenceById(size_t id) {
        return m_seqs_by_id.at(id);
    }

    SharedPtr<DnaSequenceMember> getSequenceByName(const string &name) {
        return m_seqs_by_name.at(name);
    }

    bool check_if_name_exist(string name) const {

        return !(m_seqs_by_name.find(name) == m_seqs_by_name.end());

    }

    vector<DnaSequenceMember> get_all_the_sequences() {
        vector<DnaSequenceMember> all_the_sequences_vec;
        for (std::map<size_t, SharedPtr<DnaSequenceMember> >::iterator it = m_seqs_by_id.begin();
             it != m_seqs_by_id.end(); ++it) {
            all_the_sequences_vec.push_back(*(it->second));


        }
        return all_the_sequences_vec;
    }

private:
    DnaAnalyzer() {
        m_seq_count = 1;
        m_commands.insert(std::make_pair("new", SharedPtr<Command>(new NewCommand())));
        m_commands.insert(std::make_pair("save", SharedPtr<Command>(new SaveCommand())));
        m_commands.insert(std::make_pair("load", SharedPtr<Command>(new LoadCommand())));
        m_commands.insert(std::make_pair("pair", SharedPtr<Command>(new PairCommand())));
        m_commands.insert(std::make_pair("list", SharedPtr<Command>(new ListCommand())));

    }

    static DnaAnalyzer *m_ref;
    std::map<string, SharedPtr<Command> > m_commands;
    std::map<string, SharedPtr<DnaSequenceMember> > m_seqs_by_name;
    std::map<size_t, SharedPtr<DnaSequenceMember> > m_seqs_by_id;
    size_t m_seq_count;


};

#endif //DNAPROJECT_DNAANALYZER_H
