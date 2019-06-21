cmake_minimum_required( VERSION 3.5 )

set(SNAX_VERSION_MIN "1.4")
set(SNAX_VERSION_SOFT_MAX "1.4")
#set(SNAX_VERSION_HARD_MAX "")

find_package(snax)

### Check the version of snax
set(VERSION_MATCH_ERROR_MSG "")
SNAX_CHECK_VERSION(VERSION_OUTPUT "${SNAX_VERSION}"
                                   "${SNAX_VERSION_MIN}"
                                   "${SNAX_VERSION_SOFT_MAX}"
                                   "${SNAX_VERSION_HARD_MAX}"
                                   VERSION_MATCH_ERROR_MSG)
if(VERSION_OUTPUT STREQUAL "MATCH")
   message(STATUS "Using snax version ${SNAX_VERSION}")
elseif(VERSION_OUTPUT STREQUAL "WARN")
   message(WARNING "Using snax version ${SNAX_VERSION} even though it exceeds the maximum supported version of ${SNAX_VERSION_SOFT_MAX}; continuing with configuration, however build may fail.\nIt is recommended to use snax version ${SNAX_VERSION_SOFT_MAX}.x")
else() # INVALID OR MISMATCH
   message(FATAL_ERROR "Found snax version ${SNAX_VERSION} but it does not satisfy version requirements: ${VERSION_MATCH_ERROR_MSG}\nPlease use snax version ${SNAX_VERSION_SOFT_MAX}.x")
endif(VERSION_OUTPUT STREQUAL "MATCH")


enable_testing()

configure_file(${CMAKE_SOURCE_DIR}/contracts.hpp.in ${CMAKE_BINARY_DIR}/contracts.hpp)

include_directories(${CMAKE_BINARY_DIR})

file(GLOB INT_TESTS "*.cpp" "*.hpp")

add_snax_test( integration_tests ${INT_TESTS} )
