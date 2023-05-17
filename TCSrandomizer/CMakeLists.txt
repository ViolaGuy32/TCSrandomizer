cmake_minimum_required (VERSION 3.0)
set (CMAKE_CXX_STANDARD 20)
project (rando)
add_executable(rand main.cpp CharacterData.cpp Characters.cpp FileGen.cpp OtherStuff.cpp Randomize.cpp)
