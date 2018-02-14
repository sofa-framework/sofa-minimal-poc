cmake_minimum_required(VERSION 3.0)

set(SOFAMINIMAL3_PLUGIN_NAME SofaMinimal3)
project(${SOFAMINIMAL3_PLUGIN_NAME})

set(SOFAMINIMAL3_PLUGIN_MAJOR_VERSION 0)
set(SOFAMINIMAL3_PLUGIN_MINOR_VERSION 1)
set(SOFAMINIMAL3_PLUGIN_VERSION ${SOFAMINIMAL3_PLUGIN_MAJOR_VERSION}.${SOFAMINIMAL3_PLUGIN_MINOR_VERSION})

find_package(SofaMinimal2 REQUIRED)

# NG-3
set(HEADER_FILES
    sofaminimal3.h

    # Other (improving scene coverage)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseVisual/VisualStyle.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/MeshGmshLoader.h
    ${SOFA_REPO_SOURCE_DIR}/applications/plugins/SofaMiscCollision/DefaultCollisionGroupManager.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralDeformable/TriangularBendingSprings.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralDeformable/TriangularBendingSprings.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralDeformable/RegularGridSpringForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralDeformable/RegularGridSpringForceField.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaTopologyMapping/Tetra2TriangleTopologicalMapping.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetTopologyAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetTopologyAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetTopologyAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetTopologyAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetTopologyAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetTopologyAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetTopologyAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetTopologyAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetTopologyAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetTopologyAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetTopologyAlgorithms.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetTopologyAlgorithms.inl
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/MeshSpringForceField.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/MeshSpringForceField.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/PlaneForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/PlaneForceField.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/FixedPlaneConstraint.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/FixedPlaneConstraint.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/TrianglePressureForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/TrianglePressureForceField.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralSimpleFem/TetrahedralCorotationalFEMForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralSimpleFem/TetrahedralCorotationalFEMForceField.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangularFEMForceField.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangularFEMForceField.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/UncoupledConstraintCorrection.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/UncoupledConstraintCorrection.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/SphereLoader.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/NewProximityIntersection.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/NewProximityIntersection.inl
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscTopology/TopologicalChangeProcessor.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGraphComponent/BackgroundSetting.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGraphComponent/Gravity.h


    # Dependencies
    #(DefaultCollisionGroupManager)
    ${SOFA_REPO_SOURCE_DIR}/applications/plugins/SofaMiscCollision/SolverMerger.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralExplicitOdeSolver/RungeKutta4Solver.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaImplicitOdeSolver/StaticSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/LMConstraintSolver.h
)



set(SOURCE_FILES
    initSofaMinimal3.cpp
    
    # Other (improving scene coverage)
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseVisual/VisualStyle.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/MeshGmshLoader.cpp
    ${SOFA_REPO_SOURCE_DIR}/applications/plugins/SofaMiscCollision/DefaultCollisionGroupManager.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralDeformable/TriangularBendingSprings.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralDeformable/RegularGridSpringForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaTopologyMapping/Tetra2TriangleTopologicalMapping.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/PointSetTopologyAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/EdgeSetTopologyAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TriangleSetTopologyAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/TetrahedronSetTopologyAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/QuadSetTopologyAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseTopology/HexahedronSetTopologyAlgorithms.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/MeshSpringForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/PlaneForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/FixedPlaneConstraint.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaBoundaryCondition/TrianglePressureForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralSimpleFem/TetrahedralCorotationalFEMForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangularFEMForceField.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/UncoupledConstraintCorrection.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralLoader/SphereLoader.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseCollision/NewProximityIntersection.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscTopology/TopologicalChangeProcessor.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGraphComponent/BackgroundSetting.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGraphComponent/Gravity.cpp


    # Dependencies
    #(DefaultCollisionGroupManager)
    ${SOFA_REPO_SOURCE_DIR}/applications/plugins/SofaMiscCollision/SolverMerger.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaGeneralExplicitOdeSolver/RungeKutta4Solver.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaImplicitOdeSolver/StaticSolver.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaConstraint/LMConstraintSolver.cpp
)


sofa_add_generic(${SOFA_REPO_SOURCE_DIR}/applications/plugins/CImgPlugin CImgPlugin "Plugin" ON)

set(SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SOFAMINIMAL3_PLUGIN)
# Add build macros for Windows
#(DefaultCollisionGroupManager)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_COLLISION)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_EXPLICIT_ODE_SOLVER)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_IMPLICIT_ODE_SOLVER)
#(TriangularBendingSprings)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_DEFORMABLE)
#(Tetra3TriangleTopologicalMapping)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_TOPOLOGY_MAPPING)
#(PlaneForceField)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_BOUNDARY_CONDITION)
#(TetrahedralCorotationalFEMForceField)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GENERAL_SIMPLE_FEM)
#(TopologicalChangeProcessor)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_MISC_TOPOLOGY)
#(BackgroundSetting)
list(APPEND SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_GRAPH_COMPONENT)

####

configure_file(${SOFA_REPO_SOURCE_DIR}/SofaMisc/config.h.in "${CMAKE_BINARY_DIR}/include/SofaMisc/config.h")

configure_file(sofaminimal3.h.in ${SOFAMINIMAL3_PLUGIN_NAME}/sofaminimal3.h)
configure_file(SofaMinimal3Config.cmake.in ${CMAKE_BINARY_DIR}/cmake/SofaMinimal3Config.cmake)

#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${SOFAMINIMAL_PLUGIN_NAME}/sofaminimal1.h DESTINATION "include/${SOFAMINIMAL_PLUGIN_NAME}")

set(SOFAMINIMAL3_PLUGIN_COMPILER_FLAGS "${SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS}")
set(SOFAMINIMAL3_PLUGIN_INSTALL_DIR share/sofa/plugins/${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

set(SOFAMINIMAL3_LIBRARIES
    SofaMinimal2
    newmat # TriangularFEMForceField
    )
target_link_libraries(${PROJECT_NAME} PUBLIC ${SOFAMINIMAL3_LIBRARIES})

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${SOFA_REPO_SOURCE_DIR}/applications/plugins>")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${SOFAMINIMAL3_PLUGIN_VERSION})
target_compile_definitions(${PROJECT_NAME} PUBLIC COMPILE_DEFINITIONS ${SOFAMINIMAL3_PLUGIN_COMPILER_DEFINITIONS})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

#install(TARGETS ${PROJECT_NAME}
#        COMPONENT ${SOFAMINIMAL_PLUGIN_NAME}_libraries
#        EXPORT ${SOFAMINIMAL_PLUGIN_NAME}Targets
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#        PUBLIC_HEADER DESTINATION "include/${PROJECT_NAME}")

#install(DIRECTORY scenes/ DESTINATION ${SOFAMINIMAL_PLUGIN_INSTALL_DIR}/scenes)
#install(DIRECTORY data/ DESTINATION ${SOFAMINIMAL_PLUGIN_INSTALL_DIR}/data)

