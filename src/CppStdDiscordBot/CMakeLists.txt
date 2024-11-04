# Project settings
project(CppStdDiscordBot LANGUAGES CXX)

# Source files
set(DISCORDBOT_SOURCE_FILES)
file(GLOB DISCORDBOT_ALL_SOURCE_FILES
    "*.cpp"
    "*.hpp"
)
list(APPEND DISCORDBOT_SOURCE_FILES ${DISCORDBOT_ALL_SOURCE_FILES})

# Target settings
add_executable(${PROJECT_NAME} ${DISCORDBOT_SOURCE_FILES})
add_reference_dpp(${PROJECT_NAME})
