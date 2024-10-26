# Project settings
project(BotsServer LANGUAGES CXX)

# Source files
set(BOTSSERVER_SOURCE_FILES)
file(GLOB BOTSSERVER_ALL_SOURCE_FILES
    "*.cpp"
    "*.cc"
    "*.c"
    "*.h"
    "*.hpp"
)
list(APPEND BOTSSERVER_SOURCE_FILES ${BOTSSERVER_ALL_SOURCE_FILES})

# Target settings
add_executable(${PROJECT_NAME} ${BOTSSERVER_SOURCE_FILES})
#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
#target_link_libraries(${PROJECT_NAME} PRIVATE )
