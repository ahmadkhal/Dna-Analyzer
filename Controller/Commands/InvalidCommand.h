

#ifndef DNAPROJECT_INVALIDCOMMAND_H
#define DNAPROJECT_INVALIDCOMMAND_H

#include <exception>

class InvalidCommand : public std::exception {
    const char *what() const throw() {
        return "Invalid Command";
    }
};


#endif //DNAPROJECT_INVALIDCOMMAND_H




