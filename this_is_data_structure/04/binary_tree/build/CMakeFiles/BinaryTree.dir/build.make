# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/build

# Include any dependencies generated for this target.
include CMakeFiles/BinaryTree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BinaryTree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BinaryTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BinaryTree.dir/flags.make

CMakeFiles/BinaryTree.dir/codegen:
.PHONY : CMakeFiles/BinaryTree.dir/codegen

CMakeFiles/BinaryTree.dir/main.c.o: CMakeFiles/BinaryTree.dir/flags.make
CMakeFiles/BinaryTree.dir/main.c.o: /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/main.c
CMakeFiles/BinaryTree.dir/main.c.o: CMakeFiles/BinaryTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BinaryTree.dir/main.c.o"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BinaryTree.dir/main.c.o -MF CMakeFiles/BinaryTree.dir/main.c.o.d -o CMakeFiles/BinaryTree.dir/main.c.o -c /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/main.c

CMakeFiles/BinaryTree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BinaryTree.dir/main.c.i"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/main.c > CMakeFiles/BinaryTree.dir/main.c.i

CMakeFiles/BinaryTree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BinaryTree.dir/main.c.s"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/main.c -o CMakeFiles/BinaryTree.dir/main.c.s

# Object files for target BinaryTree
BinaryTree_OBJECTS = \
"CMakeFiles/BinaryTree.dir/main.c.o"

# External object files for target BinaryTree
BinaryTree_EXTERNAL_OBJECTS =

BinaryTree: CMakeFiles/BinaryTree.dir/main.c.o
BinaryTree: CMakeFiles/BinaryTree.dir/build.make
BinaryTree: CMakeFiles/BinaryTree.dir/compiler_depend.ts
BinaryTree: CMakeFiles/BinaryTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BinaryTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BinaryTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BinaryTree.dir/build: BinaryTree
.PHONY : CMakeFiles/BinaryTree.dir/build

CMakeFiles/BinaryTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BinaryTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BinaryTree.dir/clean

CMakeFiles/BinaryTree.dir/depend:
	cd /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/build /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/build /home/deep-purple/work/data_structure/this_is_data_structure/04/binary_tree/build/CMakeFiles/BinaryTree.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/BinaryTree.dir/depend

