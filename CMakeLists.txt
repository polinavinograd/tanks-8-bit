cmake_minimum_required(VERSION 3.0.0)
project(tanks-8-bit VERSION 0.1.0)

file(
  GLOB_RECURSE
  SOURCES
  CMAKE_CONFIGURE_DEPENDS
  "src/*.hpp"
  "src/*.cpp"
)

add_executable(tanks-8-bit ${SOURCES} main.cpp)

target_link_libraries(
  tanks-8-bit
  sfml-graphics
  sfml-window
  sfml-system
)
