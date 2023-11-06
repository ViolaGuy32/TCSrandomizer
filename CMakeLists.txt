cmake_minimum_required (VERSION 3.0)
set (CMAKE_CXX_STANDARD 23)

project (rando)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#add_compile_definitions(_DEBUG)
add_executable(rando src/main.cpp src/CharacterData.cpp src/Characters.cpp src/FileGen.cpp src/OtherStuff.cpp src/Randomize.cpp src/Levels.cpp src/LevelData.cpp)

target_precompile_headers(rando PRIVATE src/pch.h)
