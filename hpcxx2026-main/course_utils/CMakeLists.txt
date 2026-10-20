cmake_minimum_required(VERSION 3.30)

set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/EnableCxxImportStd.cmake)

set(CMAKE_CXX_MODULE_STD 1)

project(CCOURSE_UTILS VERSION 0.0.1 LANGUAGES CXX)
include(GNUInstallDirs)
option(COURSE_UTILS_TESTS "Whether to build the test programs." OFF)

# Plain headers version of the library
add_library(course_utils_header_only INTERFACE)
target_sources(course_utils_header_only INTERFACE
    FILE_SET HEADERS FILES
        Vbose.hh
	timeit.hh
	FileAsLines.hh
	CountingIterator.hh
	binform.hh
)
target_include_directories(course_utils_header_only INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)
add_library(course_utils::header_only ALIAS course_utils_header_only)
message("CMAKE_INSTALL_INCLUDEDIR = ${CMAKE_INSTALL_INCLUDEDIR}")
# Create an INTERFACE library. This is perfect for header-only or module-based
# libraries as it doesn't compile anything itself but groups usage requirements.
add_library(course_utils_module)
# Add the module interface unit to the library's public file set.
# This tells consuming projects that this is a module they can import.
target_sources(course_utils_module PUBLIC
    FILE_SET CXX_MODULES FILES course_utils.ixx
)
target_include_directories(course_utils_module PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)
target_compile_features(course_utils_module PUBLIC "cxx_std_23")
# Add the current directory to the include path for consumers, so they can find the headers.
target_link_libraries(course_utils_module PUBLIC course_utils_header_only)

add_library(course_utils::course_utils_module ALIAS course_utils_module)

# --- Example Executables ---
if (COURSE_UTILS_TESTS)
    set(tests timeit_test binform_test)
    foreach(src ${tests})
        add_executable(${src} tests/${src}.cc)
        target_link_libraries(${src} PRIVATE course_utils_header_only)
    endforeach()
    foreach(src ${tests})
        add_executable(${src}_m tests/${src}.cc)
	target_compile_definitions(${src}_m PRIVATE WITH_MODULE)
        target_link_libraries(${src}_m PRIVATE course_utils_module)
    endforeach()
endif()

# --- Installation and Exporting ---

# Install the header file and the compiled module artifacts.
# CMake automatically handles installing the correct .pcm/.gcm files.
install(TARGETS course_utils_header_only course_utils_module EXPORT course_utils
    LIBRARY
	COMPONENT Runtime 
	NAMELINK_COMPONENT Development 
	ARCHIVE 
	COMPONENT Development 

    FILE_SET HEADERS
	DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/course_utils"

    FILE_SET CXX_MODULES 
	DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/cxx_modules"
)

install(DIRECTORY cmake DESTINATION share)

# Generate and install the course_utilsConfig.cmake file so `find_package(course_utils)` works.
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/course_utilsConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/course_utilsConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/course_utils
)

#  export(EXPORT course_utils NAMESPACE course_utils:: 
#      FILE "${CMAKE_CURRENT_BINARY_DIR}/course_utilsTargets.cmake")

install(EXPORT course_utils NAMESPACE course_utils::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/course_utils
    FILE course_utilsTargets.cmake
	CXX_MODULES_DIRECTORY ${CMAKE_INSTALL_LIBDIR}/modules
	)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/course_utilsVersion.cmake"
	VERSION "${PROJECT_VERSION}"
	COMPATIBILITY AnyNewerVersion
)
install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/course_utilsConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/course_utilsVersion.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/course_utils
)
