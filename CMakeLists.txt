cmake_minimum_required(VERSION 2.8.7)
set(PROJECT_NAME_STR edisondrone)
project(${PROJECT_NAME_STR} C CXX)

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread -std=c++11)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_definitions(-std=c++11)
else()
    message(FATAL_ERROR "Unknown CXX compiler")
endif()

include_directories(${PROJECT_SOURCE_DIR}/edisondrone/include)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/edisondrone/src/*.cc)
add_executable(edisondrone-server ${SRC_FILES})

if(test)
    enable_testing()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cc)
    set(TEST_SRC_FILES ${TEST_SRC_FILES} ${SRC_FILES})
    list(REMOVE_ITEM TEST_SRC_FILES
         ${PROJECT_SOURCE_DIR}/edisondrone/src/main.cc)
    add_executable(edisondrone-test ${TEST_SRC_FILES} )
    target_link_libraries(edisondrone-test
                          ${GTEST_LIBRARIES}
                          ${GTEST_MAIN_LIBRARIES}
                          pthread)

    add_test(AllEdisondroneTests edisondrone-test)
endif()
