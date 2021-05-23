cmake_minimum_required(VERSION 3.10)
project(MobRendLogger)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INC_DIR "${SRC_DIR}/include")

add_library(
    mr_logger 
    "${SRC_DIR}/mr_logger.c"
    "${INC_DIR}/mr_logger.h"
)
target_include_directories(
    mr_logger PUBLIC 
    "${INC_DIR}")