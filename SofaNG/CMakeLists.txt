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
include_directories(${SOFA_KERNEL_SOURCE_DIR}/modules/)
include_directories(${SOFA_KERNEL_SOURCE_DIR}/)

set(HEADER_FILES
    sofang.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.h
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.inl
)

set(SOURCE_FILES
    initSofaNG.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/modules/SofaBaseMechanics/MechanicalObject.cpp
)

configure_file(${SOFA_KERNEL_SOURCE_DIR}/SofaBase/config.h.in "${CMAKE_BINARY_DIR}/include/SofaBase/config.h")


configure_file(sofang.h.in ${SOFANG_PLUGIN_NAME}/sofang.h)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${SOFANG_PLUGIN_NAME}/sofang.h DESTINATION "include/${SOFANG_PLUGIN_NAME}")

set(SOFANG_PLUGIN_COMPILER_FLAGS "${SOFANG_PLUGIN_COMPILER_FLAGS} -DSOFA_BUILD_SOFANG_PLUGIN")
set(SOFANG_PLUGIN_INSTALL_DIR share/sofa/plugins/${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES} )
target_link_libraries(${PROJECT_NAME} PUBLIC SofaCore SofaHelper)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${SOFANG_PLUGIN_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${SOFANG_PLUGIN_COMPILER_FLAGS}")
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

install(TARGETS ${PROJECT_NAME}
        COMPONENT ${SOFANG_PLUGIN_NAME}_libraries
        EXPORT ${SOFANG_PLUGIN_NAME}Targets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION "include/${PROJECT_NAME}")

install(DIRECTORY scenes/ DESTINATION ${SOFANG_PLUGIN_INSTALL_DIR}/scenes)
install(DIRECTORY data/ DESTINATION ${SOFANG_PLUGIN_INSTALL_DIR}/data)

