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

set(Queue Queue)
set(QueueLib QueueLib)
set(QueueTest QueueTest)

set(List List)
set(ListLib ListLib)
set(ListTest ListTest)

set(MultiStack MultiStack)
set(MultiStackLib MultiStackLib)
set(MultiStackTest MultiStackTest)

set(ArrList ArrList)
set(ArrListLib ArrListLib)
set(ArrListTest ArrListTest)

set(StackList StackList)
set(StackListLib StackListLib)
set(StackListTest StackListTest)

set(PolishNotation PolishNotation)
set(PolishNotationLib PolishNotationLib)
set(PolishNotationTest PolishNotationTest)

set(Polynomial Polynomial)
set(PolynomialLib PolynomialLib)
set(PolynomialTest PolynomialTest)

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

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(List)
add_subdirectory(ListLib)
add_subdirectory(ListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MultiStackLib)
add_subdirectory(MultiStack)
add_subdirectory(MultiStackLib)
add_subdirectory(MultiStackTest)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ArrListLib)
add_subdirectory(ArrList)
add_subdirectory(ArrListLib)
add_subdirectory(ArrListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackListLib)
add_subdirectory(StackList)
add_subdirectory(StackListLib)
add_subdirectory(StackListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishNotationLib)
add_subdirectory(PolishNotation)
add_subdirectory(PolishNotationLib)
add_subdirectory(PolishNotationTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolynomialLib)
add_subdirectory(Polynomial)
add_subdirectory(PolynomialLib)
add_subdirectory(PolynomialTest)