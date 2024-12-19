cmake_minimum_required(VERSION 3.29.0)
project("app")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_STANDARD 20)

# Example: adding 3rd party library. In this case, Raylib
# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)
file(GLOB_RECURSE MODULES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.ixx"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cppm"
)
add_executable(${PROJECT_NAME} ${SOURCES} ${MODULES})
target_sources(${PROJECT_NAME} PRIVATE
    FILE_SET all_my_modules TYPE CXX_MODULES
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES ${MODULES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
)

if(MSVC)
   target_compile_options(${PROJECT_NAME} PUBLIC "/ZI")
   target_link_options(${PROJECT_NAME} PUBLIC "/INCREMENTAL")
endif()