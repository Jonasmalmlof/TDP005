cmake_minimum_required(VERSION 3.6)
project(clion005)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    cmake-build-debug/CMakeFiles/3.6.2/CompilerIdC/CMakeCCompilerId.c
    cmake-build-debug/CMakeFiles/3.6.2/CompilerIdCXX/CMakeCXXCompilerId.cpp
    cmake-build-debug/CMakeFiles/feature_tests.c
    cmake-build-debug/CMakeFiles/feature_tests.cxx
    equipment.cpp
    equipment.h
    game.cpp
    game.h
    game_state.cpp
    game_state.h
    goal.cpp
    goal.h
    gold.cpp
    gold.h
    level.cpp
    level.h
    main.cpp
    monster.cc
    monster.h
    movable.cc
    movable.h
    object.cc
    object.h
    player.cc
    player.h
    potion.cpp
    potion.h
    treasure.cpp
    treasure.h
    wall.cpp
    wall.h)

add_executable(clion005 ${SOURCE_FILES})