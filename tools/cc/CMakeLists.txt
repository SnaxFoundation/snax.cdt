configure_file(${CMAKE_CURRENT_SOURCE_DIR}/snax-cc.cpp.in ${CMAKE_BINARY_DIR}/snax-cc.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/snax-cpp.cpp.in ${CMAKE_BINARY_DIR}/snax-cpp.cpp)

add_tool(snax-cc)
add_tool(snax-cpp)
