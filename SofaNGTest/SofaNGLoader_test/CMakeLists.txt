cmake_minimum_required(VERSION 3.1)

project(SofaNGLoader_test)

set(LEGACY_SOFALOADERTEST_DIR ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/SofaLoader_test )

set(SOURCE_FILES
    ${LEGACY_SOFALOADERTEST_DIR}/MeshVTKLoader_test.cpp
    ${LEGACY_SOFALOADERTEST_DIR}/MeshObjLoader_test.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SofaNGGTestMain SofaNGTest)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
