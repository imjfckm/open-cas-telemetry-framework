cmake_minimum_required(VERSION 3.9)
project(test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

enable_testing()
find_package (Threads)

add_executable(octf-tests "")
set_target_properties(octf-tests PROPERTIES EXCLUDE_FROM_ALL TRUE)

find_package(Protobuf 3.0 REQUIRED)
target_include_directories(octf-tests
	SYSTEM PRIVATE ${PROTOBUF_INCLUDE_DIR}
)

add_subdirectory(octf)

target_include_directories(octf-tests
	PUBLIC
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/source/
    ${CMAKE_BINARY_DIR}/source
)

target_link_libraries(octf-tests
    ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} gtest_main octf
)

add_custom_target(run-unit-tests
    COMMAND octf-tests
)
