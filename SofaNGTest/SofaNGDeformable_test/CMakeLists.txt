cmake_minimum_required(VERSION 3.1)

project(SofaNGDeformable_test)

set(LEGACY_SOFADEFORNABLETEST_DIR ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SofaDeformable_test )

set(SOURCE_FILES
	#TODO: uncomment once CGLinearSolver is enabled
    #${LEGACY_SOFADEFORNABLETEST_DIR}/StiffSpringForceField_test.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SofaNGGTestMain SofaNGTest)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
