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
CMAKE_SOURCE_DIR = /home/yujin/haejun/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yujin/haejun/cpp

# Include any dependencies generated for this target.
include CMakeFiles/stack3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/stack3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/stack3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stack3.dir/flags.make

CMakeFiles/stack3.dir/stack3/main.cpp.o: CMakeFiles/stack3.dir/flags.make
CMakeFiles/stack3.dir/stack3/main.cpp.o: stack3/main.cpp
CMakeFiles/stack3.dir/stack3/main.cpp.o: CMakeFiles/stack3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yujin/haejun/cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stack3.dir/stack3/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/stack3.dir/stack3/main.cpp.o -MF CMakeFiles/stack3.dir/stack3/main.cpp.o.d -o CMakeFiles/stack3.dir/stack3/main.cpp.o -c /home/yujin/haejun/cpp/stack3/main.cpp

CMakeFiles/stack3.dir/stack3/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stack3.dir/stack3/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yujin/haejun/cpp/stack3/main.cpp > CMakeFiles/stack3.dir/stack3/main.cpp.i

CMakeFiles/stack3.dir/stack3/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stack3.dir/stack3/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yujin/haejun/cpp/stack3/main.cpp -o CMakeFiles/stack3.dir/stack3/main.cpp.s

CMakeFiles/stack3.dir/stack3/stack.cpp.o: CMakeFiles/stack3.dir/flags.make
CMakeFiles/stack3.dir/stack3/stack.cpp.o: stack3/stack.cpp
CMakeFiles/stack3.dir/stack3/stack.cpp.o: CMakeFiles/stack3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yujin/haejun/cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stack3.dir/stack3/stack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/stack3.dir/stack3/stack.cpp.o -MF CMakeFiles/stack3.dir/stack3/stack.cpp.o.d -o CMakeFiles/stack3.dir/stack3/stack.cpp.o -c /home/yujin/haejun/cpp/stack3/stack.cpp

CMakeFiles/stack3.dir/stack3/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stack3.dir/stack3/stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yujin/haejun/cpp/stack3/stack.cpp > CMakeFiles/stack3.dir/stack3/stack.cpp.i

CMakeFiles/stack3.dir/stack3/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stack3.dir/stack3/stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yujin/haejun/cpp/stack3/stack.cpp -o CMakeFiles/stack3.dir/stack3/stack.cpp.s

# Object files for target stack3
stack3_OBJECTS = \
"CMakeFiles/stack3.dir/stack3/main.cpp.o" \
"CMakeFiles/stack3.dir/stack3/stack.cpp.o"

# External object files for target stack3
stack3_EXTERNAL_OBJECTS =

stack3: CMakeFiles/stack3.dir/stack3/main.cpp.o
stack3: CMakeFiles/stack3.dir/stack3/stack.cpp.o
stack3: CMakeFiles/stack3.dir/build.make
stack3: CMakeFiles/stack3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yujin/haejun/cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable stack3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stack3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stack3.dir/build: stack3
.PHONY : CMakeFiles/stack3.dir/build

CMakeFiles/stack3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stack3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stack3.dir/clean

CMakeFiles/stack3.dir/depend:
	cd /home/yujin/haejun/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yujin/haejun/cpp /home/yujin/haejun/cpp /home/yujin/haejun/cpp /home/yujin/haejun/cpp /home/yujin/haejun/cpp/CMakeFiles/stack3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stack3.dir/depend

