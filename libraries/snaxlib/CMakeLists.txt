file(GLOB HEADERS "*.hpp"
                  "*.h")

add_library(snax
            snaxlib.cpp
            crypto.cpp
            ${HEADERS})

add_library(snax_malloc
            malloc.cpp
            ${HEADERS})

add_library(snax_dsm
            simple_malloc.cpp
            ${HEADERS})

add_library(snax_cmem
            memory.cpp
            ${HEADERS})

add_native_library(native_snax
                   snaxlib.cpp
                   crypto.cpp
                   malloc.cpp
                   ${HEADERS})

set_target_properties(snax_malloc PROPERTIES LINKER_LANGUAGE C)

target_include_directories(snax PUBLIC
                                 ${CMAKE_SOURCE_DIR}/libc/musl/include
                                 ${CMAKE_SOURCE_DIR}/libc/musl/src/internal
                                 ${CMAKE_SOURCE_DIR}/libc/musl/src/crypt
                                 ${CMAKE_SOURCE_DIR}/libc/musl/arch/snax
                                 ${CMAKE_SOURCE_DIR}/libcxx/include
                                 ${CMAKE_SOURCE_DIR}
                                 ${CMAKE_SOURCE_DIR}/boost/include)

target_link_libraries( snax c c++ )
add_dependencies( native_snax snax )

add_custom_command( TARGET snax POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:snax> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET snax_malloc POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:snax_malloc> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET snax_dsm POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:snax_dsm> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET snax_cmem POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:snax_cmem> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET native_snax POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:native_snax> ${BASE_BINARY_DIR}/lib )

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../snaxlib DESTINATION ${BASE_BINARY_DIR}/include FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
