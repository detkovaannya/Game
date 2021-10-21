cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(game main.cpp cell.cpp cell.h field.cpp field.h iterator.cpp iterator.h
        builder.h basefield_builder.cpp basefield_builder.h Interface_Object_Cell.h
        Director.cpp Director.h game.cpp game.h)
target_link_libraries(game sfml-graphics sfml-audio)