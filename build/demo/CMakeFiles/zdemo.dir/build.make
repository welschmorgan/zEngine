# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/dev/engines/zEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/dev/engines/zEngine/build

# Include any dependencies generated for this target.
include demo/CMakeFiles/zdemo.dir/depend.make

# Include the progress variables for this target.
include demo/CMakeFiles/zdemo.dir/progress.make

# Include the compile flags for this target's objects.
include demo/CMakeFiles/zdemo.dir/flags.make

demo/CMakeFiles/zdemo.dir/src/main.cpp.o: demo/CMakeFiles/zdemo.dir/flags.make
demo/CMakeFiles/zdemo.dir/src/main.cpp.o: ../demo/src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/dev/engines/zEngine/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object demo/CMakeFiles/zdemo.dir/src/main.cpp.o"
	cd /root/dev/engines/zEngine/build/demo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zdemo.dir/src/main.cpp.o -c /root/dev/engines/zEngine/demo/src/main.cpp

demo/CMakeFiles/zdemo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zdemo.dir/src/main.cpp.i"
	cd /root/dev/engines/zEngine/build/demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/dev/engines/zEngine/demo/src/main.cpp > CMakeFiles/zdemo.dir/src/main.cpp.i

demo/CMakeFiles/zdemo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zdemo.dir/src/main.cpp.s"
	cd /root/dev/engines/zEngine/build/demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/dev/engines/zEngine/demo/src/main.cpp -o CMakeFiles/zdemo.dir/src/main.cpp.s

demo/CMakeFiles/zdemo.dir/src/main.cpp.o.requires:
.PHONY : demo/CMakeFiles/zdemo.dir/src/main.cpp.o.requires

demo/CMakeFiles/zdemo.dir/src/main.cpp.o.provides: demo/CMakeFiles/zdemo.dir/src/main.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/zdemo.dir/build.make demo/CMakeFiles/zdemo.dir/src/main.cpp.o.provides.build
.PHONY : demo/CMakeFiles/zdemo.dir/src/main.cpp.o.provides

demo/CMakeFiles/zdemo.dir/src/main.cpp.o.provides.build: demo/CMakeFiles/zdemo.dir/src/main.cpp.o

# Object files for target zdemo
zdemo_OBJECTS = \
"CMakeFiles/zdemo.dir/src/main.cpp.o"

# External object files for target zdemo
zdemo_EXTERNAL_OBJECTS =

demo/bin/DEBUG/zdemo: demo/CMakeFiles/zdemo.dir/src/main.cpp.o
demo/bin/DEBUG/zdemo: demo/CMakeFiles/zdemo.dir/build.make
demo/bin/DEBUG/zdemo: demo/CMakeFiles/zdemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/DEBUG/zdemo"
	cd /root/dev/engines/zEngine/build/demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zdemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/CMakeFiles/zdemo.dir/build: demo/bin/DEBUG/zdemo
.PHONY : demo/CMakeFiles/zdemo.dir/build

demo/CMakeFiles/zdemo.dir/requires: demo/CMakeFiles/zdemo.dir/src/main.cpp.o.requires
.PHONY : demo/CMakeFiles/zdemo.dir/requires

demo/CMakeFiles/zdemo.dir/clean:
	cd /root/dev/engines/zEngine/build/demo && $(CMAKE_COMMAND) -P CMakeFiles/zdemo.dir/cmake_clean.cmake
.PHONY : demo/CMakeFiles/zdemo.dir/clean

demo/CMakeFiles/zdemo.dir/depend:
	cd /root/dev/engines/zEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/dev/engines/zEngine /root/dev/engines/zEngine/demo /root/dev/engines/zEngine/build /root/dev/engines/zEngine/build/demo /root/dev/engines/zEngine/build/demo/CMakeFiles/zdemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/CMakeFiles/zdemo.dir/depend
