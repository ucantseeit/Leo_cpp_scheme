# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ucantseeit/my_pro/scheme/my_scheme

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ucantseeit/my_pro/scheme/my_scheme/build

# Include any dependencies generated for this target.
include CMakeFiles/test.o.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.o.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.o.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.o.dir/flags.make

CMakeFiles/test.o.dir/test.cpp.o: CMakeFiles/test.o.dir/flags.make
CMakeFiles/test.o.dir/test.cpp.o: ../test.cpp
CMakeFiles/test.o.dir/test.cpp.o: CMakeFiles/test.o.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ucantseeit/my_pro/scheme/my_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.o.dir/test.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.o.dir/test.cpp.o -MF CMakeFiles/test.o.dir/test.cpp.o.d -o CMakeFiles/test.o.dir/test.cpp.o -c /home/ucantseeit/my_pro/scheme/my_scheme/test.cpp

CMakeFiles/test.o.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.o.dir/test.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ucantseeit/my_pro/scheme/my_scheme/test.cpp > CMakeFiles/test.o.dir/test.cpp.i

CMakeFiles/test.o.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.o.dir/test.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ucantseeit/my_pro/scheme/my_scheme/test.cpp -o CMakeFiles/test.o.dir/test.cpp.s

CMakeFiles/test.o.dir/Pair.cpp.o: CMakeFiles/test.o.dir/flags.make
CMakeFiles/test.o.dir/Pair.cpp.o: ../Pair.cpp
CMakeFiles/test.o.dir/Pair.cpp.o: CMakeFiles/test.o.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ucantseeit/my_pro/scheme/my_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.o.dir/Pair.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.o.dir/Pair.cpp.o -MF CMakeFiles/test.o.dir/Pair.cpp.o.d -o CMakeFiles/test.o.dir/Pair.cpp.o -c /home/ucantseeit/my_pro/scheme/my_scheme/Pair.cpp

CMakeFiles/test.o.dir/Pair.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.o.dir/Pair.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ucantseeit/my_pro/scheme/my_scheme/Pair.cpp > CMakeFiles/test.o.dir/Pair.cpp.i

CMakeFiles/test.o.dir/Pair.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.o.dir/Pair.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ucantseeit/my_pro/scheme/my_scheme/Pair.cpp -o CMakeFiles/test.o.dir/Pair.cpp.s

CMakeFiles/test.o.dir/scheme.cpp.o: CMakeFiles/test.o.dir/flags.make
CMakeFiles/test.o.dir/scheme.cpp.o: ../scheme.cpp
CMakeFiles/test.o.dir/scheme.cpp.o: CMakeFiles/test.o.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ucantseeit/my_pro/scheme/my_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.o.dir/scheme.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.o.dir/scheme.cpp.o -MF CMakeFiles/test.o.dir/scheme.cpp.o.d -o CMakeFiles/test.o.dir/scheme.cpp.o -c /home/ucantseeit/my_pro/scheme/my_scheme/scheme.cpp

CMakeFiles/test.o.dir/scheme.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.o.dir/scheme.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ucantseeit/my_pro/scheme/my_scheme/scheme.cpp > CMakeFiles/test.o.dir/scheme.cpp.i

CMakeFiles/test.o.dir/scheme.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.o.dir/scheme.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ucantseeit/my_pro/scheme/my_scheme/scheme.cpp -o CMakeFiles/test.o.dir/scheme.cpp.s

CMakeFiles/test.o.dir/tokenizer.cpp.o: CMakeFiles/test.o.dir/flags.make
CMakeFiles/test.o.dir/tokenizer.cpp.o: ../tokenizer.cpp
CMakeFiles/test.o.dir/tokenizer.cpp.o: CMakeFiles/test.o.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ucantseeit/my_pro/scheme/my_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.o.dir/tokenizer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.o.dir/tokenizer.cpp.o -MF CMakeFiles/test.o.dir/tokenizer.cpp.o.d -o CMakeFiles/test.o.dir/tokenizer.cpp.o -c /home/ucantseeit/my_pro/scheme/my_scheme/tokenizer.cpp

CMakeFiles/test.o.dir/tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.o.dir/tokenizer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ucantseeit/my_pro/scheme/my_scheme/tokenizer.cpp > CMakeFiles/test.o.dir/tokenizer.cpp.i

CMakeFiles/test.o.dir/tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.o.dir/tokenizer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ucantseeit/my_pro/scheme/my_scheme/tokenizer.cpp -o CMakeFiles/test.o.dir/tokenizer.cpp.s

# Object files for target test.o
test_o_OBJECTS = \
"CMakeFiles/test.o.dir/test.cpp.o" \
"CMakeFiles/test.o.dir/Pair.cpp.o" \
"CMakeFiles/test.o.dir/scheme.cpp.o" \
"CMakeFiles/test.o.dir/tokenizer.cpp.o"

# External object files for target test.o
test_o_EXTERNAL_OBJECTS =

test.o: CMakeFiles/test.o.dir/test.cpp.o
test.o: CMakeFiles/test.o.dir/Pair.cpp.o
test.o: CMakeFiles/test.o.dir/scheme.cpp.o
test.o: CMakeFiles/test.o.dir/tokenizer.cpp.o
test.o: CMakeFiles/test.o.dir/build.make
test.o: CMakeFiles/test.o.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ucantseeit/my_pro/scheme/my_scheme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable test.o"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.o.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.o.dir/build: test.o
.PHONY : CMakeFiles/test.o.dir/build

CMakeFiles/test.o.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.o.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.o.dir/clean

CMakeFiles/test.o.dir/depend:
	cd /home/ucantseeit/my_pro/scheme/my_scheme/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ucantseeit/my_pro/scheme/my_scheme /home/ucantseeit/my_pro/scheme/my_scheme /home/ucantseeit/my_pro/scheme/my_scheme/build /home/ucantseeit/my_pro/scheme/my_scheme/build /home/ucantseeit/my_pro/scheme/my_scheme/build/CMakeFiles/test.o.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.o.dir/depend

