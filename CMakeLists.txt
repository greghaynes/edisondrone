cmake_minimum_required(VERSION 2.8.8)
set(PROJECT_NAME_STR edisondrone)
project(${PROJECT_NAME_STR} C CXX)

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cc)
add_executable(edisondrone-test ${TEST_SRC_FILES})
target_link_libraries(edisondrone-test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

add_test(AllEdisondroneTests edisondrone-test)
