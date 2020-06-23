cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
project(LM75_Raspberry_Pi)

EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )
message( STATUS "detected architecture: ${ARCHITECTURE}" )

if(NOT ${ARCHITECTURE} STREQUAL "x86_64" )
    add_definitions(-DIS_RASPBERRY_PI)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lwiringPi")
endif()

file(GLOB_RECURSE SRC_CXX_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

add_executable(${PROJECT_NAME}
    ${SRC_CXX_FILES} ${SRC_HEADERS})
target_link_libraries(${PROJECT_NAME} mosquittopp)

install (TARGETS ${PROJECT_NAME} DESTINATION /usr/local/bin/)
