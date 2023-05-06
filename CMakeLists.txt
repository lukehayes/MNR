cmake_minimum_required(VERSION 3.25)
project(MNR)

# Variables.
#
set(C_STANDARD  17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include")
set(BIN_NAME "app")
set(CFLAGS "-E")

# Find all source files.
#
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.c")

# Find SDL2 library.
#
find_package(glfw3 REQUIRED)

# Find OpenGL library.
#
find_package(OpenGL REQUIRED)

# Find GLEW library.
#
find_package(GLEW REQUIRED)


# Set the project include directories.
#
include_directories(${INCLUDE_DIRS})


# Add debugging option
#
option(DEV_DEBUG "Enter debug mode" 0)
if (DEV_DEBUG)
  add_definitions(-DDEV_DEBUG)
endif()

# Create the final binary.
#
add_executable(${BIN_NAME} main.c )

# Tell cmake where the source files are.
#
add_subdirectory(src)

# Link in any libraies the binary needs.
#
target_link_libraries(${BIN_NAME} glfw)
target_link_libraries(${BIN_NAME} OpenGL)
target_link_libraries(${BIN_NAME} GLEW)

# After the source files have been compiled, link them into the final binary.
#
target_link_libraries(${BIN_NAME} MNR)

# Link to the math library (libm)
target_link_libraries(${BIN_NAME} m)

