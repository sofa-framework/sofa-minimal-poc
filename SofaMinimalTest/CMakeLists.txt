cmake_minimum_required(VERSION 3.1)
project(SofaMinimalTest)

set(SOFAMINIMALTEST_VERSION 0.1)

find_package(SofaMinimal2 REQUIRED)
#find_package(SofaMisc REQUIRED)
#find_package(SceneCreator REQUIRED)

set(LEGACY_SOFATEST_DIR ${SOFA_REPO_SOURCE_DIR}/applications/plugins/SofaTest )

# Sofaesque GTest 
add_subdirectory(SofaMinimalGTestMain)    
# Unit tests
add_subdirectory(SofaMinimalFramework_test)
add_subdirectory(SofaMinimalBaseMechanics_test)
add_subdirectory(SofaMinimalLoader_test)
#add_subdirectory(SofaMinimalExplicitOdeSolver_test) #too much deps on SceneCreator
#add_subdirectory(SofaMinimalImplicitOdeSolver_test)
#add_subdirectory(SofaMinimalDeformable_test)

## SofaTest
set(HEADER_FILES
    #BroadPhase_test.h
    ${LEGACY_SOFATEST_DIR}/DataEngine_test.h
    #Elasticity_test.h
    #Elasticity_test.inl
    ${LEGACY_SOFATEST_DIR}/ForceField_test.h
    ${LEGACY_SOFATEST_DIR}/InitPlugin_test.h
    ${LEGACY_SOFATEST_DIR}/Mapping_test.h
    #MultiMapping_test.h
    #Multi2Mapping_test.h
    #PrimitiveCreation.h
    #LogMessage.h
)

set(SOURCE_FILES
    ${LEGACY_SOFATEST_DIR}/InitPlugin_test.cpp
    #Elasticity_test.cpp
    #PrimitiveCreation.cpp
)

# Workaround to include symbol for TestMessageHandler for Windows
# because: - cannot set the others test (dep to SceneCreator with a lot of deps)
#          - TestMessageHandle is using dll export/import mechanism and so will make this library containing the necessary code in the .lib
if(WIN32)
    list(APPEND SOURCE_FILES dummyfile.cpp)
endif()

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} SofaCore SofaHelper SofaDefaultType SofaMinimal2)
target_link_libraries(${PROJECT_NAME} gtest)
target_include_directories(${PROJECT_NAME} PUBLIC ${SOFA_REPO_SOURCE_DIR}/applications/plugins)
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<INSTALL_INTERFACE:include>")
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DSOFA_BUILD_TEST -DSOFA_SRC_DIR=\"\\\"${SOFA_REPO_SOURCE_DIR}\\\"\"")
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/..")

## Install rules for the library and headers; CMake package configurations files
# sofa_create_package(SofaTest ${SOFATEST_VERSION} ${PROJECT_NAME} SofaTest)
