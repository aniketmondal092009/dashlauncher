cmake_minimum_required(VERSION 4.2)

project(dash)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -O2)

include_directories(include)

set(SRCS
    src/main.cpp
    src/fzf.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})

find_package(X11 REQUIRED)

target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})

