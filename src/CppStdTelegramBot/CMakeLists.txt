# Project settings
project(CppStdTelegramBot LANGUAGES CXX)

find_package(TgBot REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(CURL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

# Source files
set(TELEGRAMBOT_SOURCE_FILES)
file(GLOB TELEGRAMBOT_ALL_SOURCE_FILES
    "*.cpp"
    "*.cc"
    "*.c"
    "*.h"
    "*.hpp"
)
list(APPEND TELEGRAMBOT_SOURCE_FILES ${TELEGRAMBOT_ALL_SOURCE_FILES})

# Target settings
add_executable(${PROJECT_NAME} ${TELEGRAMBOT_SOURCE_FILES})
#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(${PROJECT_NAME} PRIVATE TgBot::TgBot ssl crypto pthread yaml-cpp Boost::system)
