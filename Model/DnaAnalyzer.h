#ifndef DNAPROJECT_DNAANALYZER_H
#define DNAPROJECT_DNAANALYZER_H


#include <map>
#include "DnaData/DnaSequenceData.h"
#include "SharedPtr.h"
#include "../Controller/Commands/CommandFactory.h"

class DnaAnalyzer {

public:
    size_t getNextCount() {
        return m_seq_count++;
    }


    void pushNewSeq(const size_t id, const string &name, SharedPtr<DnaSequenceData> sp) {
        m_seqs_by_name.insert(std::make_pair(name, sp));
        m_seqs_by_id.insert(std::make_pair(id, sp));
    }

    SharedPtr<DnaSequenceData> getSequenceById(size_t id) {
        return m_seqs_by_id.at(id);
    }

    SharedPtr<DnaSequenceData> getSequenceByName(const string &name) {
        return m_seqs_by_name.at(name);
    }


    SharedPtr<Command> make_command(const string &command) {
        return m_commands_factory.at(command)->make_command();
    }

    SharedPtr<DnaSequenceData> getDnaSequenceByArg(const string &str) {
        if (str[0] == '#') {

            return m_seqs_by_id.at(atoi(str.substr(1, str.size()).c_str()));
        }
        return m_seqs_by_name.at(str.substr(1, str.size()));
    }

    bool check_if_name_exist(string name) const {

        return !(m_seqs_by_name.find(name) == m_seqs_by_name.end());

    }

    vector<DnaSequenceData> get_all_the_sequences() {
        vector<DnaSequenceData> all_the_sequences_vec;
        for (std::map<size_t, SharedPtr<DnaSequenceData> >::iterator it = m_seqs_by_id.begin();
             it != m_seqs_by_id.end(); ++it) {
            all_the_sequences_vec.push_back(*(it->second));


        }
        return all_the_sequences_vec;
    }

    DnaAnalyzer() {
        m_seq_count = 1;
        m_commands_factory.insert(std::make_pair("new", SharedPtr<CommandFactory>(new NewCommandFactory())));
        m_commands_factory.insert(std::make_pair("load", SharedPtr<CommandFactory>(new LoadCommandFactory())));
        m_commands_factory.insert(std::make_pair("dup", SharedPtr<CommandFactory>(new DupCommandFactory())));
        m_commands_factory.insert(std::make_pair("save", SharedPtr<CommandFactory>(new SaveCommandFactory())));
        m_commands_factory.insert(std::make_pair("list", SharedPtr<CommandFactory>(new ListCommandFactory())));
        m_commands_factory.insert(std::make_pair("slice", SharedPtr<CommandFactory>(new SliceCommandFactory())));
        m_commands_factory.insert(std::make_pair("pair", SharedPtr<CommandFactory>(new PairCommandFactory())));
//        m_commands_factory.insert(std::make_pair("concat", SharedPtr<CommandFactory>(new ConcatCommandFactory())));
//        m_commands_factory.insert(std::make_pair("replace", SharedPtr<CommandFactory>(new ReplaceCommandFactory())));

    }

private:

    std::map<string, SharedPtr<CommandFactory> >      m_commands_factory;
    std::map<string, SharedPtr<DnaSequenceData> >     m_seqs_by_name;
    std::map<size_t, SharedPtr<DnaSequenceData> >     m_seqs_by_id;
    size_t                                            m_seq_count;

};

#endif //DNAPROJECT_DNAANALYZER_H
