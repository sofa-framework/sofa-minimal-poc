cmake_minimum_required(VERSION 3.1)

project(runSofaMinimal)

find_package(SofaMinimal0 REQUIRED)

include(cmake/GeneratePluginConfig.cmake)
# if MSVC then plugins are located in bin/ instead of lib/ on Mac and Linux
if(MSVC)
        set(_pluginLocation "bin")
else()
        set(_pluginLocation "lib")
endif()
set(_configPluginFileName plugin_list.conf)
set(_defaultConfigPluginFileName "${_configPluginFileName}.default")
set(_defaultConfigPluginFilePath "${CMAKE_BINARY_DIR}/${_pluginLocation}/${_defaultConfigPluginFileName}")
sofa_generate_plugin_config(${_defaultConfigPluginFilePath})
message("Write Plugin list at ${_defaultConfigPluginFilePath}")

set(HEADER_FILES
    #sofang.h
    BatchGUI.h
    ${SOFA_KERNEL_SOURCE_DIR}/../modules/SofaGraphComponent/RequiredPlugin.cpp

)

set(SOURCE_FILES
    #initSofaMinimal.cpp
    Main.cpp
    BatchGUI.cpp
    ${SOFA_KERNEL_SOURCE_DIR}/../modules/SofaGraphComponent/RequiredPlugin.cpp

)

# Add build macro for Windows
set(RUNSOFAMINIMAL_COMPILER_FLAGS "-DSOFA_BUILD_GRAPH_COMPONENT")


configure_file(${SOFA_KERNEL_SOURCE_DIR}/../SofaGeneral/config.h.in "${CMAKE_BINARY_DIR}/include/SofaGeneral/config.h")

if(APPLE)
	set_source_files_properties(${RC_FILES} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
endif()

add_executable(${PROJECT_NAME} ${RC_FILES} ${SOURCE_FILES})

target_compile_definitions(${PROJECT_NAME} PUBLIC "CONFIG_PLUGIN_FILENAME=${_configPluginFileName}")
target_compile_definitions(${PROJECT_NAME} PUBLIC "DEFAULT_CONFIG_PLUGIN_FILENAME=${_defaultConfigPluginFileName}")
target_link_libraries(${PROJECT_NAME} PUBLIC SofaHelper SofaCore SofaSimulationCommon SofaSimulationTree SofaSimulationGraph)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${RUNSOFAMINIMAL_COMPILER_FLAGS}")
