project(Bank-Management-System)

# source
file(GLOB SOURCE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/app/Gui/*.cpp
)

# includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/app/include
    ${CMAKE_CURRENT_SOURCE_DIR}/app/Gui/include
)

# executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets SQLite::SQLite3)