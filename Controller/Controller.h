

#ifndef DNAPROJECT_CONTROLLER_H
#define DNAPROJECT_CONTROLLER_H

#include "../Model/SharedPtr.h"
#include "../View/View.h"
#include "DnaAnalyzer.h"
#include "CommandParser.h"

class Controller {
public:
    Controller(SharedPtr<View> view,
               SharedPtr<DnaAnalyzer> dna_analyzer,
               SharedPtr<CommandParser> parser) : m_view(view), m_dna_analyzer(dna_analyzer), m_parser(parser) {};

    SharedPtr<View> getView() {
        return m_view;
    }

    SharedPtr<DnaAnalyzer> getDnaAnalyzer() {
        return m_dna_analyzer;
    }

    SharedPtr<CommandParser> getParser() {
        return m_parser;
    }
    void start();

private:
    SharedPtr<View> m_view;
    SharedPtr<DnaAnalyzer> m_dna_analyzer;
    SharedPtr<CommandParser> m_parser;

};

#endif //DNAPROJECT_CONTROLLER_H
