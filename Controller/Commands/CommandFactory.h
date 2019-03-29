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



class ICommandFactory {
public:
    virtual SharedPtr<Command> create() = 0;

    virtual ~ICommandFactory() {}
};

class NewCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new NewCommand());
    }
};

class LoadCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new LoadCommand());
    }
};

class SaveCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new SaveCommand());
    }
};

class DupCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new DupCommand());
    }
};

class ListCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new ListCommand());
    }
};

class PairCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new PairCommand());
    }
};

class SliceCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new SliceCommand());
    }
};

class ConcatCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new ConcatCommand());
    }
};

class ReplaceCommandFactory : public ICommandFactory {
public:
    SharedPtr<Command> create() {
        return SharedPtr<Command>(new ReplaceCommand());
    }
};


#endif //DNAPROJECT_COMMANDFACTORY_H


