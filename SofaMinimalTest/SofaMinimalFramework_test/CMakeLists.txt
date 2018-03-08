cmake_minimum_required(VERSION 3.1)

project(SofaMinimalFramework_test)


set(LEGACY_SOFAFRAMEWORKTEST_DIR ${SOFA_KERNEL_SOURCE_DIR}/framework/framework_test )
set(LEGACY_SOFAFRAMEWORKEXTRATEST_DIR ${SOFA_KERNEL_SOURCE_DIR}/modules/sofa/frameworkextra/frameworkextra_test )


set(SOURCE_FILES
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/core/loader/MeshLoader_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/core/objectmodel/AspectPool_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/core/objectmodel/Data_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/core/objectmodel/BaseLink_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/core/objectmodel/BaseObjectDescription_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/core/objectmodel/DataFileName_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/core/DataEngine_test.cpp
    ${LEGACY_SOFAFRAMEWORKEXTRATEST_DIR}/core/TrackedData_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/defaulttype/MapMapSparseMatrixEigenUtils_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/defaulttype/MatTypes_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/defaulttype/VecTypes_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/types/Color_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/types/Material_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/KdTree_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/Utils_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/Quater_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/SVector_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/vector_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/io/MeshOBJ_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/io/MeshSTL_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/system/FileMonitor_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/system/FileRepository_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/system/FileSystem_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/system/PluginManager_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/system/atomic_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/logging/logging_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/testing/TestMessageHandler_test.cpp
    ${LEGACY_SOFAFRAMEWORKTEST_DIR}/main.cpp
)

if(SOFA_HAVE_PNG)
    list(APPEND SOURCE_FILES ${LEGACY_SOFAFRAMEWORKTEST_DIR}/helper/io/ImagePNG_test.cpp)
endif()

if(NOT SOFA_NO_OPENGL AND SOFA_HAVE_GLEW)
    list(APPEND SOURCE_FILES helper/gl/GLSLShader_test.cpp)
endif()

include_directories(${gtest_SOURCE_DIR}/include)

add_definitions("-DFRAMEWORK_TEST_RESOURCES_DIR=\"${LEGACY_SOFAFRAMEWORKTEST_DIR}/resources\"")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} gtest_main SofaCore SofaSimulationCommon SofaMinimalTest)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DSOFA_BUILD_TEST")

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${PROJECT_NAME} COMMENT "-> Running unit tests..." VERBATIM)
