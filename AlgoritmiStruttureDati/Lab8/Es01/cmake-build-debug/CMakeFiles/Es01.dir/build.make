# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Es01.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\Es01.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Es01.dir\flags.make

CMakeFiles\Es01.dir\main.c.obj: CMakeFiles\Es01.dir\flags.make
CMakeFiles\Es01.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Es01.dir/main.c.obj"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Es01.dir\main.c.obj /FdCMakeFiles\Es01.dir\ /FS -c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\main.c"
<<

CMakeFiles\Es01.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Es01.dir/main.c.i"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe > CMakeFiles\Es01.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\main.c"
<<

CMakeFiles\Es01.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Es01.dir/main.c.s"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Es01.dir\main.c.s /c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\main.c"
<<

CMakeFiles\Es01.dir\listaTitoli.c.obj: CMakeFiles\Es01.dir\flags.make
CMakeFiles\Es01.dir\listaTitoli.c.obj: ..\listaTitoli.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Es01.dir/listaTitoli.c.obj"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Es01.dir\listaTitoli.c.obj /FdCMakeFiles\Es01.dir\ /FS -c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\listaTitoli.c"
<<

CMakeFiles\Es01.dir\listaTitoli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Es01.dir/listaTitoli.c.i"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe > CMakeFiles\Es01.dir\listaTitoli.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\listaTitoli.c"
<<

CMakeFiles\Es01.dir\listaTitoli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Es01.dir/listaTitoli.c.s"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Es01.dir\listaTitoli.c.s /c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\listaTitoli.c"
<<

CMakeFiles\Es01.dir\titolo.c.obj: CMakeFiles\Es01.dir\flags.make
CMakeFiles\Es01.dir\titolo.c.obj: ..\titolo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Es01.dir/titolo.c.obj"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Es01.dir\titolo.c.obj /FdCMakeFiles\Es01.dir\ /FS -c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\titolo.c"
<<

CMakeFiles\Es01.dir\titolo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Es01.dir/titolo.c.i"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe > CMakeFiles\Es01.dir\titolo.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\titolo.c"
<<

CMakeFiles\Es01.dir\titolo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Es01.dir/titolo.c.s"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Es01.dir\titolo.c.s /c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\titolo.c"
<<

CMakeFiles\Es01.dir\data.c.obj: CMakeFiles\Es01.dir\flags.make
CMakeFiles\Es01.dir\data.c.obj: ..\data.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Es01.dir/data.c.obj"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Es01.dir\data.c.obj /FdCMakeFiles\Es01.dir\ /FS -c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\data.c"
<<

CMakeFiles\Es01.dir\data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Es01.dir/data.c.i"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe > CMakeFiles\Es01.dir\data.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\data.c"
<<

CMakeFiles\Es01.dir\data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Es01.dir/data.c.s"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Es01.dir\data.c.s /c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\data.c"
<<

CMakeFiles\Es01.dir\BST.c.obj: CMakeFiles\Es01.dir\flags.make
CMakeFiles\Es01.dir\BST.c.obj: ..\BST.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Es01.dir/BST.c.obj"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Es01.dir\BST.c.obj /FdCMakeFiles\Es01.dir\ /FS -c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\BST.c"
<<

CMakeFiles\Es01.dir\BST.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Es01.dir/BST.c.i"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe > CMakeFiles\Es01.dir\BST.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\BST.c"
<<

CMakeFiles\Es01.dir\BST.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Es01.dir/BST.c.s"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Es01.dir\BST.c.s /c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\BST.c"
<<

CMakeFiles\Es01.dir\quotazione.c.obj: CMakeFiles\Es01.dir\flags.make
CMakeFiles\Es01.dir\quotazione.c.obj: ..\quotazione.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Es01.dir/quotazione.c.obj"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Es01.dir\quotazione.c.obj /FdCMakeFiles\Es01.dir\ /FS -c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\quotazione.c"
<<

CMakeFiles\Es01.dir\quotazione.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Es01.dir/quotazione.c.i"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe > CMakeFiles\Es01.dir\quotazione.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\quotazione.c"
<<

CMakeFiles\Es01.dir\quotazione.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Es01.dir/quotazione.c.s"
	C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Es01.dir\quotazione.c.s /c "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\quotazione.c"
<<

# Object files for target Es01
Es01_OBJECTS = \
"CMakeFiles\Es01.dir\main.c.obj" \
"CMakeFiles\Es01.dir\listaTitoli.c.obj" \
"CMakeFiles\Es01.dir\titolo.c.obj" \
"CMakeFiles\Es01.dir\data.c.obj" \
"CMakeFiles\Es01.dir\BST.c.obj" \
"CMakeFiles\Es01.dir\quotazione.c.obj"

# External object files for target Es01
Es01_EXTERNAL_OBJECTS =

Es01.exe: CMakeFiles\Es01.dir\main.c.obj
Es01.exe: CMakeFiles\Es01.dir\listaTitoli.c.obj
Es01.exe: CMakeFiles\Es01.dir\titolo.c.obj
Es01.exe: CMakeFiles\Es01.dir\data.c.obj
Es01.exe: CMakeFiles\Es01.dir\BST.c.obj
Es01.exe: CMakeFiles\Es01.dir\quotazione.c.obj
Es01.exe: CMakeFiles\Es01.dir\build.make
Es01.exe: CMakeFiles\Es01.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Es01.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Es01.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\10.0.16299.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\10.0.16299.0\x86\mt.exe --manifests -- C:\PROGRA~2\MIB055~1\2017\Enterprise\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Es01.dir\objects1.rsp @<<
 /out:Es01.exe /implib:Es01.lib /pdb:"D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\Es01.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Es01.dir\build: Es01.exe
.PHONY : CMakeFiles\Es01.dir\build

CMakeFiles\Es01.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Es01.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Es01.dir\clean

CMakeFiles\Es01.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01" "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01" "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug" "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug" "D:\INFORMATICA 2020-21\Algoritmi e Strutture Dati\Programmazione\Laboratori\Lab8\Es01\cmake-build-debug\CMakeFiles\Es01.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Es01.dir\depend

