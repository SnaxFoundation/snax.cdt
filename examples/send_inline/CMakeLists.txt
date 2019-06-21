include(ExternalProject)
# if no cdt root is given use default path
if(SNAX_CDT_ROOT STREQUAL "" OR NOT SNAX_CDT_ROOT)
   find_package(snax.cdt)
endif()

ExternalProject_Add(
   send_inline_project
   SOURCE_DIR ${CMAKE_SOURCE_DIR}/src
   BINARY_DIR ${CMAKE_BINARY_DIR}/send_inline
   CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=${SNAX_CDT_ROOT}/lib/cmake/snax.cdt/SnaxWasmToolchain.cmake
   UPDATE_COMMAND ""
   PATCH_COMMAND ""
   TEST_COMMAND ""
   INSTALL_COMMAND ""
   BUILD_ALWAYS 1
)