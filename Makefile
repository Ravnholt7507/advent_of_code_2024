# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /home/andreas/.local/lib/python3.12/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/andreas/.local/lib/python3.12/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andreas/projects/advent_of_code_2024

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andreas/projects/advent_of_code_2024

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/home/andreas/.local/lib/python3.12/site-packages/cmake/data/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/home/andreas/.local/lib/python3.12/site-packages/cmake/data/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/andreas/projects/advent_of_code_2024/CMakeFiles /home/andreas/projects/advent_of_code_2024//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/andreas/projects/advent_of_code_2024/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named output

# Build rule for target.
output: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 output
.PHONY : output

# fast build rule for target.
output/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/build
.PHONY : output/fast

10December/solution.o: 10December/solution.cpp.o
.PHONY : 10December/solution.o

# target to build an object file
10December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/10December/solution.cpp.o
.PHONY : 10December/solution.cpp.o

10December/solution.i: 10December/solution.cpp.i
.PHONY : 10December/solution.i

# target to preprocess a source file
10December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/10December/solution.cpp.i
.PHONY : 10December/solution.cpp.i

10December/solution.s: 10December/solution.cpp.s
.PHONY : 10December/solution.s

# target to generate assembly for a file
10December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/10December/solution.cpp.s
.PHONY : 10December/solution.cpp.s

11December/solution.o: 11December/solution.cpp.o
.PHONY : 11December/solution.o

# target to build an object file
11December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/11December/solution.cpp.o
.PHONY : 11December/solution.cpp.o

11December/solution.i: 11December/solution.cpp.i
.PHONY : 11December/solution.i

# target to preprocess a source file
11December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/11December/solution.cpp.i
.PHONY : 11December/solution.cpp.i

11December/solution.s: 11December/solution.cpp.s
.PHONY : 11December/solution.s

# target to generate assembly for a file
11December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/11December/solution.cpp.s
.PHONY : 11December/solution.cpp.s

1December/solution.o: 1December/solution.cpp.o
.PHONY : 1December/solution.o

# target to build an object file
1December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/1December/solution.cpp.o
.PHONY : 1December/solution.cpp.o

1December/solution.i: 1December/solution.cpp.i
.PHONY : 1December/solution.i

# target to preprocess a source file
1December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/1December/solution.cpp.i
.PHONY : 1December/solution.cpp.i

1December/solution.s: 1December/solution.cpp.s
.PHONY : 1December/solution.s

# target to generate assembly for a file
1December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/1December/solution.cpp.s
.PHONY : 1December/solution.cpp.s

2December/solution.o: 2December/solution.cpp.o
.PHONY : 2December/solution.o

# target to build an object file
2December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/2December/solution.cpp.o
.PHONY : 2December/solution.cpp.o

2December/solution.i: 2December/solution.cpp.i
.PHONY : 2December/solution.i

# target to preprocess a source file
2December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/2December/solution.cpp.i
.PHONY : 2December/solution.cpp.i

2December/solution.s: 2December/solution.cpp.s
.PHONY : 2December/solution.s

# target to generate assembly for a file
2December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/2December/solution.cpp.s
.PHONY : 2December/solution.cpp.s

3December/solution.o: 3December/solution.cpp.o
.PHONY : 3December/solution.o

# target to build an object file
3December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/3December/solution.cpp.o
.PHONY : 3December/solution.cpp.o

3December/solution.i: 3December/solution.cpp.i
.PHONY : 3December/solution.i

# target to preprocess a source file
3December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/3December/solution.cpp.i
.PHONY : 3December/solution.cpp.i

3December/solution.s: 3December/solution.cpp.s
.PHONY : 3December/solution.s

# target to generate assembly for a file
3December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/3December/solution.cpp.s
.PHONY : 3December/solution.cpp.s

4December/solution.o: 4December/solution.cpp.o
.PHONY : 4December/solution.o

# target to build an object file
4December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/4December/solution.cpp.o
.PHONY : 4December/solution.cpp.o

4December/solution.i: 4December/solution.cpp.i
.PHONY : 4December/solution.i

# target to preprocess a source file
4December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/4December/solution.cpp.i
.PHONY : 4December/solution.cpp.i

4December/solution.s: 4December/solution.cpp.s
.PHONY : 4December/solution.s

# target to generate assembly for a file
4December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/4December/solution.cpp.s
.PHONY : 4December/solution.cpp.s

5December/solution.o: 5December/solution.cpp.o
.PHONY : 5December/solution.o

# target to build an object file
5December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/5December/solution.cpp.o
.PHONY : 5December/solution.cpp.o

5December/solution.i: 5December/solution.cpp.i
.PHONY : 5December/solution.i

# target to preprocess a source file
5December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/5December/solution.cpp.i
.PHONY : 5December/solution.cpp.i

5December/solution.s: 5December/solution.cpp.s
.PHONY : 5December/solution.s

# target to generate assembly for a file
5December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/5December/solution.cpp.s
.PHONY : 5December/solution.cpp.s

6December/solution.o: 6December/solution.cpp.o
.PHONY : 6December/solution.o

# target to build an object file
6December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/6December/solution.cpp.o
.PHONY : 6December/solution.cpp.o

6December/solution.i: 6December/solution.cpp.i
.PHONY : 6December/solution.i

# target to preprocess a source file
6December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/6December/solution.cpp.i
.PHONY : 6December/solution.cpp.i

6December/solution.s: 6December/solution.cpp.s
.PHONY : 6December/solution.s

# target to generate assembly for a file
6December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/6December/solution.cpp.s
.PHONY : 6December/solution.cpp.s

7December/solution.o: 7December/solution.cpp.o
.PHONY : 7December/solution.o

# target to build an object file
7December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/7December/solution.cpp.o
.PHONY : 7December/solution.cpp.o

7December/solution.i: 7December/solution.cpp.i
.PHONY : 7December/solution.i

# target to preprocess a source file
7December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/7December/solution.cpp.i
.PHONY : 7December/solution.cpp.i

7December/solution.s: 7December/solution.cpp.s
.PHONY : 7December/solution.s

# target to generate assembly for a file
7December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/7December/solution.cpp.s
.PHONY : 7December/solution.cpp.s

8December/solution.o: 8December/solution.cpp.o
.PHONY : 8December/solution.o

# target to build an object file
8December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/8December/solution.cpp.o
.PHONY : 8December/solution.cpp.o

8December/solution.i: 8December/solution.cpp.i
.PHONY : 8December/solution.i

# target to preprocess a source file
8December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/8December/solution.cpp.i
.PHONY : 8December/solution.cpp.i

8December/solution.s: 8December/solution.cpp.s
.PHONY : 8December/solution.s

# target to generate assembly for a file
8December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/8December/solution.cpp.s
.PHONY : 8December/solution.cpp.s

9December/solution.o: 9December/solution.cpp.o
.PHONY : 9December/solution.o

# target to build an object file
9December/solution.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/9December/solution.cpp.o
.PHONY : 9December/solution.cpp.o

9December/solution.i: 9December/solution.cpp.i
.PHONY : 9December/solution.i

# target to preprocess a source file
9December/solution.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/9December/solution.cpp.i
.PHONY : 9December/solution.cpp.i

9December/solution.s: 9December/solution.cpp.s
.PHONY : 9December/solution.s

# target to generate assembly for a file
9December/solution.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/9December/solution.cpp.s
.PHONY : 9December/solution.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/output.dir/build.make CMakeFiles/output.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... output"
	@echo "... 10December/solution.o"
	@echo "... 10December/solution.i"
	@echo "... 10December/solution.s"
	@echo "... 11December/solution.o"
	@echo "... 11December/solution.i"
	@echo "... 11December/solution.s"
	@echo "... 1December/solution.o"
	@echo "... 1December/solution.i"
	@echo "... 1December/solution.s"
	@echo "... 2December/solution.o"
	@echo "... 2December/solution.i"
	@echo "... 2December/solution.s"
	@echo "... 3December/solution.o"
	@echo "... 3December/solution.i"
	@echo "... 3December/solution.s"
	@echo "... 4December/solution.o"
	@echo "... 4December/solution.i"
	@echo "... 4December/solution.s"
	@echo "... 5December/solution.o"
	@echo "... 5December/solution.i"
	@echo "... 5December/solution.s"
	@echo "... 6December/solution.o"
	@echo "... 6December/solution.i"
	@echo "... 6December/solution.s"
	@echo "... 7December/solution.o"
	@echo "... 7December/solution.i"
	@echo "... 7December/solution.s"
	@echo "... 8December/solution.o"
	@echo "... 8December/solution.i"
	@echo "... 8December/solution.s"
	@echo "... 9December/solution.o"
	@echo "... 9December/solution.i"
	@echo "... 9December/solution.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

