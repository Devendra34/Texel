cmake_minimum_required(VERSION 3.16)
set(PROJECT "Sandbox")
project(${PROJECT} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OUTPUT_DIR "${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}/${PROJECT}")
set(TEXEL_OUTPUT_DIR "${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}/Texel")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${OUTPUT_DIR})

set(SANDBOX_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/Sandbox/src")

include_directories(SANDBOX_SRCS)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Texel/src)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Texel)

add_executable(${PROJECT} ${SANDBOX_SRCS}/SandboxApp.cpp)

target_link_libraries(${PROJECT} Texel)

if (WIN32)
    target_compile_definitions(${PROJECT} PRIVATE TEXEL_PLATFORM_WINDOWS)
endif()


if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    target_compile_definitions(${PROJECT} PUBLIC TEXEL_DEBUG TEXEL_ENABLE_ASSERTS)
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
    target_compile_definitions(${PROJECT} PUBLIC TEXEL_RELEASE)
endif()

if (WIN32)
    add_custom_command(TARGET ${PROJECT} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_BINARY_DIR}/bin/${TEXEL_OUTPUT_DIR}"
            "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
endif()
