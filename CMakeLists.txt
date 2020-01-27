cmake_minimum_required(VERSION 3.9)

project(solarsystem)

# Set C++17
set_target_properties(${TARGET} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)
# Set C++17 for MSVC
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Executable files
set(SRC
  "src/main.cpp"
  "src/gui/window.cpp"
  "src/gui/window.h"
  "src/gui/canvans.cpp"
  "src/gui/canvans.h"
  "src/physics/vec2.h"
  "src/physics/object.cpp"
  "src/physics/object.h"
  "src/physics/physics.h"
  "src/physics/physics.cpp"
  "src/physics/mass.h"
  "src/physics/distance.h"
  "src/physics/space/planet.cpp"
  "src/physics/space/planet.h"
  "src/physics/space/moon.cpp"
  "src/physics/space/moon.h"
)

# Setup executables
add_executable(${PROJECT_NAME} ${SRC})

# Link SFML
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})