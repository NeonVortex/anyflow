cmake_minimum_required(VERSION 3.1)

project(anyflow LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DASIO_STANDALONE -pthread")
#add_definitions(-DASIO_STANDALONE)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(COMPILER_FLAGS
    _WIN32_WINNT=0x0601
    ASIO_STANDALONE
    $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
    )

file(GLOB MAIN_SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB MAIN_UI "${PROJECT_SOURCE_DIR}/src/*.ui")
set(SRC_LIST ${MAIN_UI} ${MAIN_SRC})

set(HEADER_LIST
    "include"
    "${PROJECT_SOURCE_DIR}/../asio-1.12.2/include"
    )

set(LIB_LIST
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    )
if(MINGW)
    set(LIB_LIST ${LIB_LIST} ws2_32)
endif()

#include_directories(${HEADER_LIST})
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${COMPILER_FLAGS})
target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_LIST})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_LIST})
