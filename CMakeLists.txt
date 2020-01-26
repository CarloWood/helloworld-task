cmake_minimum_required(VERSION 3.12...3.16)

project(helloworld-task
   DESCRIPTION "A statefultask-based task for demonstration purposes"
   LANGUAGES CXX
)

include(AICxxProject)

#==============================================================================
# BUILD PROJECT
#

# This project is an OBJECT-library, used by other git submodules and the main project.
add_library(helloworld-task_ObjLib OBJECT)

# Set SOURCE_DIR to the current directory.
set_property(
  TARGET helloworld-task_ObjLib
  PROPERTY SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}"
)

# The list of source files.
target_sources(helloworld-task_ObjLib
  PRIVATE
    "HelloWorld.cxx"

    "HelloWorld.h"
)

# Required include search-paths.
get_target_property(CWDS_INTERFACE_INCLUDE_DIRECTORIES AICxx::cwds INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(helloworld-task_ObjLib
  PUBLIC
    "${CWDS_INTERFACE_INCLUDE_DIRECTORIES}" # For sys.h and debug.h.
)

# Require support for C++17.
target_compile_features(helloworld-task_ObjLib
  PUBLIC cxx_std_17
)

# Set link dependencies.
target_link_libraries(helloworld-task_ObjLib
  PUBLIC
    AICxx::statefultask
)

# Create an ALIAS target.
add_library(AICxx::helloworld-task ALIAS helloworld-task_ObjLib)
