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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader

# Include any dependencies generated for this target.
include CMakeFiles/dev_mock.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dev_mock.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dev_mock.dir/flags.make

CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.o: CMakeFiles/dev_mock.dir/flags.make
CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.o: /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/mock/dev_mock_if.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.o   -c /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/mock/dev_mock_if.c

CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/mock/dev_mock_if.c > CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.i

CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/mock/dev_mock_if.c -o CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.s

CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.o: CMakeFiles/dev_mock.dir/flags.make
CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.o: /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/mock/dev_mock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.o -c /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/mock/dev_mock.cpp

CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/mock/dev_mock.cpp > CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.i

CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader/mock/dev_mock.cpp -o CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.s

CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.o: CMakeFiles/dev_mock.dir/flags.make
CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.o: /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.o   -c /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c

CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c > CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.i

CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c -o CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.s

# Object files for target dev_mock
dev_mock_OBJECTS = \
"CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.o" \
"CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.o" \
"CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.o"

# External object files for target dev_mock
dev_mock_EXTERNAL_OBJECTS =

libdev_mock.so: CMakeFiles/dev_mock.dir/mock/dev_mock_if.c.o
libdev_mock.so: CMakeFiles/dev_mock.dir/mock/dev_mock.cpp.o
libdev_mock.so: CMakeFiles/dev_mock.dir/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/sdk/third_party/parson/parson.c.o
libdev_mock.so: CMakeFiles/dev_mock.dir/build.make
libdev_mock.so: CMakeFiles/dev_mock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libdev_mock.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dev_mock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dev_mock.dir/build: libdev_mock.so

.PHONY : CMakeFiles/dev_mock.dir/build

CMakeFiles/dev_mock.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dev_mock.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dev_mock.dir/clean

CMakeFiles/dev_mock.dir/depend:
	cd /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/loader /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader /workspaces/aitrios-sdk-vision-sensing-app/tutorials/4_prepare_application/1_develop/testapp/build/loader/CMakeFiles/dev_mock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dev_mock.dir/depend

