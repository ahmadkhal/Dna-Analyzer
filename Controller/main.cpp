#include "Controller.h"
#include "../View/CLI.h"
#include "Commands/Command.h"


int main(int argc, char *argv[]) {

    SharedPtr<Controller> controller(
            new Controller(SharedPtr<View>(new CLI()), SharedPtr<DnaAnalyzer>(new DnaAnalyzer()),
                           SharedPtr<CommandParser>(new CommandParser())));


    string cmdline;
    string result;

    while (1) {
        vector<string> arg_vector;
        controller->getView()->start();
        cmdline = controller->getView()->prompt();
        arg_vector = controller->getParser()->parse(cmdline, ' ');
        if (arg_vector[0] == "exit") {
            break;
        }
        result = controller->getDnaAnalyzer()->make_command(arg_vector[0])->execute(arg_vector,
                                                                                    controller->getDnaAnalyzer());
        controller->getView()->print(result);

    }
    cout << "------ Good Bye ------" << endl;
    return 0;
}


