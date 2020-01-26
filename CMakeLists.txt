cmake_minimum_required(VERSION 3.9)

project(solarsystem)

# Set C++17
set_target_properties(${TARGET} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Executable files
set(SRC
  "src/main.cpp"
  "src/gui/window.cpp"
  "src/gui/window.h"
)

# Setup executables
add_executable(${PROJECT_NAME} ${SRC})

# Link SFML
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})