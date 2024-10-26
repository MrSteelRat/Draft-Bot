# Project settings
project(CppStdDiscordBot LANGUAGES CXX)

# Source files
set(DISCORDBOT_SOURCE_FILES)
file(GLOB DISCORDBOT_ALL_SOURCE_FILES
    "*.cpp"
    "*.cc"
    "*.c"
    "*.h"
    "*.hpp"
)
list(APPEND DISCORDBOT_SOURCE_FILES ${DISCORDBOT_ALL_SOURCE_FILES})

# Target settings
add_executable(${PROJECT_NAME} ${DISCORDBOT_SOURCE_FILES})
#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
#target_link_libraries(${PROJECT_NAME} PRIVATE )
