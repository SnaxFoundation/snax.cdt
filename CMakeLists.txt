cmake_minimum_required(VERSION 3.5)
project(snax_cdt)

find_program(SCCACHE_FOUND sccache)
if (SCCACHE_FOUND)
   message(STATUS "Using sccache")
   set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE sccache)
   set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK sccache)
else()
   find_program(CCACHE_FOUND ccache)
   if (CCACHE_FOUND)
      message(STATUS "Using ccache")
      set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
      set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
   endif()
endif()


set(VERSION_MAJOR 1)
set(VERSION_MINOR 6)
set(VERSION_PATCH 1)
#set(VERSION_SUFFIX rc2)

if (VERSION_SUFFIX)
   set(VERSION_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}-${VERSION_SUFFIX}")
else()
   set(VERSION_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
endif()

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
   message(WARNING "CMAKE_INSTALL_PREFIX is set to default path of ${CMAKE_INSTALL_PREFIX}, resetting to ${CMAKE_INSTALL_PREFIX}/snax.cdt")
   set(CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}/snax.cdt")
elseif ("${CMAKE_INSTALL_PREFIX}" STREQUAL "/usr/local")
   message(WARNING "CMAKE_INSTALL_PREFIX is explicitly set to /usr/local. This is not recommended.")
endif()

include(GNUInstallDirs)

include(modules/ClangExternalProject.txt)
include(modules/ToolsExternalProject.txt)

set(WASM_SDK_BUILD true)

### Configure the SnaxWasmToolchain.cmakes
set(CDT_ROOT_DIR ${CMAKE_BINARY_DIR})
configure_file(${CMAKE_SOURCE_DIR}/modules/snax.cdt-config.cmake ${CMAKE_BINARY_DIR}/lib/cmake/snax.cdt/snax.cdt-config.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/SnaxCDTMacros.cmake.in ${CMAKE_BINARY_DIR}/lib/cmake/snax.cdt/SnaxCDTMacros.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/SnaxWasmToolchain.cmake.in ${CMAKE_BINARY_DIR}/lib/cmake/snax.cdt/SnaxWasmToolchain.cmake @ONLY)

set(CDT_ROOT_DIR ${CMAKE_INSTALL_PREFIX})
configure_file(${CMAKE_SOURCE_DIR}/modules/snax.cdt-config.cmake ${CMAKE_BINARY_DIR}/modules/snax.cdt-config.cmake @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/modules/snax.cdt-config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/snax.cdt)
configure_file(${CMAKE_SOURCE_DIR}/modules/SnaxCDTMacros.cmake.in ${CMAKE_BINARY_DIR}/modules/SnaxCDTMacros.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/SnaxWasmToolchain.cmake.in ${CMAKE_BINARY_DIR}/modules/SnaxWasmToolchain.cmake @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/modules/SnaxWasmToolchain.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/snax.cdt)
install(FILES ${CMAKE_BINARY_DIR}/modules/SnaxCDTMacros.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/snax.cdt)

set(CDT_ROOT_DIR "_PREFIX_")
configure_file(${CMAKE_SOURCE_DIR}/modules/SnaxCDTMacros.cmake.in ${CMAKE_BINARY_DIR}/modules/SnaxCDTMacrosPackage.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/SnaxWasmToolchain.cmake.in ${CMAKE_BINARY_DIR}/modules/SnaxWasmToolchainPackage.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/snax.cdt-config.cmake ${CMAKE_BINARY_DIR}/modules/snax.cdt-config.cmake.package @ONLY)

include(modules/LibrariesExternalProject.txt)

include(modules/InstallCDT.cmake)

configure_file(${CMAKE_SOURCE_DIR}/imports/snax.imports.in ${CMAKE_BINARY_DIR}/snax.imports COPYONLY)
install(FILES ${CMAKE_BINARY_DIR}/snax.imports DESTINATION ${CMAKE_INSTALL_PREFIX})

configure_file(${CMAKE_SOURCE_DIR}/scripts/ricardsnax/ricardsnax.py ${CMAKE_BINARY_DIR}/scripts/ricardsnax.py COPYONLY)
install(FILES ${CMAKE_BINARY_DIR}/scripts/ricardsnax.py DESTINATION ${CMAKE_INSTALL_PREFIX}/scripts)

# section for package construction
set(VENDOR "block.one")
set(PROJECT_NAME "snax.cdt")
set(DESC "Toolchain and supporting tools for the SNAX platform")
set(URL "https://github.com/snax/snax.cdt")
set(EMAIL "support@block.one")
configure_file(${CMAKE_SOURCE_DIR}/scripts/generate_package.sh.in ${CMAKE_BINARY_DIR}/packages/generate_package.sh @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/scripts/generate_deb.sh ${CMAKE_BINARY_DIR}/packages/generate_deb.sh COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/scripts/generate_bottle.sh ${CMAKE_BINARY_DIR}/packages/generate_bottle.sh COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/scripts/generate_rpm.sh ${CMAKE_BINARY_DIR}/packages/generate_rpm.sh COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/scripts/generate_tarball.sh ${CMAKE_BINARY_DIR}/packages/generate_tarball.sh COPYONLY)

# add licenses
configure_file(${CMAKE_SOURCE_DIR}/snax_llvm/LICENSE.TXT ${CMAKE_BINARY_DIR}/licenses/llvm.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/libraries/boost/boost.license ${CMAKE_BINARY_DIR}/licenses/boost.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/tools/external/wabt/LICENSE ${CMAKE_BINARY_DIR}/licenses/wabt.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/tools/jsoncons/LICENSE ${CMAKE_BINARY_DIR}/licenses/jsoncons.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/LICENSE ${CMAKE_BINARY_DIR}/licenses/snax.cdt.license COPYONLY)

include(modules/TestsExternalProject.txt)

include(CTest)
enable_testing()
add_subdirectory(tests)
