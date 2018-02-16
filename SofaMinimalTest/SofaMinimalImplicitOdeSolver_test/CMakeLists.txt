cmake_minimum_required(VERSION 3.1)

project(SofaMinimalImplicitOdeSolver_test)

set(LEGACY_SOFAIMPLICITODESOLVERTEST_DIR ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaImplicitOdeSolver/SofaImplicitOdeSolver_test )

set(SOURCE_FILES
    ## Cannot add those tests, needs cg/stiffspring,etc
    #EulerImplicitSolverStatic_test.cpp
    #EulerImplicitSolverDynamic_test.cpp
    #SpringSolverDynamic_test.cpp
    #VariationalSymplecticExplicitSolverDynamic_test.cpp
    #VariationalSymplecticImplicitSolverDynamic_test.cpp
    #VariationalSymplecticImplicitSolverNonLinearForceDynamic_test.cpp)

add_definitions("-DSOFAIMPLICITODESOLVER_TEST_SCENES_DIR=\"${LEGACY_SOFAIMPLICITODESOLVERTEST_DIR}/scenes\"")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SofaMinimalGTestMain SofaMinimalTest)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
