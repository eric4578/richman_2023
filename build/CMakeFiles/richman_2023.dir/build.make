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
CMAKE_SOURCE_DIR = /home/lighthouse/richman_2023

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lighthouse/richman_2023/build

# Include any dependencies generated for this target.
include CMakeFiles/richman_2023.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/richman_2023.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/richman_2023.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/richman_2023.dir/flags.make

CMakeFiles/richman_2023.dir/main.c.o: CMakeFiles/richman_2023.dir/flags.make
CMakeFiles/richman_2023.dir/main.c.o: ../main.c
CMakeFiles/richman_2023.dir/main.c.o: CMakeFiles/richman_2023.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/richman_2023.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/richman_2023.dir/main.c.o -MF CMakeFiles/richman_2023.dir/main.c.o.d -o CMakeFiles/richman_2023.dir/main.c.o -c /home/lighthouse/richman_2023/main.c

CMakeFiles/richman_2023.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/richman_2023.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lighthouse/richman_2023/main.c > CMakeFiles/richman_2023.dir/main.c.i

CMakeFiles/richman_2023.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/richman_2023.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lighthouse/richman_2023/main.c -o CMakeFiles/richman_2023.dir/main.c.s

CMakeFiles/richman_2023.dir/src/Player.c.o: CMakeFiles/richman_2023.dir/flags.make
CMakeFiles/richman_2023.dir/src/Player.c.o: ../src/Player.c
CMakeFiles/richman_2023.dir/src/Player.c.o: CMakeFiles/richman_2023.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/richman_2023.dir/src/Player.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/richman_2023.dir/src/Player.c.o -MF CMakeFiles/richman_2023.dir/src/Player.c.o.d -o CMakeFiles/richman_2023.dir/src/Player.c.o -c /home/lighthouse/richman_2023/src/Player.c

CMakeFiles/richman_2023.dir/src/Player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/richman_2023.dir/src/Player.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lighthouse/richman_2023/src/Player.c > CMakeFiles/richman_2023.dir/src/Player.c.i

CMakeFiles/richman_2023.dir/src/Player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/richman_2023.dir/src/Player.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lighthouse/richman_2023/src/Player.c -o CMakeFiles/richman_2023.dir/src/Player.c.s

CMakeFiles/richman_2023.dir/src/func.c.o: CMakeFiles/richman_2023.dir/flags.make
CMakeFiles/richman_2023.dir/src/func.c.o: ../src/func.c
CMakeFiles/richman_2023.dir/src/func.c.o: CMakeFiles/richman_2023.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/richman_2023.dir/src/func.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/richman_2023.dir/src/func.c.o -MF CMakeFiles/richman_2023.dir/src/func.c.o.d -o CMakeFiles/richman_2023.dir/src/func.c.o -c /home/lighthouse/richman_2023/src/func.c

CMakeFiles/richman_2023.dir/src/func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/richman_2023.dir/src/func.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lighthouse/richman_2023/src/func.c > CMakeFiles/richman_2023.dir/src/func.c.i

CMakeFiles/richman_2023.dir/src/func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/richman_2023.dir/src/func.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lighthouse/richman_2023/src/func.c -o CMakeFiles/richman_2023.dir/src/func.c.s

CMakeFiles/richman_2023.dir/src/map.c.o: CMakeFiles/richman_2023.dir/flags.make
CMakeFiles/richman_2023.dir/src/map.c.o: ../src/map.c
CMakeFiles/richman_2023.dir/src/map.c.o: CMakeFiles/richman_2023.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/richman_2023.dir/src/map.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/richman_2023.dir/src/map.c.o -MF CMakeFiles/richman_2023.dir/src/map.c.o.d -o CMakeFiles/richman_2023.dir/src/map.c.o -c /home/lighthouse/richman_2023/src/map.c

CMakeFiles/richman_2023.dir/src/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/richman_2023.dir/src/map.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lighthouse/richman_2023/src/map.c > CMakeFiles/richman_2023.dir/src/map.c.i

CMakeFiles/richman_2023.dir/src/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/richman_2023.dir/src/map.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lighthouse/richman_2023/src/map.c -o CMakeFiles/richman_2023.dir/src/map.c.s

CMakeFiles/richman_2023.dir/src/start.c.o: CMakeFiles/richman_2023.dir/flags.make
CMakeFiles/richman_2023.dir/src/start.c.o: ../src/start.c
CMakeFiles/richman_2023.dir/src/start.c.o: CMakeFiles/richman_2023.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/richman_2023.dir/src/start.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/richman_2023.dir/src/start.c.o -MF CMakeFiles/richman_2023.dir/src/start.c.o.d -o CMakeFiles/richman_2023.dir/src/start.c.o -c /home/lighthouse/richman_2023/src/start.c

CMakeFiles/richman_2023.dir/src/start.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/richman_2023.dir/src/start.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lighthouse/richman_2023/src/start.c > CMakeFiles/richman_2023.dir/src/start.c.i

CMakeFiles/richman_2023.dir/src/start.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/richman_2023.dir/src/start.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lighthouse/richman_2023/src/start.c -o CMakeFiles/richman_2023.dir/src/start.c.s

CMakeFiles/richman_2023.dir/src/test.c.o: CMakeFiles/richman_2023.dir/flags.make
CMakeFiles/richman_2023.dir/src/test.c.o: ../src/test.c
CMakeFiles/richman_2023.dir/src/test.c.o: CMakeFiles/richman_2023.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/richman_2023.dir/src/test.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/richman_2023.dir/src/test.c.o -MF CMakeFiles/richman_2023.dir/src/test.c.o.d -o CMakeFiles/richman_2023.dir/src/test.c.o -c /home/lighthouse/richman_2023/src/test.c

CMakeFiles/richman_2023.dir/src/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/richman_2023.dir/src/test.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lighthouse/richman_2023/src/test.c > CMakeFiles/richman_2023.dir/src/test.c.i

CMakeFiles/richman_2023.dir/src/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/richman_2023.dir/src/test.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lighthouse/richman_2023/src/test.c -o CMakeFiles/richman_2023.dir/src/test.c.s

CMakeFiles/richman_2023.dir/src/tool.c.o: CMakeFiles/richman_2023.dir/flags.make
CMakeFiles/richman_2023.dir/src/tool.c.o: ../src/tool.c
CMakeFiles/richman_2023.dir/src/tool.c.o: CMakeFiles/richman_2023.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/richman_2023.dir/src/tool.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/richman_2023.dir/src/tool.c.o -MF CMakeFiles/richman_2023.dir/src/tool.c.o.d -o CMakeFiles/richman_2023.dir/src/tool.c.o -c /home/lighthouse/richman_2023/src/tool.c

CMakeFiles/richman_2023.dir/src/tool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/richman_2023.dir/src/tool.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lighthouse/richman_2023/src/tool.c > CMakeFiles/richman_2023.dir/src/tool.c.i

CMakeFiles/richman_2023.dir/src/tool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/richman_2023.dir/src/tool.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lighthouse/richman_2023/src/tool.c -o CMakeFiles/richman_2023.dir/src/tool.c.s

CMakeFiles/richman_2023.dir/src/update.c.o: CMakeFiles/richman_2023.dir/flags.make
CMakeFiles/richman_2023.dir/src/update.c.o: ../src/update.c
CMakeFiles/richman_2023.dir/src/update.c.o: CMakeFiles/richman_2023.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/richman_2023.dir/src/update.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/richman_2023.dir/src/update.c.o -MF CMakeFiles/richman_2023.dir/src/update.c.o.d -o CMakeFiles/richman_2023.dir/src/update.c.o -c /home/lighthouse/richman_2023/src/update.c

CMakeFiles/richman_2023.dir/src/update.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/richman_2023.dir/src/update.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lighthouse/richman_2023/src/update.c > CMakeFiles/richman_2023.dir/src/update.c.i

CMakeFiles/richman_2023.dir/src/update.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/richman_2023.dir/src/update.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lighthouse/richman_2023/src/update.c -o CMakeFiles/richman_2023.dir/src/update.c.s

# Object files for target richman_2023
richman_2023_OBJECTS = \
"CMakeFiles/richman_2023.dir/main.c.o" \
"CMakeFiles/richman_2023.dir/src/Player.c.o" \
"CMakeFiles/richman_2023.dir/src/func.c.o" \
"CMakeFiles/richman_2023.dir/src/map.c.o" \
"CMakeFiles/richman_2023.dir/src/start.c.o" \
"CMakeFiles/richman_2023.dir/src/test.c.o" \
"CMakeFiles/richman_2023.dir/src/tool.c.o" \
"CMakeFiles/richman_2023.dir/src/update.c.o"

# External object files for target richman_2023
richman_2023_EXTERNAL_OBJECTS =

../bin/richman_2023: CMakeFiles/richman_2023.dir/main.c.o
../bin/richman_2023: CMakeFiles/richman_2023.dir/src/Player.c.o
../bin/richman_2023: CMakeFiles/richman_2023.dir/src/func.c.o
../bin/richman_2023: CMakeFiles/richman_2023.dir/src/map.c.o
../bin/richman_2023: CMakeFiles/richman_2023.dir/src/start.c.o
../bin/richman_2023: CMakeFiles/richman_2023.dir/src/test.c.o
../bin/richman_2023: CMakeFiles/richman_2023.dir/src/tool.c.o
../bin/richman_2023: CMakeFiles/richman_2023.dir/src/update.c.o
../bin/richman_2023: CMakeFiles/richman_2023.dir/build.make
../bin/richman_2023: CMakeFiles/richman_2023.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lighthouse/richman_2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable ../bin/richman_2023"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/richman_2023.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/richman_2023.dir/build: ../bin/richman_2023
.PHONY : CMakeFiles/richman_2023.dir/build

CMakeFiles/richman_2023.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/richman_2023.dir/cmake_clean.cmake
.PHONY : CMakeFiles/richman_2023.dir/clean

CMakeFiles/richman_2023.dir/depend:
	cd /home/lighthouse/richman_2023/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lighthouse/richman_2023 /home/lighthouse/richman_2023 /home/lighthouse/richman_2023/build /home/lighthouse/richman_2023/build /home/lighthouse/richman_2023/build/CMakeFiles/richman_2023.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/richman_2023.dir/depend
