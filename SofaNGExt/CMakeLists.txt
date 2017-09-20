cmake_minimum_required(VERSION 3.0)

set(SOFANGEXT_PLUGIN_NAME SofaNGExt)
project(${SOFANGEXT_PLUGIN_NAME})

set(SOFANGEXT_PLUGIN_MAJOR_VERSION 0)
set(SOFANGEXT_PLUGIN_MINOR_VERSION 1)
set(SOFANGEXT_PLUGIN_VERSION ${SOFANGEXT_PLUGIN_MAJOR_VERSION}.${SOFANGEXT_PLUGIN_MINOR_VERSION})

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

find_package(SofaNG REQUIRED)



# NG-2
set(HEADER_FILES
    sofangext.h
    # SofaFem
    # TetrahedronFEMForceField # TODO: merge with Tetrahedral
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.inl
    # HexahedronFEMForceField # TODO: merge with Hexahedral
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.inl
    # TriangleFEMForceField  # TODO: merge with Triangular
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.inl
    # RestShapeSpringsForceField
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/RestShapeSpringsForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/RestShapeSpringsForceField.inl
    # SurfacePressureForceField
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/SurfacePressureForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/SurfacePressureForceField.inl

    # SofaSpring
    # SpringForceField
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.inl
    # StiffSpringForceField
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.inl

    # SofaLinearSolver
    # SparseLUSolver # direct
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLUSolver.h
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLUSolver.inl
    # SparseLDLSolver # directK
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.inl
    # SparseCholeskySolver
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseCholeskySolver.h
    # PrecomputedLinearSolver # iterative
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/PrecomputedLinearSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/PrecomputedLinearSolver.inl
    # JacobiPreconditioner
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/JacobiPreconditioner.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/JacobiPreconditioner.inl
    # ShewchukPCGLinearSolver
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/ShewchukPCGLinearSolver.h

    # SofaOdeSolver
    # StaticSolver
    # RungeKutta

    # SofaAnimationLoop
    # FreeMotionAnimationLoop
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/FreeMotionAnimationLoop.h

    # SofaMass
    # MeshMatrixMass
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.inl

    # SofaMapping
    # BarycentricMapping
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.inl
    # RigidMapping

    # SofaConstraint
    # GenericConstraintCorrection
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/GenericConstraintCorrection.h
    # GenericConstraintSolver
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/GenericConstraintSolver.h
    # PrecomputedConstraintCorrection

    # SofaCollision
    # LineModel
    # TriangleModel
    # PointModel
    # LocalMinDistance

    # SofaOpenglVisual
    # OglModel
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaOpenglVisual/OglModel.h
    # NewmarkImplicitSolver
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscSolver/NewmarkImplicitSolver.h

    # SofaEngine
    # BoxROI
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaEngine/BoxROI.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaEngine/BoxROI.inl
    # MergeROIs
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeROIs.h
    # MergeVectors
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeVectors.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeVectors.inl
    # MeshBoundaryROI
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshBoundaryROI.h
    # MeshClosingEngine
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshClosingEngine.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshClosingEngine.inl
    # IndexValueMapper
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndexValueMapper.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndexValueMapper.inl
    # SphereROI ?
    # GenerateCylinder ?

    # SofaHaptics
    # LCPForceFeedback

    # SofaImportExport
    # ReadState
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/ReadState.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/ReadState.inl
    # WriteState
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaExporter/WriteState.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaExporter/WriteState.inl

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
)



set(SOURCE_FILES
    initSofaNGExt.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaEngine/BoxROI.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/FreeMotionAnimationLoop.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/GenericConstraintCorrection.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/GenericConstraintSolver.cpp
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLUSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.cpp
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseCholeskySolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/JacobiPreconditioner.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaPreconditioner/ShewchukPCGLinearSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/PrecomputedLinearSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/IndexValueMapper.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeROIs.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MergeVectors.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshBoundaryROI.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralEngine/MeshClosingEngine.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/RestShapeSpringsForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/SurfacePressureForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaOpenglVisual/OglModel.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/ReadState.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaExporter/WriteState.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscSolver/NewmarkImplicitSolver.cpp

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
)



set(SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SOFANGEXT_PLUGIN)

set(SOFANGEXT_LIBRARIES
    SofaNG
    metis
    )

set(SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS "")
# Add build macros for Windows
#(TetrahedronFEMForceField, HexahedronFEMForceField, TriangleFEMForceField)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SIMPLE_FEM)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_FEM)
#(SpringForceField, StiffSpringForceField, RestShapeSpringsForceField)
#list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_DEFORMABLE) # already in SofaNG
#(MeshMatrixMass)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_FORCEFIELD)
#(BarycentricMapping)
#list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_MECHANICS) # already in SofaNG
#(BoxROI)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_ENGINE)
#(FreeMotionAnimationLoop, GenericConstraintCorrection, GenericConstraintSolver)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_CONSTRAINT)
#(SparseLUSolver, SparseLDLSolver, SparseCholeskySolver)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SPARSE_SOLVER)
#(IndexValueMapper, MergeROIs, MergeVectors, MeshBoundaryROI, MeshClosingEngine)
#list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_ENGINE) # already in SofaNG
#(SurfacePressureForceField)
#list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BOUNDARY_CONDITION) # already in SofaNG
#(OglModel)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_OPENGL_VISUAL)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BASE_VISUAL)
#(ReadState)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_LOADER)
#(WriteState)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_EXPORTER)
#(NewmarkImplicitSolver)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_SOLVER)

####

configure_file(${SOFA_REPO_SOURCE_DIR}/SofaMisc/config.h.in "${CMAKE_BINARY_DIR}/include/SofaMisc/config.h")

# include_directories(${SOFA_REPO_SOURCE_DIR}/modules)
# include_directories(${SOFA_KERNEL_SOURCE_DIR}/modules)
# include_directories(${SOFA_KERNEL_SOURCE_DIR})
# include_directories(${SOFA_REPO_SOURCE_DIR}/)

configure_file(sofangext.h.in ${SOFANGEXT_PLUGIN_NAME}/sofangext.h)
configure_file(SofaNGExtConfig.cmake.in ${CMAKE_BINARY_DIR}/cmake/SofaNGExtConfig.cmake)

#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${SOFANG_PLUGIN_NAME}/sofang.h DESTINATION "include/${SOFANG_PLUGIN_NAME}")

set(SOFANGEXT_PLUGIN_COMPILER_FLAGS "${SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS}")
set(SOFANGEXT_PLUGIN_INSTALL_DIR share/sofa/plugins/${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} )

target_link_libraries(${PROJECT_NAME} PUBLIC ${SOFANGEXT_LIBRARIES})

## Dependencies
# LULinearSolver
# target_link_libraries(${PROJECT_NAME} PUBLIC newmat)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${SOFANGEXT_PLUGIN_VERSION})
target_compile_definitions(${PROJECT_NAME} PUBLIC COMPILE_DEFINITIONS ${SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS})
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

