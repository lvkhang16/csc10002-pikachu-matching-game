# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lvkha\Desktop\pikachu-matching-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lvkha\Desktop\pikachu-matching-game\build

# Include any dependencies generated for this target.
include CMakeFiles/pikachu.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pikachu.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pikachu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pikachu.dir/flags.make

CMakeFiles/pikachu.dir/codegen:
.PHONY : CMakeFiles/pikachu.dir/codegen

CMakeFiles/pikachu.dir/src/cell.cpp.obj: CMakeFiles/pikachu.dir/flags.make
CMakeFiles/pikachu.dir/src/cell.cpp.obj: CMakeFiles/pikachu.dir/includes_CXX.rsp
CMakeFiles/pikachu.dir/src/cell.cpp.obj: C:/Users/lvkha/Desktop/pikachu-matching-game/src/cell.cpp
CMakeFiles/pikachu.dir/src/cell.cpp.obj: CMakeFiles/pikachu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lvkha\Desktop\pikachu-matching-game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pikachu.dir/src/cell.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pikachu.dir/src/cell.cpp.obj -MF CMakeFiles\pikachu.dir\src\cell.cpp.obj.d -o CMakeFiles\pikachu.dir\src\cell.cpp.obj -c C:\Users\lvkha\Desktop\pikachu-matching-game\src\cell.cpp

CMakeFiles/pikachu.dir/src/cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pikachu.dir/src/cell.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lvkha\Desktop\pikachu-matching-game\src\cell.cpp > CMakeFiles\pikachu.dir\src\cell.cpp.i

CMakeFiles/pikachu.dir/src/cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pikachu.dir/src/cell.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lvkha\Desktop\pikachu-matching-game\src\cell.cpp -o CMakeFiles\pikachu.dir\src\cell.cpp.s

CMakeFiles/pikachu.dir/src/main.cpp.obj: CMakeFiles/pikachu.dir/flags.make
CMakeFiles/pikachu.dir/src/main.cpp.obj: CMakeFiles/pikachu.dir/includes_CXX.rsp
CMakeFiles/pikachu.dir/src/main.cpp.obj: C:/Users/lvkha/Desktop/pikachu-matching-game/src/main.cpp
CMakeFiles/pikachu.dir/src/main.cpp.obj: CMakeFiles/pikachu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lvkha\Desktop\pikachu-matching-game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pikachu.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pikachu.dir/src/main.cpp.obj -MF CMakeFiles\pikachu.dir\src\main.cpp.obj.d -o CMakeFiles\pikachu.dir\src\main.cpp.obj -c C:\Users\lvkha\Desktop\pikachu-matching-game\src\main.cpp

CMakeFiles/pikachu.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pikachu.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lvkha\Desktop\pikachu-matching-game\src\main.cpp > CMakeFiles\pikachu.dir\src\main.cpp.i

CMakeFiles/pikachu.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pikachu.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lvkha\Desktop\pikachu-matching-game\src\main.cpp -o CMakeFiles\pikachu.dir\src\main.cpp.s

CMakeFiles/pikachu.dir/src/menuAndControl.cpp.obj: CMakeFiles/pikachu.dir/flags.make
CMakeFiles/pikachu.dir/src/menuAndControl.cpp.obj: CMakeFiles/pikachu.dir/includes_CXX.rsp
CMakeFiles/pikachu.dir/src/menuAndControl.cpp.obj: C:/Users/lvkha/Desktop/pikachu-matching-game/src/menuAndControl.cpp
CMakeFiles/pikachu.dir/src/menuAndControl.cpp.obj: CMakeFiles/pikachu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lvkha\Desktop\pikachu-matching-game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pikachu.dir/src/menuAndControl.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pikachu.dir/src/menuAndControl.cpp.obj -MF CMakeFiles\pikachu.dir\src\menuAndControl.cpp.obj.d -o CMakeFiles\pikachu.dir\src\menuAndControl.cpp.obj -c C:\Users\lvkha\Desktop\pikachu-matching-game\src\menuAndControl.cpp

CMakeFiles/pikachu.dir/src/menuAndControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pikachu.dir/src/menuAndControl.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lvkha\Desktop\pikachu-matching-game\src\menuAndControl.cpp > CMakeFiles\pikachu.dir\src\menuAndControl.cpp.i

CMakeFiles/pikachu.dir/src/menuAndControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pikachu.dir/src/menuAndControl.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lvkha\Desktop\pikachu-matching-game\src\menuAndControl.cpp -o CMakeFiles\pikachu.dir\src\menuAndControl.cpp.s

CMakeFiles/pikachu.dir/src/normalGame.cpp.obj: CMakeFiles/pikachu.dir/flags.make
CMakeFiles/pikachu.dir/src/normalGame.cpp.obj: CMakeFiles/pikachu.dir/includes_CXX.rsp
CMakeFiles/pikachu.dir/src/normalGame.cpp.obj: C:/Users/lvkha/Desktop/pikachu-matching-game/src/normalGame.cpp
CMakeFiles/pikachu.dir/src/normalGame.cpp.obj: CMakeFiles/pikachu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lvkha\Desktop\pikachu-matching-game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pikachu.dir/src/normalGame.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pikachu.dir/src/normalGame.cpp.obj -MF CMakeFiles\pikachu.dir\src\normalGame.cpp.obj.d -o CMakeFiles\pikachu.dir\src\normalGame.cpp.obj -c C:\Users\lvkha\Desktop\pikachu-matching-game\src\normalGame.cpp

CMakeFiles/pikachu.dir/src/normalGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pikachu.dir/src/normalGame.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lvkha\Desktop\pikachu-matching-game\src\normalGame.cpp > CMakeFiles\pikachu.dir\src\normalGame.cpp.i

CMakeFiles/pikachu.dir/src/normalGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pikachu.dir/src/normalGame.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lvkha\Desktop\pikachu-matching-game\src\normalGame.cpp -o CMakeFiles\pikachu.dir\src\normalGame.cpp.s

CMakeFiles/pikachu.dir/src/slidingGame.cpp.obj: CMakeFiles/pikachu.dir/flags.make
CMakeFiles/pikachu.dir/src/slidingGame.cpp.obj: CMakeFiles/pikachu.dir/includes_CXX.rsp
CMakeFiles/pikachu.dir/src/slidingGame.cpp.obj: C:/Users/lvkha/Desktop/pikachu-matching-game/src/slidingGame.cpp
CMakeFiles/pikachu.dir/src/slidingGame.cpp.obj: CMakeFiles/pikachu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lvkha\Desktop\pikachu-matching-game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pikachu.dir/src/slidingGame.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pikachu.dir/src/slidingGame.cpp.obj -MF CMakeFiles\pikachu.dir\src\slidingGame.cpp.obj.d -o CMakeFiles\pikachu.dir\src\slidingGame.cpp.obj -c C:\Users\lvkha\Desktop\pikachu-matching-game\src\slidingGame.cpp

CMakeFiles/pikachu.dir/src/slidingGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pikachu.dir/src/slidingGame.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lvkha\Desktop\pikachu-matching-game\src\slidingGame.cpp > CMakeFiles\pikachu.dir\src\slidingGame.cpp.i

CMakeFiles/pikachu.dir/src/slidingGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pikachu.dir/src/slidingGame.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lvkha\Desktop\pikachu-matching-game\src\slidingGame.cpp -o CMakeFiles\pikachu.dir\src\slidingGame.cpp.s

CMakeFiles/pikachu.dir/src/utility.cpp.obj: CMakeFiles/pikachu.dir/flags.make
CMakeFiles/pikachu.dir/src/utility.cpp.obj: CMakeFiles/pikachu.dir/includes_CXX.rsp
CMakeFiles/pikachu.dir/src/utility.cpp.obj: C:/Users/lvkha/Desktop/pikachu-matching-game/src/utility.cpp
CMakeFiles/pikachu.dir/src/utility.cpp.obj: CMakeFiles/pikachu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lvkha\Desktop\pikachu-matching-game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pikachu.dir/src/utility.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pikachu.dir/src/utility.cpp.obj -MF CMakeFiles\pikachu.dir\src\utility.cpp.obj.d -o CMakeFiles\pikachu.dir\src\utility.cpp.obj -c C:\Users\lvkha\Desktop\pikachu-matching-game\src\utility.cpp

CMakeFiles/pikachu.dir/src/utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pikachu.dir/src/utility.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lvkha\Desktop\pikachu-matching-game\src\utility.cpp > CMakeFiles\pikachu.dir\src\utility.cpp.i

CMakeFiles/pikachu.dir/src/utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pikachu.dir/src/utility.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lvkha\Desktop\pikachu-matching-game\src\utility.cpp -o CMakeFiles\pikachu.dir\src\utility.cpp.s

# Object files for target pikachu
pikachu_OBJECTS = \
"CMakeFiles/pikachu.dir/src/cell.cpp.obj" \
"CMakeFiles/pikachu.dir/src/main.cpp.obj" \
"CMakeFiles/pikachu.dir/src/menuAndControl.cpp.obj" \
"CMakeFiles/pikachu.dir/src/normalGame.cpp.obj" \
"CMakeFiles/pikachu.dir/src/slidingGame.cpp.obj" \
"CMakeFiles/pikachu.dir/src/utility.cpp.obj"

# External object files for target pikachu
pikachu_EXTERNAL_OBJECTS =

Debug/pikachu.exe: CMakeFiles/pikachu.dir/src/cell.cpp.obj
Debug/pikachu.exe: CMakeFiles/pikachu.dir/src/main.cpp.obj
Debug/pikachu.exe: CMakeFiles/pikachu.dir/src/menuAndControl.cpp.obj
Debug/pikachu.exe: CMakeFiles/pikachu.dir/src/normalGame.cpp.obj
Debug/pikachu.exe: CMakeFiles/pikachu.dir/src/slidingGame.cpp.obj
Debug/pikachu.exe: CMakeFiles/pikachu.dir/src/utility.cpp.obj
Debug/pikachu.exe: CMakeFiles/pikachu.dir/build.make
Debug/pikachu.exe: CMakeFiles/pikachu.dir/linkLibs.rsp
Debug/pikachu.exe: CMakeFiles/pikachu.dir/objects1.rsp
Debug/pikachu.exe: CMakeFiles/pikachu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\lvkha\Desktop\pikachu-matching-game\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Debug\pikachu.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pikachu.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pikachu.dir/build: Debug/pikachu.exe
.PHONY : CMakeFiles/pikachu.dir/build

CMakeFiles/pikachu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pikachu.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pikachu.dir/clean

CMakeFiles/pikachu.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lvkha\Desktop\pikachu-matching-game C:\Users\lvkha\Desktop\pikachu-matching-game C:\Users\lvkha\Desktop\pikachu-matching-game\build C:\Users\lvkha\Desktop\pikachu-matching-game\build C:\Users\lvkha\Desktop\pikachu-matching-game\build\CMakeFiles\pikachu.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pikachu.dir/depend
