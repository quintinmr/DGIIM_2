# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/quintin/Documentos/clion-2021.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/quintin/Documentos/clion-2021.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/contraste.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/contraste.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/contraste.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/contraste.dir/flags.make

CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o: CMakeFiles/contraste.dir/flags.make
CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o: ../estudiante/src/contraste.cpp
CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o: CMakeFiles/contraste.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o -MF CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o.d -o CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o -c /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/estudiante/src/contraste.cpp

CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/estudiante/src/contraste.cpp > CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.i

CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/estudiante/src/contraste.cpp -o CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.s

# Object files for target contraste
contraste_OBJECTS = \
"CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o"

# External object files for target contraste
contraste_EXTERNAL_OBJECTS =

contraste: CMakeFiles/contraste.dir/estudiante/src/contraste.cpp.o
contraste: CMakeFiles/contraste.dir/build.make
contraste: libimage.a
contraste: CMakeFiles/contraste.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable contraste"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/contraste.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/contraste.dir/build: contraste
.PHONY : CMakeFiles/contraste.dir/build

CMakeFiles/contraste.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/contraste.dir/cmake_clean.cmake
.PHONY : CMakeFiles/contraste.dir/clean

CMakeFiles/contraste.dir/depend:
	cd /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/cmake-build-debug-coverage /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/cmake-build-debug-coverage /home/quintin/Documentos/Documentos/DGIIM/2ºDGIIM/Informática/Estructuras_de_Datos/Prácticas/Práctica_2/practica2-imagenes/cmake-build-debug-coverage/CMakeFiles/contraste.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/contraste.dir/depend

