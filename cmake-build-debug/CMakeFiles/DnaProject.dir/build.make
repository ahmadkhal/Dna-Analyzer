# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/57/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/57/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ahmad/CLionProjects/DnaProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmad/CLionProjects/DnaProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DnaProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DnaProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DnaProject.dir/flags.make

CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.o: CMakeFiles/DnaProject.dir/flags.make
CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.o: ../Model/dnaSequence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/DnaProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.o -c /home/ahmad/CLionProjects/DnaProject/Model/dnaSequence.cpp

CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/DnaProject/Model/dnaSequence.cpp > CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.i

CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/DnaProject/Model/dnaSequence.cpp -o CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.s

CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.o: CMakeFiles/DnaProject.dir/flags.make
CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.o: ../Model/Nucleotide.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/DnaProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.o -c /home/ahmad/CLionProjects/DnaProject/Model/Nucleotide.cpp

CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/DnaProject/Model/Nucleotide.cpp > CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.i

CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/DnaProject/Model/Nucleotide.cpp -o CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.s

CMakeFiles/DnaProject.dir/Controller/Controller.cpp.o: CMakeFiles/DnaProject.dir/flags.make
CMakeFiles/DnaProject.dir/Controller/Controller.cpp.o: ../Controller/Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/DnaProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DnaProject.dir/Controller/Controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaProject.dir/Controller/Controller.cpp.o -c /home/ahmad/CLionProjects/DnaProject/Controller/Controller.cpp

CMakeFiles/DnaProject.dir/Controller/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaProject.dir/Controller/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/DnaProject/Controller/Controller.cpp > CMakeFiles/DnaProject.dir/Controller/Controller.cpp.i

CMakeFiles/DnaProject.dir/Controller/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaProject.dir/Controller/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/DnaProject/Controller/Controller.cpp -o CMakeFiles/DnaProject.dir/Controller/Controller.cpp.s

CMakeFiles/DnaProject.dir/Controller/Command.cpp.o: CMakeFiles/DnaProject.dir/flags.make
CMakeFiles/DnaProject.dir/Controller/Command.cpp.o: ../Controller/Command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/DnaProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DnaProject.dir/Controller/Command.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaProject.dir/Controller/Command.cpp.o -c /home/ahmad/CLionProjects/DnaProject/Controller/Command.cpp

CMakeFiles/DnaProject.dir/Controller/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaProject.dir/Controller/Command.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/DnaProject/Controller/Command.cpp > CMakeFiles/DnaProject.dir/Controller/Command.cpp.i

CMakeFiles/DnaProject.dir/Controller/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaProject.dir/Controller/Command.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/DnaProject/Controller/Command.cpp -o CMakeFiles/DnaProject.dir/Controller/Command.cpp.s

CMakeFiles/DnaProject.dir/View/CLI.cpp.o: CMakeFiles/DnaProject.dir/flags.make
CMakeFiles/DnaProject.dir/View/CLI.cpp.o: ../View/CLI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmad/CLionProjects/DnaProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DnaProject.dir/View/CLI.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaProject.dir/View/CLI.cpp.o -c /home/ahmad/CLionProjects/DnaProject/View/CLI.cpp

CMakeFiles/DnaProject.dir/View/CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaProject.dir/View/CLI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmad/CLionProjects/DnaProject/View/CLI.cpp > CMakeFiles/DnaProject.dir/View/CLI.cpp.i

CMakeFiles/DnaProject.dir/View/CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaProject.dir/View/CLI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmad/CLionProjects/DnaProject/View/CLI.cpp -o CMakeFiles/DnaProject.dir/View/CLI.cpp.s

# Object files for target DnaProject
DnaProject_OBJECTS = \
"CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.o" \
"CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.o" \
"CMakeFiles/DnaProject.dir/Controller/Controller.cpp.o" \
"CMakeFiles/DnaProject.dir/Controller/Command.cpp.o" \
"CMakeFiles/DnaProject.dir/View/CLI.cpp.o"

# External object files for target DnaProject
DnaProject_EXTERNAL_OBJECTS =

DnaProject: CMakeFiles/DnaProject.dir/Model/dnaSequence.cpp.o
DnaProject: CMakeFiles/DnaProject.dir/Model/Nucleotide.cpp.o
DnaProject: CMakeFiles/DnaProject.dir/Controller/Controller.cpp.o
DnaProject: CMakeFiles/DnaProject.dir/Controller/Command.cpp.o
DnaProject: CMakeFiles/DnaProject.dir/View/CLI.cpp.o
DnaProject: CMakeFiles/DnaProject.dir/build.make
DnaProject: CMakeFiles/DnaProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmad/CLionProjects/DnaProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable DnaProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DnaProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DnaProject.dir/build: DnaProject

.PHONY : CMakeFiles/DnaProject.dir/build

CMakeFiles/DnaProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DnaProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DnaProject.dir/clean

CMakeFiles/DnaProject.dir/depend:
	cd /home/ahmad/CLionProjects/DnaProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmad/CLionProjects/DnaProject /home/ahmad/CLionProjects/DnaProject /home/ahmad/CLionProjects/DnaProject/cmake-build-debug /home/ahmad/CLionProjects/DnaProject/cmake-build-debug /home/ahmad/CLionProjects/DnaProject/cmake-build-debug/CMakeFiles/DnaProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DnaProject.dir/depend

