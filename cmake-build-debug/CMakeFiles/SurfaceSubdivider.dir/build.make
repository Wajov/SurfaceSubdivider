# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wajov/Projects/SurfaceSubdivider

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wajov/Projects/SurfaceSubdivider/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SurfaceSubdivider.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SurfaceSubdivider.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SurfaceSubdivider.dir/flags.make

CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.o: CMakeFiles/SurfaceSubdivider.dir/flags.make
CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.o: SurfaceSubdivider_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.o -c /home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/SurfaceSubdivider_autogen/mocs_compilation.cpp

CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/SurfaceSubdivider_autogen/mocs_compilation.cpp > CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.i

CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/SurfaceSubdivider_autogen/mocs_compilation.cpp -o CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.s

CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.o: CMakeFiles/SurfaceSubdivider.dir/flags.make
CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.o: ../src/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.o -c /home/wajov/Projects/SurfaceSubdivider/src/Mesh.cpp

CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wajov/Projects/SurfaceSubdivider/src/Mesh.cpp > CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.i

CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wajov/Projects/SurfaceSubdivider/src/Mesh.cpp -o CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.s

CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.o: CMakeFiles/SurfaceSubdivider.dir/flags.make
CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.o: ../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.o -c /home/wajov/Projects/SurfaceSubdivider/src/Model.cpp

CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wajov/Projects/SurfaceSubdivider/src/Model.cpp > CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.i

CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wajov/Projects/SurfaceSubdivider/src/Model.cpp -o CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.s

CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.o: CMakeFiles/SurfaceSubdivider.dir/flags.make
CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.o: ../src/RenderWidget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.o -c /home/wajov/Projects/SurfaceSubdivider/src/RenderWidget.cpp

CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wajov/Projects/SurfaceSubdivider/src/RenderWidget.cpp > CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.i

CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wajov/Projects/SurfaceSubdivider/src/RenderWidget.cpp -o CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.s

CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.o: CMakeFiles/SurfaceSubdivider.dir/flags.make
CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.o: ../src/RenderWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.o -c /home/wajov/Projects/SurfaceSubdivider/src/RenderWindow.cpp

CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wajov/Projects/SurfaceSubdivider/src/RenderWindow.cpp > CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.i

CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wajov/Projects/SurfaceSubdivider/src/RenderWindow.cpp -o CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.s

CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.o: CMakeFiles/SurfaceSubdivider.dir/flags.make
CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.o: ../src/Vertex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.o -c /home/wajov/Projects/SurfaceSubdivider/src/Vertex.cpp

CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wajov/Projects/SurfaceSubdivider/src/Vertex.cpp > CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.i

CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wajov/Projects/SurfaceSubdivider/src/Vertex.cpp -o CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.s

CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.o: CMakeFiles/SurfaceSubdivider.dir/flags.make
CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.o -c /home/wajov/Projects/SurfaceSubdivider/src/main.cpp

CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wajov/Projects/SurfaceSubdivider/src/main.cpp > CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.i

CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wajov/Projects/SurfaceSubdivider/src/main.cpp -o CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.s

# Object files for target SurfaceSubdivider
SurfaceSubdivider_OBJECTS = \
"CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.o" \
"CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.o" \
"CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.o" \
"CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.o" \
"CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.o" \
"CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.o"

# External object files for target SurfaceSubdivider
SurfaceSubdivider_EXTERNAL_OBJECTS =

SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/SurfaceSubdivider_autogen/mocs_compilation.cpp.o
SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/src/Mesh.cpp.o
SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/src/Model.cpp.o
SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/src/RenderWidget.cpp.o
SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/src/RenderWindow.cpp.o
SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/src/Vertex.cpp.o
SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/src/main.cpp.o
SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/build.make
SurfaceSubdivider: /usr/lib/libQt5Widgets.so.5.15.2
SurfaceSubdivider: /usr/lib/libQt5Gui.so.5.15.2
SurfaceSubdivider: /usr/lib/libQt5Core.so.5.15.2
SurfaceSubdivider: CMakeFiles/SurfaceSubdivider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable SurfaceSubdivider"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SurfaceSubdivider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SurfaceSubdivider.dir/build: SurfaceSubdivider

.PHONY : CMakeFiles/SurfaceSubdivider.dir/build

CMakeFiles/SurfaceSubdivider.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SurfaceSubdivider.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SurfaceSubdivider.dir/clean

CMakeFiles/SurfaceSubdivider.dir/depend:
	cd /home/wajov/Projects/SurfaceSubdivider/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wajov/Projects/SurfaceSubdivider /home/wajov/Projects/SurfaceSubdivider /home/wajov/Projects/SurfaceSubdivider/cmake-build-debug /home/wajov/Projects/SurfaceSubdivider/cmake-build-debug /home/wajov/Projects/SurfaceSubdivider/cmake-build-debug/CMakeFiles/SurfaceSubdivider.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SurfaceSubdivider.dir/depend
