cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(course_utils_usage_headers VERSION 0.0.1 LANGUAGES CXX)
find_package(course_utils REQUIRED)

add_executable(main main.cc)
target_link_libraries(main PRIVATE course_utils::course_utils_header_only)

