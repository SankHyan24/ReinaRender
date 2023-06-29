target_include_directories(
    ${SC_EXECUTABLE_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends
)

# add imgui sources except files under examples
file(GLOB IMGUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_sdl2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_sdl2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.h
)




target_sources(
    ${SC_EXECUTABLE_NAME}
    PRIVATE
    ${IMGUI_SOURCES}
)
