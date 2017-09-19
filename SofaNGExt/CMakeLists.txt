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
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.h
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.inl

#    # SofaFEM
##    TetrahedronFEMForceField # TODO: merge with Tetrahedral
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.h
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.inl
##    HexahedronFEMForceField # TODO: merge with Hexahedral
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.h
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.inl
##    TriangleFEMForceField  # TODO: merge with Triangular
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.h
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.inl

#    # SofaSpring
##    SpringForceField
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.h
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.inl
##    StiffSpringForceField
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.h
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.inl

    # SofaLinearSolver
    # LU # direct
    # LDL # direct
    # PrecomputedLinearSolver # iterative

    # SofaOdeSolver
    # StaticSolver
    # RungeKutta

    # SofaAnimationLoop
    # FreeMotionAnimationLoop

#    # SofaMass
#    MeshMatrixMass
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.h
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.inl

#    # SofaMapping
#    BarycentricMapping
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.h
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.inl
#    RigidMapping

    # SofaConstraint
    # GenericConstraintCorrection
    # GenericConstraintSolver
    # PrecomputedConstraintCorrection

    # SofaCollision
    # LineModel
    # TriangleModel
    # PointModel
    # LocalMinDistance

    # SofaOpenglVisual
    # OglModel

    # SofaEngine
    # BoxROI
    # MergeROIs + MergeVectors + MeshBoundaryROI + MeshClosingEngine
    # IndexValueMapper

    # SofaHaptics
    # LCPForceFeedback

    # SofaMisc TODO: CHANGE THE NAME
    # ReadState
    # WriteState


)

set(SOURCE_FILES
    initSofaNGExt.cpp
    ${SOFA_REPO_SOURCE_DIR}/modules/SofaSparseSolver/SparseLDLSolver.cpp
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/TetrahedronFEMForceField.cpp
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaSimpleFem/HexahedronFEMForceField.cpp
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscFem/TriangleFEMForceField.cpp
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/SpringForceField.cpp
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaDeformable/StiffSpringForceField.cpp
#    ${SOFA_REPO_SOURCE_DIR}/modules/SofaMiscForceField/MeshMatrixMass.cpp
#    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/BarycentricMapping.cpp
)


set(SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SOFANGEXT_PLUGIN)

set(SOFANGEXT_LIBRARIES
    SofaNG
    metis
    )

set(SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS "")
# Add build macros for Windows
#(SparseLDLSolver)
list(APPEND SOFANGEXT_PLUGIN_COMPILER_DEFINITIONS SOFA_BUILD_SPARSE_SOLVER)
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

