cmake_minimum_required(VERSION 3.13)
project(DnaProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(DnaProject Model/dnaSequence.cpp Model/Nucleotide.h Model/Nucleotide.cpp Controller/DnaAnalyzer.h Controller/Controller.h Controller/Controller.cpp View/View.h Controller/dnaSequenceMember.h Controller/Command.h Controller/Command.cpp View/CLI.h View/CLI.cpp)