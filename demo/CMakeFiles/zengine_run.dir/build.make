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
CMAKE_SOURCE_DIR = /home/darkboss/dev/engines/zEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darkboss/dev/engines/zEngine/tests

# Include any dependencies generated for this target.
include CMakeFiles/zengine_run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zengine_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zengine_run.dir/flags.make

CMakeFiles/zengine_run.dir/src/main.cpp.o: CMakeFiles/zengine_run.dir/flags.make
CMakeFiles/zengine_run.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/darkboss/dev/engines/zEngine/tests/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zengine_run.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zengine_run.dir/src/main.cpp.o -c /home/darkboss/dev/engines/zEngine/src/main.cpp

CMakeFiles/zengine_run.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine_run.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/darkboss/dev/engines/zEngine/src/main.cpp > CMakeFiles/zengine_run.dir/src/main.cpp.i

CMakeFiles/zengine_run.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine_run.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/darkboss/dev/engines/zEngine/src/main.cpp -o CMakeFiles/zengine_run.dir/src/main.cpp.s

CMakeFiles/zengine_run.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/zengine_run.dir/src/main.cpp.o.requires

CMakeFiles/zengine_run.dir/src/main.cpp.o.provides: CMakeFiles/zengine_run.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine_run.dir/build.make CMakeFiles/zengine_run.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/zengine_run.dir/src/main.cpp.o.provides

CMakeFiles/zengine_run.dir/src/main.cpp.o.provides.build: CMakeFiles/zengine_run.dir/src/main.cpp.o

CMakeFiles/zengine_run.dir/src/state_manager.cpp.o: CMakeFiles/zengine_run.dir/flags.make
CMakeFiles/zengine_run.dir/src/state_manager.cpp.o: ../src/state_manager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/darkboss/dev/engines/zEngine/tests/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zengine_run.dir/src/state_manager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zengine_run.dir/src/state_manager.cpp.o -c /home/darkboss/dev/engines/zEngine/src/state_manager.cpp

CMakeFiles/zengine_run.dir/src/state_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine_run.dir/src/state_manager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/darkboss/dev/engines/zEngine/src/state_manager.cpp > CMakeFiles/zengine_run.dir/src/state_manager.cpp.i

CMakeFiles/zengine_run.dir/src/state_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine_run.dir/src/state_manager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/darkboss/dev/engines/zEngine/src/state_manager.cpp -o CMakeFiles/zengine_run.dir/src/state_manager.cpp.s

CMakeFiles/zengine_run.dir/src/state_manager.cpp.o.requires:
.PHONY : CMakeFiles/zengine_run.dir/src/state_manager.cpp.o.requires

CMakeFiles/zengine_run.dir/src/state_manager.cpp.o.provides: CMakeFiles/zengine_run.dir/src/state_manager.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine_run.dir/build.make CMakeFiles/zengine_run.dir/src/state_manager.cpp.o.provides.build
.PHONY : CMakeFiles/zengine_run.dir/src/state_manager.cpp.o.provides

CMakeFiles/zengine_run.dir/src/state_manager.cpp.o.provides.build: CMakeFiles/zengine_run.dir/src/state_manager.cpp.o

CMakeFiles/zengine_run.dir/src/platform.cpp.o: CMakeFiles/zengine_run.dir/flags.make
CMakeFiles/zengine_run.dir/src/platform.cpp.o: ../src/platform.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/darkboss/dev/engines/zEngine/tests/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zengine_run.dir/src/platform.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zengine_run.dir/src/platform.cpp.o -c /home/darkboss/dev/engines/zEngine/src/platform.cpp

CMakeFiles/zengine_run.dir/src/platform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine_run.dir/src/platform.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/darkboss/dev/engines/zEngine/src/platform.cpp > CMakeFiles/zengine_run.dir/src/platform.cpp.i

CMakeFiles/zengine_run.dir/src/platform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine_run.dir/src/platform.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/darkboss/dev/engines/zEngine/src/platform.cpp -o CMakeFiles/zengine_run.dir/src/platform.cpp.s

CMakeFiles/zengine_run.dir/src/platform.cpp.o.requires:
.PHONY : CMakeFiles/zengine_run.dir/src/platform.cpp.o.requires

CMakeFiles/zengine_run.dir/src/platform.cpp.o.provides: CMakeFiles/zengine_run.dir/src/platform.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine_run.dir/build.make CMakeFiles/zengine_run.dir/src/platform.cpp.o.provides.build
.PHONY : CMakeFiles/zengine_run.dir/src/platform.cpp.o.provides

CMakeFiles/zengine_run.dir/src/platform.cpp.o.provides.build: CMakeFiles/zengine_run.dir/src/platform.cpp.o

CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o: CMakeFiles/zengine_run.dir/flags.make
CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o: ../src/ogre_console.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/darkboss/dev/engines/zEngine/tests/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o -c /home/darkboss/dev/engines/zEngine/src/ogre_console.cpp

CMakeFiles/zengine_run.dir/src/ogre_console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine_run.dir/src/ogre_console.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/darkboss/dev/engines/zEngine/src/ogre_console.cpp > CMakeFiles/zengine_run.dir/src/ogre_console.cpp.i

CMakeFiles/zengine_run.dir/src/ogre_console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine_run.dir/src/ogre_console.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/darkboss/dev/engines/zEngine/src/ogre_console.cpp -o CMakeFiles/zengine_run.dir/src/ogre_console.cpp.s

CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o.requires:
.PHONY : CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o.requires

CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o.provides: CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine_run.dir/build.make CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o.provides.build
.PHONY : CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o.provides

CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o.provides.build: CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o

CMakeFiles/zengine_run.dir/src/exception.cpp.o: CMakeFiles/zengine_run.dir/flags.make
CMakeFiles/zengine_run.dir/src/exception.cpp.o: ../src/exception.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/darkboss/dev/engines/zEngine/tests/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zengine_run.dir/src/exception.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zengine_run.dir/src/exception.cpp.o -c /home/darkboss/dev/engines/zEngine/src/exception.cpp

CMakeFiles/zengine_run.dir/src/exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine_run.dir/src/exception.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/darkboss/dev/engines/zEngine/src/exception.cpp > CMakeFiles/zengine_run.dir/src/exception.cpp.i

CMakeFiles/zengine_run.dir/src/exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine_run.dir/src/exception.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/darkboss/dev/engines/zEngine/src/exception.cpp -o CMakeFiles/zengine_run.dir/src/exception.cpp.s

CMakeFiles/zengine_run.dir/src/exception.cpp.o.requires:
.PHONY : CMakeFiles/zengine_run.dir/src/exception.cpp.o.requires

CMakeFiles/zengine_run.dir/src/exception.cpp.o.provides: CMakeFiles/zengine_run.dir/src/exception.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine_run.dir/build.make CMakeFiles/zengine_run.dir/src/exception.cpp.o.provides.build
.PHONY : CMakeFiles/zengine_run.dir/src/exception.cpp.o.provides

CMakeFiles/zengine_run.dir/src/exception.cpp.o.provides.build: CMakeFiles/zengine_run.dir/src/exception.cpp.o

CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o: CMakeFiles/zengine_run.dir/flags.make
CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o: ../src/ambiance_manager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/darkboss/dev/engines/zEngine/tests/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o -c /home/darkboss/dev/engines/zEngine/src/ambiance_manager.cpp

CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/darkboss/dev/engines/zEngine/src/ambiance_manager.cpp > CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.i

CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/darkboss/dev/engines/zEngine/src/ambiance_manager.cpp -o CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.s

CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o.requires:
.PHONY : CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o.requires

CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o.provides: CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine_run.dir/build.make CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o.provides.build
.PHONY : CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o.provides

CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o.provides.build: CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o

CMakeFiles/zengine_run.dir/src/root.cpp.o: CMakeFiles/zengine_run.dir/flags.make
CMakeFiles/zengine_run.dir/src/root.cpp.o: ../src/root.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/darkboss/dev/engines/zEngine/tests/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zengine_run.dir/src/root.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zengine_run.dir/src/root.cpp.o -c /home/darkboss/dev/engines/zEngine/src/root.cpp

CMakeFiles/zengine_run.dir/src/root.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine_run.dir/src/root.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/darkboss/dev/engines/zEngine/src/root.cpp > CMakeFiles/zengine_run.dir/src/root.cpp.i

CMakeFiles/zengine_run.dir/src/root.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine_run.dir/src/root.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/darkboss/dev/engines/zEngine/src/root.cpp -o CMakeFiles/zengine_run.dir/src/root.cpp.s

CMakeFiles/zengine_run.dir/src/root.cpp.o.requires:
.PHONY : CMakeFiles/zengine_run.dir/src/root.cpp.o.requires

CMakeFiles/zengine_run.dir/src/root.cpp.o.provides: CMakeFiles/zengine_run.dir/src/root.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine_run.dir/build.make CMakeFiles/zengine_run.dir/src/root.cpp.o.provides.build
.PHONY : CMakeFiles/zengine_run.dir/src/root.cpp.o.provides

CMakeFiles/zengine_run.dir/src/root.cpp.o.provides.build: CMakeFiles/zengine_run.dir/src/root.cpp.o

CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o: CMakeFiles/zengine_run.dir/flags.make
CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o: ../src/ogre_initialiser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/darkboss/dev/engines/zEngine/tests/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o -c /home/darkboss/dev/engines/zEngine/src/ogre_initialiser.cpp

CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/darkboss/dev/engines/zEngine/src/ogre_initialiser.cpp > CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.i

CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/darkboss/dev/engines/zEngine/src/ogre_initialiser.cpp -o CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.s

CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o.requires:
.PHONY : CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o.requires

CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o.provides: CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o.requires
	$(MAKE) -f CMakeFiles/zengine_run.dir/build.make CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o.provides.build
.PHONY : CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o.provides

CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o.provides.build: CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o

# Object files for target zengine_run
zengine_run_OBJECTS = \
"CMakeFiles/zengine_run.dir/src/main.cpp.o" \
"CMakeFiles/zengine_run.dir/src/state_manager.cpp.o" \
"CMakeFiles/zengine_run.dir/src/platform.cpp.o" \
"CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o" \
"CMakeFiles/zengine_run.dir/src/exception.cpp.o" \
"CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o" \
"CMakeFiles/zengine_run.dir/src/root.cpp.o" \
"CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o"

# External object files for target zengine_run
zengine_run_EXTERNAL_OBJECTS =

bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/src/main.cpp.o
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/src/state_manager.cpp.o
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/src/platform.cpp.o
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/src/exception.cpp.o
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/src/root.cpp.o
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/build.make
bin/DEBUG/zengine_run: CMakeFiles/zengine_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/DEBUG/zengine_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zengine_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zengine_run.dir/build: bin/DEBUG/zengine_run
.PHONY : CMakeFiles/zengine_run.dir/build

CMakeFiles/zengine_run.dir/requires: CMakeFiles/zengine_run.dir/src/main.cpp.o.requires
CMakeFiles/zengine_run.dir/requires: CMakeFiles/zengine_run.dir/src/state_manager.cpp.o.requires
CMakeFiles/zengine_run.dir/requires: CMakeFiles/zengine_run.dir/src/platform.cpp.o.requires
CMakeFiles/zengine_run.dir/requires: CMakeFiles/zengine_run.dir/src/ogre_console.cpp.o.requires
CMakeFiles/zengine_run.dir/requires: CMakeFiles/zengine_run.dir/src/exception.cpp.o.requires
CMakeFiles/zengine_run.dir/requires: CMakeFiles/zengine_run.dir/src/ambiance_manager.cpp.o.requires
CMakeFiles/zengine_run.dir/requires: CMakeFiles/zengine_run.dir/src/root.cpp.o.requires
CMakeFiles/zengine_run.dir/requires: CMakeFiles/zengine_run.dir/src/ogre_initialiser.cpp.o.requires
.PHONY : CMakeFiles/zengine_run.dir/requires

CMakeFiles/zengine_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zengine_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zengine_run.dir/clean

CMakeFiles/zengine_run.dir/depend:
	cd /home/darkboss/dev/engines/zEngine/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darkboss/dev/engines/zEngine /home/darkboss/dev/engines/zEngine /home/darkboss/dev/engines/zEngine/tests /home/darkboss/dev/engines/zEngine/tests /home/darkboss/dev/engines/zEngine/tests/CMakeFiles/zengine_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zengine_run.dir/depend

