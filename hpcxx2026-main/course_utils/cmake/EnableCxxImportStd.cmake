# EnableCxxImportStd.cmake
# Centralized handling of CMAKE_EXPERIMENTAL_CXX_IMPORT_STD GUIDs
# Update this file when CMake changes the GUID again.

cmake_policy(PUSH)
cmake_policy(SET CMP0012 NEW)  # For better version comparisons if needed

# Only do this once per configure
if(DEFINED _CXX_IMPORT_STD_GATE_SET)
    cmake_policy(POP)
    return()
endif()
set(_CXX_IMPORT_STD_GATE_SET TRUE)

# Require a version that supports import std
if(CMAKE_VERSION VERSION_LESS "3.30")
    message(WARNING "CMAKE_EXPERIMENTAL_CXX_IMPORT_STD requires CMake >= 3.30. Current: ${CMAKE_VERSION}")
    cmake_policy(POP)
    return()
endif()

# Map CMake version ranges to the correct GUID
if(CMAKE_VERSION VERSION_GREATER_EQUAL "4.4")  # or whatever the next breaking change is
    set(_import_std_guid "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
elseif(CMAKE_VERSION VERSION_GREATER_EQUAL "4.3")    
    set(_import_std_guid "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
elseif(CMAKE_VERSION VERSION_GREATER_EQUAL "4.0.3")
    set(_import_std_guid "d0edc3af-4c50-42ea-a356-e2862fe7a444")
elseif(CMAKE_VERSION VERSION_GREATER_EQUAL "4.0.0")
    set(_import_std_guid "a9e1cf81-9932-4810-974b-6eccaf14e457")
elseif(CMAKE_VERSION VERSION_GREATER_EQUAL "3.30")
    set(_import_std_guid "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
else()
    set(_import_std_guid "")
endif()

if(_import_std_guid)
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "${_import_std_guid}" CACHE INTERNAL "Experimental gate for import std")
    message(STATUS "Enabled experimental CXX import std with GUID ${_import_std_guid}")
    message(STATUS "for CMake ${CMAKE_VERSION}")
else()
    message(WARNING "No known GUID for this CMake version. Update EnableCxxImportStd.cmake")
endif()

cmake_policy(POP)

