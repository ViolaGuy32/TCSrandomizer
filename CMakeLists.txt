cmake_minimum_required (VERSION 3.0)
set (CMAKE_CXX_STANDARD 20)

project (rando)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#add_compile_definitions(_DEBUG)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

#add_executable(rando src/main.cpp
#	src/CharacterData.cpp src/Characters.cpp src/FileGen.cpp 
#	src/OtherStuff.cpp src/Randomize.cpp src/Levels.cpp src/LevelData.cpp src/gui.cpp)
#
#add_executable(TCSrandomizer src/gui.cpp
#	src/CharacterData.cpp src/Characters.cpp src/FileGen.cpp 
#	src/OtherStuff.cpp src/Randomize.cpp src/Levels.cpp src/LevelData.cpp src/gui.cpp)

add_executable(tester src/gui.cpp)

target_link_libraries(tester PRIVATE PkgConfig::GTK4)

#target_precompile_headers(rando PRIVATE src/pch.h)
