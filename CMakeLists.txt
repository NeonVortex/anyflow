cmake_minimum_required(VERSION 3.1)

project(anyflow LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB MAIN_SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
set(SRC_LIST ${MAIN_SRC})
set(HEADER_LIST "include")
set(LIBRARY_LIST Qt5::Core Qt5::Widgets)

#include_directories(${HEADER_LIST})
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_LIST})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_LIST})
