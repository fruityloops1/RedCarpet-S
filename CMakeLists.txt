cmake_minimum_required(VERSION 3.4)
project(RedCarpet-S CXX)

# Use response files when linking objects because of the large number of source files
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS ON)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  add_compile_options(-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  add_compile_options(-fcolor-diagnostics)
  # Required to silence "unused argument" warnings for -stdlib=libc++ when using distcc
  add_compile_options(-Wno-unused-command-line-argument)
  # Required to fix source paths in debug info when using distcc
  add_compile_options(-fdebug-prefix-map=/tmp=${CMAKE_CURRENT_BINARY_DIR})
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE CXXSOURCEFILES "src/*.cpp")

add_executable(RedCarpet-S ${CXXSOURCEFILES})
target_include_directories(RedCarpet-S PRIVATE include)
target_include_directories(RedCarpet-S PRIVATE src)
target_compile_definitions(RedCarpet-S PRIVATE NON_MATCHING)
target_compile_options(RedCarpet-S PRIVATE -fno-rtti -fno-exceptions)
target_compile_options(RedCarpet-S PRIVATE -fno-strict-aliasing)
target_compile_options(RedCarpet-S PRIVATE -Wall -Wextra -Wdeprecated)
target_compile_options(RedCarpet-S PRIVATE -Wno-unused-parameter -Wno-unused-private-field)
target_compile_options(RedCarpet-S PRIVATE -Wno-invalid-offsetof)
target_compile_options(RedCarpet-S PRIVATE -Wextra-semi)

set(NN_SDK_MAJOR 10)
set(NN_SDK_MINOR 4)
set(NN_SDK_PATCH 0)
set(NN_SDK_TYPE "Release")

set(NN_WARE_MAJOR 10)
set(NN_WARE_MINOR 4)
set(NN_WARE_PATCH 0)

add_subdirectory(lib/NintendoSDK)
target_link_libraries(RedCarpet-S PUBLIC NintendoSDK)

add_subdirectory(lib/sead)
target_link_libraries(RedCarpet-S PUBLIC sead)

add_subdirectory(lib/agl)
target_link_libraries(RedCarpet-S PUBLIC agl)

add_subdirectory(lib/aal)
target_link_libraries(RedCarpet-S PRIVATE aal)

add_subdirectory(lib/eui)
target_link_libraries(RedCarpet-S PRIVATE eui)

