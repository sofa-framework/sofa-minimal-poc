cmake_minimum_required(VERSION 3.1)

project(SofaNGExplicitOdeSolver_test)

set(LEGACY_SOFAEXPLICITODESOLVERTEST_DIR ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaExplicitOdeSolver/SofaExplicitOdeSolver_test )

set(SOURCE_FILES
    ## Cannot add those tests, needs cg/stiffspring,etc
    ${LEGACY_SOFAEXPLICITODESOLVERTEST_DIR}/EulerExplicitSolverDynamic_test.cpp
    )

add_definitions("-DSOFAEXPLICITODESOLVER_TEST_SCENES_DIR=\"${LEGACY_SOFAEXPLICITODESOLVERTEST_DIR}/scenes\"")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SofaGTestMain SofaNGTest)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
