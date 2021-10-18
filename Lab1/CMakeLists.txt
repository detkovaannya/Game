cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game main.cpp cell.cpp cell.h states_of_cell.h field.cpp field.h iterator.cpp iterator.h builder.cpp builder.h basefield_builder.cpp basefield_builder.h ICell.h)
