project (pdal-test)
cmake_minimum_required (VERSION 3.10)

if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  # Set a default build type for single-configuration cmake generators
  # if no build type is set.
  set (CMAKE_BUILD_TYPE Release)
endif ()
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (PDAL 2.0 REQUIRED CONFIG)
find_package (Eigen3 REQUIRED)
set (Eigen3_LIBRARIES Eigen3::Eigen)

add_subdirectory (src)
