# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sparklab/SuRF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sparklab/SuRF/build

# Include any dependencies generated for this target.
include test/unitTest/CMakeFiles/test_surf_small.dir/depend.make

# Include the progress variables for this target.
include test/unitTest/CMakeFiles/test_surf_small.dir/progress.make

# Include the compile flags for this target's objects.
include test/unitTest/CMakeFiles/test_surf_small.dir/flags.make

test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o: test/unitTest/CMakeFiles/test_surf_small.dir/flags.make
test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o: ../test/unitTest/test_surf_small.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sparklab/SuRF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o"
	cd /home/sparklab/SuRF/build/test/unitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o -c /home/sparklab/SuRF/test/unitTest/test_surf_small.cpp

test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_surf_small.dir/test_surf_small.cpp.i"
	cd /home/sparklab/SuRF/build/test/unitTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sparklab/SuRF/test/unitTest/test_surf_small.cpp > CMakeFiles/test_surf_small.dir/test_surf_small.cpp.i

test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_surf_small.dir/test_surf_small.cpp.s"
	cd /home/sparklab/SuRF/build/test/unitTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sparklab/SuRF/test/unitTest/test_surf_small.cpp -o CMakeFiles/test_surf_small.dir/test_surf_small.cpp.s

test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o.requires:

.PHONY : test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o.requires

test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o.provides: test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o.requires
	$(MAKE) -f test/unitTest/CMakeFiles/test_surf_small.dir/build.make test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o.provides.build
.PHONY : test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o.provides

test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o.provides.build: test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o


# Object files for target test_surf_small
test_surf_small_OBJECTS = \
"CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o"

# External object files for target test_surf_small
test_surf_small_EXTERNAL_OBJECTS =

test/unitTest/test_surf_small: test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o
test/unitTest/test_surf_small: test/unitTest/CMakeFiles/test_surf_small.dir/build.make
test/unitTest/test_surf_small: test/unitTest/CMakeFiles/test_surf_small.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sparklab/SuRF/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_surf_small"
	cd /home/sparklab/SuRF/build/test/unitTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_surf_small.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unitTest/CMakeFiles/test_surf_small.dir/build: test/unitTest/test_surf_small

.PHONY : test/unitTest/CMakeFiles/test_surf_small.dir/build

test/unitTest/CMakeFiles/test_surf_small.dir/requires: test/unitTest/CMakeFiles/test_surf_small.dir/test_surf_small.cpp.o.requires

.PHONY : test/unitTest/CMakeFiles/test_surf_small.dir/requires

test/unitTest/CMakeFiles/test_surf_small.dir/clean:
	cd /home/sparklab/SuRF/build/test/unitTest && $(CMAKE_COMMAND) -P CMakeFiles/test_surf_small.dir/cmake_clean.cmake
.PHONY : test/unitTest/CMakeFiles/test_surf_small.dir/clean

test/unitTest/CMakeFiles/test_surf_small.dir/depend:
	cd /home/sparklab/SuRF/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sparklab/SuRF /home/sparklab/SuRF/test/unitTest /home/sparklab/SuRF/build /home/sparklab/SuRF/build/test/unitTest /home/sparklab/SuRF/build/test/unitTest/CMakeFiles/test_surf_small.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unitTest/CMakeFiles/test_surf_small.dir/depend
