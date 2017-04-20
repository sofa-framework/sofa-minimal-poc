cmake_minimum_required(VERSION 3.0)

set(SOFANG_PLUGIN_NAME SofaNG)
project(${SOFANG_PLUGIN_NAME})

set(SOFANG_PLUGIN_MAJOR_VERSION 0)
set(SOFANG_PLUGIN_MINOR_VERSION 1)
set(SOFANG_PLUGIN_VERSION ${SOFANG_PLUGIN_MAJOR_VERSION}.${SOFANG_PLUGIN_MINOR_VERSION})

## RPATH
if(UNIX)
    # RPATH is a field in ELF binaries that is used as a hint by the system
    # loader to find needed shared libraries.
    #
    # In the build directory, cmake creates binaries with absolute paths in
    # RPATH.  And by default, it strips RPATH from installed binaries.  Here we
    # use CMAKE_INSTALL_RPATH to set a relative RPATH.  By doing so, we avoid
    # the need to play with LD_LIBRARY_PATH to get applications to run.
    set(CMAKE_INSTALL_RPATH "../lib")

    if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(CMAKE_MACOSX_RPATH ON)
    endif()
    
endif(UNIX)

find_package(SofaFramework REQUIRED)
find_package(SofaSimulation REQUIRED)

set(HEADER_FILES
    sofang.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaExplicitOdeSolver/EulerSolver.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaImplicitOdeSolver/EulerImplicitSolver.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.inl   
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/MeshObjLoader.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/MeshVTKLoader.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/CGLinearSolver.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/CGLinearSolver.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLinearSolver/CholeskySolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLinearSolver/CholeskySolver.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/FixedConstraint.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/PlaneForceField.h
    # ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.h
    # ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/UniformMass.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/UniformMass.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/IdentityMapping.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/IdentityMapping.inl
    ###### Dependencies
    #(MechanicalObject)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/RegularGridTopology.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/MeshTopology.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/GridTopology.h
    #(MeshVTKLoader)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/BaseVTKReader.h
    #(Linear Solvers)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/MatrixLinearSolver.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/DefaultMultiMatrixAccessor.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/GraphScatteredTypes.h

)

set(SOURCE_FILES
    initSofaNG.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaExplicitOdeSolver/EulerSolver.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaImplicitOdeSolver/EulerImplicitSolver.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/MeshObjLoader.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/MeshVTKLoader.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.cpp    
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/CGLinearSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLinearSolver/CholeskySolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/FixedConstraint.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/PlaneForceField.cpp
    # ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/UniformMass.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/IdentityMapping.cpp
    ## Dependencies
    #(MechanicalObject)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/RegularGridTopology.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/MeshTopology.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/GridTopology.cpp
    #(MechanicalObject && FixedConstraint)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetTopologyContainer.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetTopologyContainer.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetTopologyContainer.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetTopologyContainer.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetTopologyContainer.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetTopologyContainer.cpp
    #(MeshVTKLoader)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/BaseVTKReader.cpp
    #(Linear Solvers)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/MatrixLinearSolver.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/DefaultMultiMatrixAccessor.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/GraphScatteredTypes.cpp

)

set(BASE_LIBRARIES SofaCore SofaHelper SofaDefaultType SofaSimulationCommon)

set(SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SOFANG_PLUGIN)
# Add build macro for Windows
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_TOPOLOGY)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_LINEAR_SOLVER)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_MECHANICS)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_COLLISION)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_LOADER)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_DEFORMABLE)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_EXPLICIT_ODE_SOLVER)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_IMPLICIT_ODE_SOLVER)
#list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_DENSE_SOLVER)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_LINEAR_SOLVER)
list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BOUNDARY_CONDITION)
# list(APPEND SOFANG_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_FORCEFIELD)


# Other components (= "Kernel")
set(OTHER_HEADER_FILES
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.inl
    )

set(OTHER_SOURCE_FILES
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.cpp
    )
set(OTHER_LIBRARIES
    metis
    )
set(SOFANG_PLUGIN_OTHER_COMPILER_DEFINITIONS "")
list(APPEND SOFANG_PLUGIN_OTHER_COMPILER_DEFINITIONS SOFA_BUILD_SPARSE_SOLVER)
####

configure_file(${SOFA_KERNEL_SOURCE_DIR}/SofaBase/config.h.in "${CMAKE_BINARY_DIR}/include/SofaBase/config.h")
configure_file(${SOFA_KERNEL_SOURCE_DIR}/SofaCommon/config.h.in "${CMAKE_BINARY_DIR}/include/SofaCommon/config.h")
# configure_file(${SOFA_REPO_SOURCE_DIR}/SofaMisc/config.h.in "${CMAKE_BINARY_DIR}/include/SofaMisc/config.h")


include_directories(${SOFA_REPO_SOURCE_DIR}/modules)
include_directories(${SOFA_KERNEL_SOURCE_DIR}/modules)
include_directories(${SOFA_KERNEL_SOURCE_DIR})
include_directories(${SOFA_REPO_SOURCE_DIR}/)

configure_file(sofang.h.in ${SOFANG_PLUGIN_NAME}/sofang.h)
configure_file(SofaNGConfig.cmake.in ${CMAKE_BINARY_DIR}/cmake/SofaNGConfig.cmake)

#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${SOFANG_PLUGIN_NAME}/sofang.h DESTINATION "include/${SOFANG_PLUGIN_NAME}")

set(SOFANG_PLUGIN_COMPILER_FLAGS "${SOFANG_PLUGIN_COMPILER_FLAGS} -DSOFA_BUILD_SOFANG_PLUGIN")
set(SOFANG_PLUGIN_INSTALL_DIR share/sofa/plugins/${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} )
# add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${OTHER_HEADER_FILES} ${OTHER_SOURCE_FILES} )

target_link_libraries(${PROJECT_NAME} PUBLIC ${BASE_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} PUBLIC ${OTHER_LIBRARIES})

## Dependencies
# LULinearSolver
target_link_libraries(${PROJECT_NAME} PUBLIC newmat)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${SOFANG_PLUGIN_VERSION})
# set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${SOFANG_PLUGIN_COMPILER_FLAGS}")
target_compile_definitions(${PROJECT_NAME} PUBLIC COMPILE_DEFINITIONS ${SOFANG_PLUGIN_COMPILER_DEFINITIONS})
#target_compile_definitions(${PROJECT_NAME} PUBLIC COMPILE_DEFINITIONS ${SOFANG_PLUGIN_OTHER_COMPILER_DEFINITIONS})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

#install(TARGETS ${PROJECT_NAME}
#        COMPONENT ${SOFANG_PLUGIN_NAME}_libraries
#        EXPORT ${SOFANG_PLUGIN_NAME}Targets
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#        PUBLIC_HEADER DESTINATION "include/${PROJECT_NAME}")

#install(DIRECTORY scenes/ DESTINATION ${SOFANG_PLUGIN_INSTALL_DIR}/scenes)
#install(DIRECTORY data/ DESTINATION ${SOFANG_PLUGIN_INSTALL_DIR}/data)

