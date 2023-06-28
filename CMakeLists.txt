cmake_minimum_required (VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SC_PROJECT_NAME "Reina Renderer")
set(SC_EXECUTABLE_NAME "reina")
set(SC_SRC_FILE_NAME "src")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

project(${SC_PROJECT_NAME})

find_package(OpenGL REQUIRED)

add_executable(${SC_EXECUTABLE_NAME})
aux_source_directory(${CMAKE_SOURCE_DIR}/${SC_SRC_FILE_NAME} SRC_FILES)
target_sources(${SC_EXECUTABLE_NAME} PRIVATE ${SRC_FILES} ${EXT_FILES})
target_include_directories(${SC_EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/${SC_SRC_FILE_NAME})
target_link_libraries(${SC_EXECUTABLE_NAME} pthread)

add_subdirectory(${SC_SRC_FILE_NAME})
