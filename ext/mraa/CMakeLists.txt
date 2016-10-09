project(mraa_builder C CXX)
include(ExternalProject)

ExternalProject_Add(mraa
    GIT_REPOSITORY https://github.com/intel-iot-devkit/mraa
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
    INSTALL_COMMAND ""
    CMAKE_ARGS "-DBUILDSWIG=OFF -DENABLEEXAMPLES=OFF"
    )

ExternalProject_Get_Property(mraa source_dir)
set(MRAA_INCLUDE_DIRS ${source_dir}/api PARENT_SCOPE)

ExternalProject_Get_Property(mraa binary_dir)
set(MRAA_LIBS_DIR ${binary_dir}/src PARENT_SCOPE)
