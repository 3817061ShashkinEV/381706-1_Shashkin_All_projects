cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME All_projects)
project(${PROJECT_NAME})

set(MyExceptionLib MyExceptionLib)

set(Vector Vector)
set(VectorLib VectorLib)
set(VectorTest VectorTest)

set(Matrix Matrix)
set(MatrixLib MatrixLib)
set(MatrixTest MatrixTest)

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE) 
 set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MyExceptionLib)
add_subdirectory(MyExceptionLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)
add_subdirectory(Matrix)
add_subdirectory(MatrixLib)
add_subdirectory(MatrixTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)




