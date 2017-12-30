cmake_minimum_required(VERSION 2.8.9)
project(SFML_RPG)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
<<<<<<< HEAD
include_directories(external_include)

link_directories(link)
=======
>>>>>>> 651af03b4c6191d22b5bc96ec9e8e8b539f4b9d4

if(WIN32)
	include_directories(include_win32)
endif(WIN32)

include_directories(F:/Projects/C++/C++_LIBS/SFML-2.4.2/include)

if(WIN32)
	include_directories(include_win32)
	link_directories(link_win32)
endif(WIN32)

file(GLOB SOURCES "src/*.cpp" "include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(SFML_RPG ${SOURCES})

if(WIN32)
<<<<<<< HEAD
	target_link_libraries(SFML_RPG sfml-window-2 sfml-graphics-2 sfml-system-2 dl RPG_MODDING_API)
	add_custom_command(TARGET SFML_RPG POST_BUILD COMMAND powershell cp bin/SFML_RPG.exe ../../run)
elseif(UNIX)
	target_link_libraries(SFML_RPG sfml-window sfml-graphics sfml-system dl RPG_MODDING_API)
=======
	target_link_libraries(SFML_RPG sfml-window-2 sfml-graphics-2 sfml-system-2 dl)
	add_custom_command(TARGET SFML_RPG POST_BUILD COMMAND powershell cp bin/SFML_RPG.exe ../../run)
elseif(UNIX)
	target_link_libraries(SFML_RPG sfml-window sfml-graphics sfml-system dl)
>>>>>>> 651af03b4c6191d22b5bc96ec9e8e8b539f4b9d4
	add_custom_command(TARGET SFML_RPG POST_BUILD COMMAND powershell cp bin/SFML_RPG.exe ../../run)
endif(WIN32)

add_custom_command(TARGET SFML_RPG POST_BUILD COMMAND powershell cp bin/SFML_RPG.exe ../../run)