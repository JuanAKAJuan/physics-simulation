cmake_minimum_required(VERSION 3.20)
project(PhysicsSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directory for built objects.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Find SDL3 - prefer system version, fallback to vendored
find_package(SDL3 REQUIRED)
find_package(glm CONFIG REQUIRED)

if (NOT SDL3_FOUND)
  message(STATUS "SDL3 not found system-wide, using vendored version.")
  add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
endif()

# Create your game executable target
add_executable(PhysicsSimulator src/main.cpp src/core/particle.cpp src/core/particle_system.cpp src/graphics/renderer.cpp)

# Link to the SDL3 library.
target_link_libraries(PhysicsSimulator PRIVATE SDL3::SDL3 glm::glm)
