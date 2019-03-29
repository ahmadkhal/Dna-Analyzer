#include "Runner.h"
#include "../View/CLI.h"

Runner::Runner() : controller(SharedPtr<Controller>(
        new Controller(SharedPtr<View>(new CLI()), SharedPtr<DnaStore>(new DnaStore()),
                       SharedPtr<CommandParser>(new CommandParser())))) {}


void Runner::run() {


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

        result = controller->make_command(arg_vector[0])->execute(arg_vector,
                                                                  controller->getDnaAnalyzer());
        controller->getView()->print(result);
    }
    cout << "------ Good Bye ------" << endl;

}