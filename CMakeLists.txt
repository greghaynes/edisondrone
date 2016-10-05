cmake_minimum_required(VERSION 2.8.8)

set(PROJECT_NAME_STR edisondrone)
project(${PROJECT_NAME_STR} C CXX)

set(BUILDSWIG OFF CACHE BOOL "Disable swig")
set(ENABLEEXAMPLES OFF CACHE BOOL "Disable examples")
set(BUILDTESTS OFF CACHE BOOL "Disable tests")

add_subdirectory(ext/mraa)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -ansi -Wno-deprecated -pthread -std=c++11")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11")
else()
    message(FATAL_ERROR "Unknown CXX compiler")
endif()


find_package(Threads REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/edisondrone/include
                    ${MRAA_INCLUDE_DIRS}
                    ${PROJECT_SOURCE_DIR}/ext/sparkfun_9dof)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/edisondrone/src/*.cc)
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/edisondrone/src/main.cc)
set(SRC_FILES
    ${SRC_FILES}
    ${PROJECT_SOURCE_DIR}/ext/sparkfun_9dof/SFE_LSM9DS0.cpp)

add_library(edisondrone STATIC ${SRC_FILES})
add_dependencies(edisondrone mraa)
target_link_libraries(edisondrone ${MRAA_LIBS_DIR}/libmraa.so)

add_executable(edisondrone-server
               ${PROJECT_SOURCE_DIR}/edisondrone/src/main.cc)
add_dependencies(edisondrone-server mraa)
target_link_libraries(edisondrone-server ${MRAA_LIBS_DIR}/libmraa.so edisondrone)

file(GLOB SIMULATOR_SRC_FILES ${PROJECT_SOURCE_DIR}/simulator/*.cc)
add_executable(edisondrone-simulator
               ${SIMULATOR_SRC_FILES})
add_dependencies(edisondrone-simulator mraa)
target_link_libraries(edisondrone-simulator ${MRAA_LIBS_DIR}/libmraa.so edisondrone)

if(test)
    enable_testing()
    add_subdirectory(ext/googletest)
    include_directories(${GTEST_INCLUDE_DIRS})

    file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cc)
    set(TEST_SRC_FILES
        ${TEST_SRC_FILES}
        ${PROJECT_SOURCE_DIR}/ext/sparkfun_9dof/SFE_LSM9DS0.cpp)

    add_executable(edisondrone-test ${TEST_SRC_FILES})
    add_dependencies(edisondrone-test mraa googletest)

    target_link_libraries(edisondrone-test
                          ${GTEST_LIBS_DIR}/libgtest.a
                          ${GTEST_LIBS_DIR}/libgtest_main.a
                          edisondrone
                          pthread)

    add_test(AllEdisondroneTests edisondrone-test)
endif()
