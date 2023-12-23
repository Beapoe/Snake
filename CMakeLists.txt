cmake_minimum_required(VERSION 3.10)
set(NAME Snake)
set(SOURCE src/main.cpp )
set(LSOURCE src/lib.cpp
            src/display.cpp
            src/logic.cpp)
project(${NAME} VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${NAME} ${SOURCE})
target_include_directories(${NAME} PRIVATE include)
add_library(${NAME}_lib STATIC ${LSOURCE})
target_include_directories(${NAME}_lib PRIVATE include)
target_link_libraries(${NAME} PRIVATE ${NAME}_lib)
