cmake_minimum_required(VERSION 3.10)

project(Bank-Management-System)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# source files
file(GLOB SOURCE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Gui/*.cpp
)

# includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Gui
)

# executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(SQLite3 REQUIRED)

# libraries
target_link_libraries(${PROJECT_NAME} Qt5::Widgets SQLite::SQLite3)

# On Windows, you may need to include the SQLite3 DLL in your binary directory
if (WIN32)
    add_custom_command(TARGET MyApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${SQLite3_DLL_PATH}"
        $<TARGET_FILE_DIR:MyApp>)
endif ()