cmake_minimum_required(VERSION 3.1)

project(runSofaNG)

find_package(SofaFramework REQUIRED)
find_package(SofaSimulation REQUIRED)

set(HEADER_FILES
    #sofang.h
    BatchGUI.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/RegularGridTopology.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MeshTopology.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/GridTopology.cpp
)

set(SOURCE_FILES
    #initSofaNG.cpp
    Main.cpp
    BatchGUI.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/RegularGridTopology.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/MeshTopology.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/GridTopology.cpp
)


if(APPLE)
	set_source_files_properties(${RC_FILES} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
endif()

add_executable(${PROJECT_NAME} ${RC_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC SofaHelper SofaCore SofaSimulationCommon SofaSimulationTree SofaSimulationGraph)
