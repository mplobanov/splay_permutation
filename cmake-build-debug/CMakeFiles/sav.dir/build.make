# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mplobanov/CLionProjects/splay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mplobanov/CLionProjects/splay/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sav.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sav.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sav.dir/flags.make

CMakeFiles/sav.dir/sol.cpp.o: CMakeFiles/sav.dir/flags.make
CMakeFiles/sav.dir/sol.cpp.o: ../sol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mplobanov/CLionProjects/splay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sav.dir/sol.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sav.dir/sol.cpp.o -c /Users/mplobanov/CLionProjects/splay/sol.cpp

CMakeFiles/sav.dir/sol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sav.dir/sol.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mplobanov/CLionProjects/splay/sol.cpp > CMakeFiles/sav.dir/sol.cpp.i

CMakeFiles/sav.dir/sol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sav.dir/sol.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mplobanov/CLionProjects/splay/sol.cpp -o CMakeFiles/sav.dir/sol.cpp.s

# Object files for target sav
sav_OBJECTS = \
"CMakeFiles/sav.dir/sol.cpp.o"

# External object files for target sav
sav_EXTERNAL_OBJECTS =

sav: CMakeFiles/sav.dir/sol.cpp.o
sav: CMakeFiles/sav.dir/build.make
sav: CMakeFiles/sav.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mplobanov/CLionProjects/splay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sav"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sav.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sav.dir/build: sav

.PHONY : CMakeFiles/sav.dir/build

CMakeFiles/sav.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sav.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sav.dir/clean

CMakeFiles/sav.dir/depend:
	cd /Users/mplobanov/CLionProjects/splay/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mplobanov/CLionProjects/splay /Users/mplobanov/CLionProjects/splay /Users/mplobanov/CLionProjects/splay/cmake-build-debug /Users/mplobanov/CLionProjects/splay/cmake-build-debug /Users/mplobanov/CLionProjects/splay/cmake-build-debug/CMakeFiles/sav.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sav.dir/depend

