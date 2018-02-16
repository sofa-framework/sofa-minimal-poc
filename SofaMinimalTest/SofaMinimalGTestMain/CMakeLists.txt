cmake_minimum_required(VERSION 3.1)
project(SofaMinimalGTestMain)


set(LEGACY_SOFAGTESTMAIN_DIR ${SOFA_REPO_SOURCE_DIR}/tools/SofaGTestMain )

## Dependencies
find_package(SofaSimulation REQUIRED)
find_package(GTest CONFIG REQUIRED)

## Version
set(SOFAGTESTMAIN_VERSION ${SofaSimulation_VERSION})

add_definitions("-DSOFA_SRC_DIR=\"${CMAKE_SOURCE_DIR}\"")

add_library(${PROJECT_NAME} ${LEGACY_SOFAGTESTMAIN_DIR}/SofaGTestMain.cpp)
target_link_libraries(${PROJECT_NAME} gtest SofaSimulationTree SofaSimulationGraph SofaMinimalTest)

## Install rules for the library; CMake package configurations files
# sofa_create_package(${PROJECT_NAME} ${SOFAGTESTMAIN_VERSION} ${PROJECT_NAME} ${PROJECT_NAME})
