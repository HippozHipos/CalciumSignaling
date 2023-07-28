cmake_minimum_required (VERSION 3.8)
project(CalciumSig)

set(THIRD_PARTY_PATH  ${CMAKE_SOURCE_DIR}/thirdParty)

set(GLFW_INCLUDES  ${THIRD_PARTY_PATH}/glfw/glfw/include)
set(GLAD_INCLUDES  ${THIRD_PARTY_PATH}/glad/glad/include)
set(IMGUI_INCLUDES  ${THIRD_PARTY_PATH}/imgui/imgui "src/imguiBackend")

file(GLOB_RECURSE SOURCE_FILES 
	"src/CalciumSig/*.c"
	"src/CalciumSig/*.cpp"
)
	
file(GLOB_RECURSE HEADER_FILES 
	"src/CalciumSig/*.h"
	"src/CalciumSig/*.hpp"
)

include_directories(${GLFW_INCLUDES})
include_directories(${GLAD_INCLUDES})
include_directories(${IMGUI_INCLUDES})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CalciumSig)

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

#glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory( ${THIRD_PARTY_PATH}/glfw/glfw ${CMAKE_SOURCE_DIR}/out/glfw)

#glad
add_subdirectory( ${THIRD_PARTY_PATH}/glad/glad ${CMAKE_SOURCE_DIR}/out/glad)

#imgui
add_subdirectory( ${THIRD_PARTY_PATH}/imgui/imgui ${CMAKE_SOURCE_DIR}/out/imgui)

target_link_libraries( ${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw glad imgui)