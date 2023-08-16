cmake_minimum_required(VERSION 3.0.0)
project(leetcode_shit VERSION 0.1.0 LANGUAGES C CXX)


file(GLOB_RECURSE LEETCODE_SRC 
    leetcode/*.cpp
)
include_directories(
    leetcode/
)
# message(${LEETCODE_SRC})


# dbg-macro
include(FetchContent)
FetchContent_Declare(dbg_macro GIT_REPOSITORY https://github.com/sharkdp/dbg-macro)
FetchContent_MakeAvailable(dbg_macro)
# # Disable dbg-macro
# add_definitions(-DDBG_MACRO_DISABLE)


# benchmark
find_package(benchmark REQUIRED)




# Enable benchmark
option(ENABLE_BENCHMARK "google benchmark" OFF)

if(ENABLE_BENCHMARK)
    add_definitions(-DGO_BENCHMARK)
    add_definitions(-DDBG_MACRO_DISABLE)
endif()







add_executable(leetcode_shit
    main.cpp
    ${LEETCODE_SRC}
)

target_link_libraries(${PROJECT_NAME} PRIVATE dbg_macro benchmark::benchmark)
