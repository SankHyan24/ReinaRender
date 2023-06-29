cmake_minimum_required (VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SC_PROJECT_NAME "Reina Renderer")
set(SC_EXECUTABLE_NAME "reina")
set(SC_SRC_FILE_NAME "src")


project(${SC_PROJECT_NAME})

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
set(SDL2_LIBRARIES  "SDL2" "SDL2main")
set(SDL2_INCLUDE_DIRS  /usr/include/SDL2)
set(SDL2_LIBDIR ${CMAKE_SOURCE_DIR}/thirdparty/SDL2/lib/x64)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


add_executable(${SC_EXECUTABLE_NAME})
aux_source_directory(${CMAKE_SOURCE_DIR}/${SC_SRC_FILE_NAME} SRC_FILES)
target_sources(${SC_EXECUTABLE_NAME} PRIVATE ${SRC_FILES} ${EXT_FILES})
target_include_directories(
    ${SC_EXECUTABLE_NAME} 
    PRIVATE 
    ${CMAKE_SOURCE_DIR}/${SC_SRC_FILE_NAME}
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${SC_EXECUTABLE_NAME} pthread ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

add_subdirectory(${SC_SRC_FILE_NAME})
add_subdirectory(thirdparty)
