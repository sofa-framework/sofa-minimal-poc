cmake_minimum_required(VERSION 3.1)

project(runSofaNG)

find_package(SofaFramework REQUIRED)
find_package(SofaSimulation REQUIRED)

set(HEADER_FILES
    #sofang.h
    BatchGUI.h
    ${SOFA_KERNEL_SOURCE_DIR}/../modules/SofaGraphComponent/RequiredPlugin.cpp

)

set(SOURCE_FILES
    #initSofaNG.cpp
    Main.cpp
    BatchGUI.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/../modules/SofaGraphComponent/RequiredPlugin.cpp

)

# Add build macro for Windows
set(RUNSOFANG_COMPILER_FLAGS "-DSOFA_BUILD_GRAPH_COMPONENT")


configure_file(${SOFA_KERNEL_SOURCE_DIR}/../SofaGeneral/config.h.in "${CMAKE_BINARY_DIR}/include/SofaGeneral/config.h")

if(APPLE)
	set_source_files_properties(${RC_FILES} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
endif()

add_executable(${PROJECT_NAME} ${RC_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC SofaHelper SofaCore SofaSimulationCommon SofaSimulationTree SofaSimulationGraph)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${RUNSOFANG_COMPILER_FLAGS}")
