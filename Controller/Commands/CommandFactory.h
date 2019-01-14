#ifndef DNAPROJECT_COMMANDFACTORY_H
#define DNAPROJECT_COMMANDFACTORY_H




#include "Manipulation/PairCommand.h"
#include "Manipulation/SliceCommand.h"
#include "Manipulation/ConcatCommand.h"
#include "Manipulation/ReplaceCommand.h"
#include "Creational/NewCommand.h"
#include "Creational/LoadCommand.h"
#include "Management/SaveCommand.h"
#include "Creational/DupCommand.h"
#include "Control/ListCommand.h"



class CommandFactory {
public:
    virtual SharedPtr<Command> make_command() = 0;

    virtual ~CommandFactory() {}
};

class NewCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new NewCommand());
    }
};

class LoadCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new LoadCommand());
    }
};

class SaveCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new SaveCommand());
    }
};

class DupCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new DupCommand());
    }
};

class ListCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new ListCommand());
    }
};

class PairCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new PairCommand());
    }
};

class SliceCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new SliceCommand());
    }
};

class ConcatCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new ConcatCommand());
    }
};

class ReplaceCommandFactory : public CommandFactory {
public:
    SharedPtr<Command> make_command() {
        return SharedPtr<Command>(new ReplaceCommand());
    }
};


#endif //DNAPROJECT_COMMANDFACTORY_H


