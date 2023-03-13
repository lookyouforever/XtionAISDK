file(GLOB_RECURSE Mosaic_SRC_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/db_vlvm/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/db_vlvm/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/dbreg/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dbreg/*.c
        )
add_library(EdgeEngineMosaic OBJECT ${Mosaic_SRC_FILES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/db_vlvm
        ${CMAKE_CURRENT_SOURCE_DIR}/dbreg
        )