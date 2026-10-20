cmake_minimum_required(VERSION 3.30)

set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_MODULE_STD 1)
include($ENV{CMAKE_IMPORT_STD_MODULE_DIR}/EnableCxxImportStd.cmake)

project(course_utils_usage_modules VERSION 0.0.1 LANGUAGES CXX)
find_package(course_utils REQUIRED)

add_executable(main main.cc)
target_link_libraries(main PUBLIC course_utils::course_utils_module)
target_compile_features(main PUBLIC "cxx_std_23")

