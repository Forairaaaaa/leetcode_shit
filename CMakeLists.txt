cmake_minimum_required(VERSION 3.0.0)
project(leetcode_shit VERSION 0.1.0 LANGUAGES C CXX)

# dbg-macro
include(FetchContent)
FetchContent_Declare(dbg_macro GIT_REPOSITORY https://github.com/sharkdp/dbg-macro)
FetchContent_MakeAvailable(dbg_macro)

# benchmark
find_package(benchmark REQUIRED)


add_executable(leetcode_shit
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE dbg_macro benchmark::benchmark)
