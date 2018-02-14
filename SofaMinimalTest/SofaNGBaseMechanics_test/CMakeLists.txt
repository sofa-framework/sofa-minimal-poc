cmake_minimum_required(VERSION 3.1)

project(SofaMinimalBaseMechanics_test)


set(LEGACY_SOFABASEMECHANICSTEST_DIR ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/SofaBaseMechanics_test )

set(SOURCE_FILES
    #UniformMass_test.cpp
    #DiagonalMass_test.cpp
    ${LEGACY_SOFABASEMECHANICSTEST_DIR}/MechanicalObject_test.cpp
    #UniformMass_test.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SofaMinimal1GTestMain SofaMinimalTest SofaMinimal1)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
