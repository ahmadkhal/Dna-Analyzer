

#ifndef DNAPROJECT_CONTROLLER_H
#define DNAPROJECT_CONTROLLER_H

#include "../Model/SharedPtr.h"
#include "../View/View.h"
#include "DnaAnalyzer.h"
#include "CommandParser.h"
#include "Commands/CommandFactory.h"
class Controller {
public:
    Controller(SharedPtr<View> view,
               SharedPtr<DnaAnalyzer> dna_analyzer,
               SharedPtr<CommandParser> parser) : m_view(view), m_dna_analyzer(dna_analyzer), m_parser(parser) {

        m_commands_factory.insert(std::make_pair("new", SharedPtr<CommandFactory>(new NewCommandFactory())));
        m_commands_factory.insert(std::make_pair("load", SharedPtr<CommandFactory>(new LoadCommandFactory())));
        m_commands_factory.insert(std::make_pair("dup", SharedPtr<CommandFactory>(new DupCommandFactory())));
        m_commands_factory.insert(std::make_pair("save", SharedPtr<CommandFactory>(new SaveCommandFactory())));
        m_commands_factory.insert(std::make_pair("list", SharedPtr<CommandFactory>(new ListCommandFactory())));
        m_commands_factory.insert(std::make_pair("slice", SharedPtr<CommandFactory>(new SliceCommandFactory())));
        m_commands_factory.insert(std::make_pair("pair", SharedPtr<CommandFactory>(new PairCommandFactory())));
        m_commands_factory.insert(std::make_pair("concat", SharedPtr<CommandFactory>(new ConcatCommandFactory())));
        m_commands_factory.insert(std::make_pair("replace", SharedPtr<CommandFactory>(new ReplaceCommandFactory())));
    };

    SharedPtr<View> getView() {
        return m_view;
    }

    SharedPtr<DnaAnalyzer> getDnaAnalyzer() {
        return m_dna_analyzer;
    }

    SharedPtr<CommandParser> getParser() {
        return m_parser;
    }
    SharedPtr<Command> make_command(const string &command) {
        return m_commands_factory.at(command)->make_command();
    }
    void start();

private:
    SharedPtr<View> m_view;
    SharedPtr<DnaAnalyzer> m_dna_analyzer;
    std::map<string, SharedPtr<CommandFactory> >
            m_commands_factory;
    SharedPtr<CommandParser> m_parser;

};

#endif //DNAPROJECT_CONTROLLER_H
