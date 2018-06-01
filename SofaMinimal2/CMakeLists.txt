cmake_minimum_required(VERSION 3.0)

set(SOFAMINIMAL2_PLUGIN_NAME SofaMinimal2)
project(${SOFAMINIMAL2_PLUGIN_NAME})

set(SOFAMINIMAL2_PLUGIN_MAJOR_VERSION 0)
set(SOFAMINIMAL2_PLUGIN_MINOR_VERSION 1)
set(SOFAMINIMAL2_PLUGIN_VERSION ${SOFAMINIMAL2_PLUGIN_MAJOR_VERSION}.${SOFAMINIMAL2_PLUGIN_MINOR_VERSION})

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

find_package(SofaMinimal1 REQUIRED)

# NG-2
set(HEADER_FILES
    sofaminimal2.h

    # SofaFem
    # TODO: merge {Tetra,Hexa}hedronFEMForceField with {Tetra,Hexa}hedralFEMForceField
    # TODO: merge TriangleFEMForceField with TriangularFEMForceField
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/RestShapeSpringsForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/RestShapeSpringsForceField.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/SurfacePressureForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/SurfacePressureForceField.inl

    # SofaSpring
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.inl

    # SofaLinearSolver
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaDenseSolver/LULinearSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLUSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLUSolver.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseCholeskySolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/PrecomputedLinearSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/PrecomputedLinearSolver.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/JacobiPreconditioner.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/JacobiPreconditioner.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/ShewchukPCGLinearSolver.h
    # SofaOdeSolver
    # StaticSolver
    # RungeKutta

    # SofaAnimationLoop
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/FreeMotionAnimationLoop.h

    # SofaMass
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.inl

    # SofaMapping
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaRigid/RigidMapping.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaRigid/RigidMapping.inl

    # SofaConstraint
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/GenericConstraintCorrection.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/GenericConstraintSolver.h
    # PrecomputedConstraintCorrection

    # SofaCollision
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/PointModel.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/PointModel.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/LineModel.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/LineModel.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/TriangleModel.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/TriangleModel.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/LocalMinDistance.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/LocalMinDistance.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/MinProximityIntersection.h

    # SofaOpenglVisual
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaOpenglVisual/OglModel.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscSolver/NewmarkImplicitSolver.h

    # SofaEngine
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaEngine/BoxROI.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaEngine/BoxROI.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeROIs.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeVectors.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeVectors.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshBoundaryROI.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshClosingEngine.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshClosingEngine.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndexValueMapper.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndexValueMapper.inl
    # SphereROI ?
    # GenerateCylinder ?

    # SofaHaptics
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaHaptics/LCPForceFeedback.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaHaptics/LCPForceFeedback.inl

    # SofaImportExport
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/ReadState.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/ReadState.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaExporter/WriteState.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaExporter/WriteState.inl

    # SofaMass
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/DiagonalMass.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/DiagonalMass.inl


    # Dependencies
    #(HexahedronFEMForceField)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/SparseGridTopology.h
    #(MeshMatrixMass)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/NumericalIntegrationDescriptor.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/NumericalIntegrationDescriptor.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetGeometryAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetGeometryAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetGeometryAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetGeometryAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetGeometryAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetGeometryAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetGeometryAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetGeometryAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetGeometryAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetGeometryAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetGeometryAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetGeometryAlgorithms.inl
    #(FreeMotionAnimationLoop)
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/ConstraintSolverImpl.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/LCPConstraintSolver.h
    #(OglModel)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseVisual/VisualModelImpl.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetTopologyModifier.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetTopologyModifier.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetTopologyModifier.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetTopologyModifier.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetTopologyModifier.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetTopologyModifier.h
    #(Point/Line/TriangleModel)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/LocalMinDistanceFilter.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/PointLocalMinDistanceFilter.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/LineLocalMinDistanceFilter.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/TriangleLocalMinDistanceFilter.h
    #(LocalMinDistance)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/BaseProximityIntersection.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaUserInteraction/RayModel.h
)



set(SOURCE_FILES
    initSofaMinimal2.cpp

    # SofaFem
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/RestShapeSpringsForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/SurfacePressureForceField.cpp

    # SofaSpring
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.cpp

    # SofaLinearSolver
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaDenseSolver/LULinearSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLUSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseCholeskySolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/PrecomputedLinearSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/JacobiPreconditioner.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/ShewchukPCGLinearSolver.h
    # SofaOdeSolver
    # StaticSolver
    # RungeKutta

    # SofaAnimationLoop
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/FreeMotionAnimationLoop.cpp

    # SofaMass
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.cpp

    # SofaMapping
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaRigid/RigidMapping.cpp

    # SofaConstraint
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/GenericConstraintCorrection.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/GenericConstraintSolver.cpp
    # PrecomputedConstraintCorrection

    # SofaCollision
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/PointModel.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/LineModel.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/TriangleModel.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/LocalMinDistance.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/MinProximityIntersection.cpp

    # SofaOpenglVisual
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaOpenglVisual/OglModel.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscSolver/NewmarkImplicitSolver.cpp

    # SofaEngine
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaEngine/BoxROI.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeROIs.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeVectors.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshBoundaryROI.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshClosingEngine.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndexValueMapper.cpp
    # SphereROI ?
    # GenerateCylinder ?

    # SofaHaptics
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaHaptics/LCPForceFeedback.cpp

    # SofaImportExport
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/ReadState.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaExporter/WriteState.cpp

    # SofaMass
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/DiagonalMass.cpp


    # Dependencies
    #(HexahedronFEMForceField)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/SparseGridTopology.cpp
    #(MeshMatrixMass)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/NumericalIntegrationDescriptor.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetGeometryAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetGeometryAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetGeometryAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetGeometryAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetGeometryAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetGeometryAlgorithms.cpp
    #(FreeMotionAnimationLoop)
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/ConstraintSolverImpl.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/LCPConstraintSolver.cpp
    #(OglModel)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseVisual/VisualModelImpl.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetTopologyModifier.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetTopologyModifier.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetTopologyModifier.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetTopologyModifier.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetTopologyModifier.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetTopologyModifier.cpp
    #(Point/Line/TriangleModel)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/LocalMinDistanceFilter.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/PointLocalMinDistanceFilter.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/LineLocalMinDistanceFilter.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaMeshCollision/TriangleLocalMinDistanceFilter.cpp
    #(LocalMinDistance)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/BaseProximityIntersection.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaUserInteraction/RayModel.cpp
)

set(SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SOFAMINIMAL2_PLUGIN)
# Add build macros for Windows
#(TetrahedronFEMForceField, HexahedronFEMForceField, TriangleFEMForceField)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SIMPLE_FEM)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_FEM)
#(MeshMatrixMass)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_FORCEFIELD)
#(BoxROI)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_ENGINE)
#(FreeMotionAnimationLoop, GenericConstraintCorrection, GenericConstraintSolver)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_CONSTRAINT)
#(SparseLUSolver, SparseLDLSolver, SparseCholeskySolver)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SPARSE_SOLVER)
#(OglModel)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_OPENGL_VISUAL)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_VISUAL)
#(ReadState)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_LOADER)
#(WriteState)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_EXPORTER)
#(NewmarkImplicitSolver)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_SOLVER)
#(LCPForceFeedback)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_HAPTICS)
#(LineModel)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MESH_COLLISION)
#(RigidMapping)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_RIGID)
#(LocalMinDistance)
list(APPEND SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_USER_INTERACTION)

####

configure_file(${SOFA_REPO_SOURCE_DIR}/SofaMisc/config.h.in "${CMAKE_BINARY_DIR}/include/SofaMisc/config.h")

# include_directories(${SOFA_REPO_SOURCE_DIR}/modules)
# include_directories(${SOFA_KERNEL_SOURCE_DIR}/modules)
# include_directories(${SOFA_KERNEL_SOURCE_DIR})
# include_directories(${SOFA_REPO_SOURCE_DIR}/)

configure_file(sofaminimal2.h.in ${SOFAMINIMAL2_PLUGIN_NAME}/sofaminimal2.h)
configure_file(SofaMinimal2Config.cmake.in ${CMAKE_BINARY_DIR}/cmake/SofaMinimal2Config.cmake)

#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${SOFAMINIMAL_PLUGIN_NAME}/sofaminimal1.h DESTINATION "include/${SOFAMINIMAL_PLUGIN_NAME}")

set(SOFAMINIMAL2_PLUGIN_COMPILER_FLAGS "${SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS}")
set(SOFAMINIMAL2_PLUGIN_INSTALL_DIR share/sofa/plugins/${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} )

set(SOFAMINIMAL2_LIBRARIES
    SofaMinimal1
    metis
    csparse # SparseLUSolver, SparseCholeskySolver
    )
target_link_libraries(${PROJECT_NAME} PUBLIC ${SOFAMINIMAL2_LIBRARIES})

## Dependencies
# LULinearSolver
# target_link_libraries(${PROJECT_NAME} PUBLIC newmat)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${SOFA_REPO_SOURCE_DIR}/applications/plugins>")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${SOFAMINIMAL2_PLUGIN_VERSION})
target_compile_definitions(${PROJECT_NAME} PUBLIC COMPILE_DEFINITIONS ${SOFAMINIMAL2_PLUGIN_COMPILER_DEFINITIONS})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

sofa_create_package(${PROJECT_NAME} 1.0 ${PROJECT_NAME} ${PROJECT_NAME})

#install(TARGETS ${PROJECT_NAME}
#        COMPONENT ${SOFAMINIMAL_PLUGIN_NAME}_libraries
#        EXPORT ${SOFAMINIMAL_PLUGIN_NAME}Targets
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#        PUBLIC_HEADER DESTINATION "include/${PROJECT_NAME}")

#install(DIRECTORY scenes/ DESTINATION ${SOFAMINIMAL_PLUGIN_INSTALL_DIR}/scenes)
#install(DIRECTORY data/ DESTINATION ${SOFAMINIMAL_PLUGIN_INSTALL_DIR}/data)

