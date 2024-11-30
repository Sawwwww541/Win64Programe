cmake_minimum_required(VERSION 3.29)
project(Finalworks)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

link_libraries(libeasyx.a)

add_executable(Finalworks
        main.cpp
        ../midsearch.cpp
)