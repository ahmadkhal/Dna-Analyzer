
#include "Command.h"
#include "Management/SaveCommand.h"
#include "Manipulation/PairCommand.h"
#include "Control/ListCommand.h"
#include "Creational/LoadCommand.h"
#include "InvalidCommand.h"
#include "Creational/NewCommand.h"
#include "Manipulation/SliceCommand.h"
#include "Manipulation/ReplaceCommand.h"
#include "Manipulation/ConcatCommand.h"
#include "Creational/DupCommand.h"

SharedPtr<Command> Command::makeCommand(const string &command) {
//    MapOfCommands<String, COnstructor> myMap
//    myCstr = MyMap.FIND(cmd)
//            myCtrs.createComand()
    if (command == "new")
        return SharedPtr<Command>(new NewCommand());
    else if (command == "save")
        return SharedPtr<Command>(new SaveCommand());
    else if (command == "load")
        return SharedPtr<Command>(new LoadCommand());
    else if (command == "pair")
        return SharedPtr<Command>(new PairCommand());
    else if (command == "list")
        return SharedPtr<Command>(new ListCommand());
    else if (command == "slice")
        return SharedPtr<Command>(new SliceCommand());
    else if (command == "replace")
        return SharedPtr<Command>(new ReplaceCommand());
    else if (command == "concat")
        return SharedPtr<Command>(new ConcatCommand());
    else if (command == "dup")
        return SharedPtr<Command>(new DupCommand());
    else
        throw InvalidCommand();


}
