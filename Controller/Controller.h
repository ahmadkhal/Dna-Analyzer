

#ifndef DNAPROJECT_CONTROLLER_H
#define DNAPROJECT_CONTROLLER_H

#include "../Model/SharedPtr.h"
#include "../View/View.h"
#include "../Model/DnaStore.h"
#include "CommandParser.h"
#include "Commands/CommandFactory.h"

class Controller {
public:
    Controller(SharedPtr<View> view,
               SharedPtr<DnaStore> dna_analyzer,
               SharedPtr<CommandParser> parser) : m_view(view), m_dna_analyzer(dna_analyzer), m_parser(parser) {
        m_commands_factory.insert(std::make_pair("new", SharedPtr<ICommandFactory>(new NewCommandFactory())));
        m_commands_factory.insert(std::make_pair("load", SharedPtr<ICommandFactory>(new LoadCommandFactory())));
        m_commands_factory.insert(std::make_pair("dup", SharedPtr<ICommandFactory>(new DupCommandFactory())));
        m_commands_factory.insert(std::make_pair("save", SharedPtr<ICommandFactory>(new SaveCommandFactory())));
        m_commands_factory.insert(std::make_pair("list", SharedPtr<ICommandFactory>(new ListCommandFactory())));
        m_commands_factory.insert(std::make_pair("slice", SharedPtr<ICommandFactory>(new SliceCommandFactory())));
        m_commands_factory.insert(std::make_pair("pair", SharedPtr<ICommandFactory>(new PairCommandFactory())));
        m_commands_factory.insert(std::make_pair("concat", SharedPtr<ICommandFactory>(new ConcatCommandFactory())));
        m_commands_factory.insert(std::make_pair("replace", SharedPtr<ICommandFactory>(new ReplaceCommandFactory())));



    };

    SharedPtr<View> getView() {
        return m_view;
    }

    SharedPtr<DnaStore> getDnaAnalyzer() {
        return m_dna_analyzer;
    }

    SharedPtr<CommandParser> getParser() {
        return m_parser;
    }
    SharedPtr<Command> make_command(const string &command) {
        return m_commands_factory.at(command)->create();
    }

    void start();

private:
    SharedPtr<View> m_view;
    SharedPtr<DnaStore> m_dna_analyzer;
    SharedPtr<CommandParser> m_parser;
    std::map<string, SharedPtr<ICommandFactory> >      m_commands_factory;



};

#endif //DNAPROJECT_CONTROLLER_H
