cmake_minimum_required(VERSION 3.16)
set(PROJECT "Texel")
project(${PROJECT} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OUTPUT_DIR "${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}/${PROJECT}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${OUTPUT_DIR})

set(TEXEL_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(THIRD_PARTY_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/third-party")

file(GLOB_RECURSE FILE_SOURCES "${TEXEL_SRCS}/*.h" "${TEXEL_SRCS}/*.cpp")

include_directories(${TEXEL_SRCS})
include_directories(${THIRD_PARTY_SRCS}/spdlog/include)
include_directories(${THIRD_PARTY_SRCS}/glfw/include)
include_directories(${THIRD_PARTY_SRCS}/glad/include)
include_directories(${THIRD_PARTY_SRCS}/imgui/)
include_directories(${THIRD_PARTY_SRCS}/imgui/backends)


file(GLOB FILES_IMGUI_SOURCES "${THIRD_PARTY_SRCS}/imgui/*.h"
        "${THIRD_PARTY_SRCS}/imgui/*.cpp"
        "${THIRD_PARTY_SRCS}/imgui/backends/imgui_impl_glfw.cpp"
        "${THIRD_PARTY_SRCS}/imgui/backends/imgui_impl_opengl2.cpp"
        "${THIRD_PARTY_SRCS}/imgui/backends/imgui_impl_opengl3.cpp")

set(CMAKE_POSITION_INDEPENDENT_CODE 1)

add_subdirectory(${THIRD_PARTY_SRCS}/spdlog)
add_subdirectory(${THIRD_PARTY_SRCS}/glfw)
add_subdirectory(${THIRD_PARTY_SRCS}/glad)

find_package(OpenGL REQUIRED)

add_library(${PROJECT} SHARED ${FILE_SOURCES} ${FILES_IMGUI_SOURCES})

target_link_libraries(${PROJECT} spdlog glfw glad ${OPENGL_LIBRARY})

if (WIN32)
    target_compile_definitions(${PROJECT} PRIVATE TEXEL_PLATFORM_WINDOWS TEXEL_BUILD_DLL)
endif()


if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    target_compile_definitions(${PROJECT} PUBLIC TEXEL_DEBUG TEXEL_ENABLE_ASSERTS)
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
    target_compile_definitions(${PROJECT} PUBLIC TEXEL_RELEASE)
endif()

# target_precompile_headers(${PROJECT} PRIVATE src/texel_pch.h)
