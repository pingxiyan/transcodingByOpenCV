cmake_minimum_required(VERSION 2.8)
project(cvt)

find_package(OpenCV)

# Add the source in project root directory
aux_source_directory(. DIRSRCS)
# Add header file include directories
include_directories(./ ${OpenCV_INCLUDE_DIR})
# Target
add_executable(cvt ${DIRSRCS})
target_link_libraries(cvt ${OpenCV_LIBS})