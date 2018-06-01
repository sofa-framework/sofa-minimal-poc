cmake_minimum_required(VERSION 3.0)

set(SOFAMINIMAL1_PLUGIN_NAME SofaMinimal1)
project(${SOFAMINIMAL1_PLUGIN_NAME})

set(SOFAMINIMAL1_PLUGIN_MAJOR_VERSION 0)
set(SOFAMINIMAL1_PLUGIN_MINOR_VERSION 1)
set(SOFAMINIMAL1_PLUGIN_VERSION ${SOFAMINIMAL1_PLUGIN_MAJOR_VERSION}.${SOFAMINIMAL1_PLUGIN_MINOR_VERSION})

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

find_package(SofaMinimal0 REQUIRED)

# NG-1
set(HEADER_FILES
    sofaminimal1.h
    # SofaMass
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/UniformMass.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/UniformMass.inl
    # SofaFEM
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/ConstantForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/ConstantForceField.inl
    # SofaOdeSolver
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaExplicitOdeSolver/EulerSolver.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaImplicitOdeSolver/EulerImplicitSolver.h
    # SofaLinearSolver
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/CGLinearSolver.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/CGLinearSolver.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLinearSolver/CholeskySolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLinearSolver/CholeskySolver.inl
    # SofaMapping
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/IdentityMapping.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/IdentityMapping.inl
    # SofaConstraint
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/FixedConstraint.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/PartialFixedConstraint.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/PartialFixedConstraint.inl
    # SofaCollision
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/CubeModel.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/SphereModel.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/SphereModel.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/DefaultContactManager.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/DefaultPipeline.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/BruteForceDetection.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/DiscreteIntersection.h
    # SofaEngine
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndicesFromValues.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndicesFromValues.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/ValuesFromIndices.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/ValuesFromIndices.inl
    # SofaLoader
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/MeshObjLoader.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/MeshVTKLoader.h
    # SofaMechanics
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.inl

    ## Dependencies
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
    #(DiscreteIntersection)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrUtility3.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrUtility3.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/BaseIntTool.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/CapsuleModel.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/CapsuleIntTool.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/CapsuleIntTool.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrSphereOBB.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrSphereOBB.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrCapsuleOBB.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrCapsuleOBB.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/OBBModel.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/OBBModel.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/OBBIntTool.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrOBBOBB.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrOBBOBB.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/RigidCapsuleModel.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/RigidCapsuleModel.inl
)

set(SOURCE_FILES
    initSofaMinimal1.cpp
    # SofaMass
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/UniformMass.cpp
    # SofaFEM
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/ConstantForceField.cpp
    # SofaOdeSolver
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaExplicitOdeSolver/EulerSolver.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaImplicitOdeSolver/EulerImplicitSolver.cpp
    # SofaLinearSolver
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseLinearSolver/CGLinearSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLinearSolver/CholeskySolver.cpp
    # SofaMapping
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/IdentityMapping.cpp
    # SofaConstraint
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/FixedConstraint.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/PartialFixedConstraint.cpp
    # SofaCollision
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/CubeModel.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/SphereModel.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/DefaultContactManager.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/DefaultPipeline.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/BruteForceDetection.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/DiscreteIntersection.cpp
    # SofaEngine
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndicesFromValues.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/ValuesFromIndices.cpp
    # SofaLoader
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/MeshObjLoader.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaLoader/MeshVTKLoader.cpp
    # SofaMechanics
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.cpp

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
    #(DiscreteIntersection)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrUtility3.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/BaseIntTool.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/CapsuleModel.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/CapsuleIntTool.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrSphereOBB.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrCapsuleOBB.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/OBBModel.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/OBBIntTool.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/IntrOBBOBB.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/RigidCapsuleModel.cpp
)


set(SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SOFAMINIMAL1_PLUGIN)
# Add build macro for Windows
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_TOPOLOGY)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_LINEAR_SOLVER)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_MECHANICS)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_COLLISION)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_LOADER)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_DEFORMABLE)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_EXPLICIT_ODE_SOLVER)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_IMPLICIT_ODE_SOLVER)
#list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_DENSE_SOLVER)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_LINEAR_SOLVER)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BOUNDARY_CONDITION)
list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_ENGINE)
# list(APPEND SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_FORCEFIELD)


# Other components (= "Kernel")
#set(OTHER_HEADER_FILES
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.h
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.inl
#    )

#set(OTHER_SOURCE_FILES
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.cpp
#    )
#set(OTHER_LIBRARIES
#    metis
#    )
#set(SOFAMINIMAL1_PLUGIN_OTHER_COMPILER_DEFINITIONS "")
#list(APPEND SOFAMINIMAL1_PLUGIN_OTHER_COMPILER_DEFINITIONS SOFA_BUILD_SPARSE_SOLVER)
####

configure_file(${SOFA_KERNEL_SOURCE_DIR}/SofaBase/config.h.in "${CMAKE_BINARY_DIR}/include/SofaBase/config.h")
configure_file(${SOFA_KERNEL_SOURCE_DIR}/SofaCommon/config.h.in "${CMAKE_BINARY_DIR}/include/SofaCommon/config.h")
# configure_file(${SOFA_REPO_SOURCE_DIR}/SofaMisc/config.h.in "${CMAKE_BINARY_DIR}/include/SofaMisc/config.h")

configure_file(sofaminimal1.h.in ${SOFAMINIMAL1_PLUGIN_NAME}/sofaminimal1.h)
configure_file(SofaMinimal1Config.cmake.in ${CMAKE_BINARY_DIR}/cmake/SofaMinimal1Config.cmake)

#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${SOFAMINIMAL1_PLUGIN_NAME}/sofang.h DESTINATION "include/${SOFAMINIMAL1_PLUGIN_NAME}")

set(SOFAMINIMAL1_PLUGIN_COMPILER_FLAGS "${SOFAMINIMAL1_PLUGIN_COMPILER_FLAGS} -DSOFA_BUILD_SOFAMINIMAL1_PLUGIN")
set(SOFAMINIMAL1_PLUGIN_INSTALL_DIR share/sofa/plugins/${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} )
# add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${OTHER_HEADER_FILES} ${OTHER_SOURCE_FILES} )

target_include_directories(${PROJECT_NAME} PUBLIC ${SOFA_REPO_SOURCE_DIR}/modules)
target_include_directories(${PROJECT_NAME} PUBLIC ${SOFA_KERNEL_SOURCE_DIR}/modules)
target_include_directories(${PROJECT_NAME} PUBLIC ${SOFA_KERNEL_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${SOFA_REPO_SOURCE_DIR}/)

target_link_libraries(${PROJECT_NAME} PUBLIC SofaMinimal0)
#target_link_libraries(${PROJECT_NAME} PUBLIC ${OTHER_LIBRARIES})

## Dependencies
# LULinearSolver
# target_link_libraries(${PROJECT_NAME} PUBLIC newmat)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${SOFAMINIMAL1_PLUGIN_VERSION})
# set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${SOFAMINIMAL1_PLUGIN_COMPILER_FLAGS}")
target_compile_definitions(${PROJECT_NAME} PUBLIC COMPILE_DEFINITIONS ${SOFAMINIMAL1_PLUGIN_COMPILER_DEFINITIONS})
#target_compile_definitions(${PROJECT_NAME} PUBLIC COMPILE_DEFINITIONS ${SOFAMINIMAL1_PLUGIN_OTHER_COMPILER_DEFINITIONS})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

sofa_create_package(${PROJECT_NAME} 1.0 ${PROJECT_NAME} ${PROJECT_NAME})

#install(TARGETS ${PROJECT_NAME}
#        COMPONENT ${SOFAMINIMAL1_PLUGIN_NAME}_libraries
#        EXPORT ${SOFAMINIMAL1_PLUGIN_NAME}Targets
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#        PUBLIC_HEADER DESTINATION "include/${PROJECT_NAME}")

#install(DIRECTORY scenes/ DESTINATION ${SOFAMINIMAL1_PLUGIN_INSTALL_DIR}/scenes)
#install(DIRECTORY data/ DESTINATION ${SOFAMINIMAL1_PLUGIN_INSTALL_DIR}/data)

