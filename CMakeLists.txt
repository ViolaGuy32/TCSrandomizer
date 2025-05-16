cmake_minimum_required (VERSION 3.0)
set (CMAKE_CXX_STANDARD 20)

project (rando)

#add_compile_definitions(_DEBUG)
add_executable(rand src/main.cpp src/CharacterData.cpp src/Characters.cpp src/FileGen.cpp src/OtherStuff.cpp src/Randomize.cpp)

target_precompile_headers(rand PRIVATE src/pch.h)
