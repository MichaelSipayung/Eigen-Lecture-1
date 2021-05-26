# CMakeList.txt : CMake project for Eigen Lecture 1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
find_package(Eigen3 CONFIG REQUIRED)
# Add source to this project's executable.
add_executable (CMakeTarget "Eigen Lecture 1.cpp" "Eigen Lecture 1.h" )
target_link_libraries(CMakeTarget PRIVATE Eigen3::Eigen)

# TODO: Add tests and install targets if needed.
