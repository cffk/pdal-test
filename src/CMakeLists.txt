add_library (pdal_plugin_filter_eigentest SHARED eigentest.cpp eigentest.hpp)

target_link_libraries (pdal_plugin_filter_eigentest
  PRIVATE ${PDAL_LIBRARIES} ${Eigen3_LIBRARIES})

target_include_directories (pdal_plugin_filter_eigentest
  PRIVATE ${PDAL_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})

# install lib
install(FILES eigentest.hpp DESTINATION include)
install(TARGETS
  pdal_plugin_filter_eigentest
  EXPORT targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib${LIB_SUFFIX}
  ARCHIVE DESTINATION lib${LIB_SUFFIX})

add_executable (bare_eigentest bareeigentest.cpp)

target_link_libraries (bare_eigentest
  PRIVATE ${Eigen3_LIBRARIES})

target_include_directories (bare_eigentest
  PRIVATE ${EIGEN3_INCLUDE_DIRS})

install(TARGETS bare_eigentest DESTINATION bin)
