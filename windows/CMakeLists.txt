set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_MODULE_PATH "D:\\Applications\\Qt\\5.14.2\\msvc2017_64\\lib\\cmake\\*")
#include_directories(${HEADER_LIST})

set(CMAKE_PREFIX_PATH "D:\\Applications\\Qt\\5.14.2\\msvc2017_64\\")
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB MAIN_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(SRC_LIST ${MAIN_SRC})
set(HEADER_LIST "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIBRARY_LIST Qt5::Core Qt5::Widgets)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_LIST})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_LIST})
