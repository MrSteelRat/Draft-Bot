cmake_minimum_required(VERSION 3.15)

# Root project
project(DocumentationBots CXX)

# Project options
option(DOCBOTS_ENABLE_CPPSTD_DISCORDBOT "Enable CppStdDiscordBot" OFF)
option(DOCBOTS_ENABLE_CPPSTD_TELEGRAMBOT "Enable CppStdTelegramBot" OFF)
option(DOCBOTS_ENABLE_BOTS_SERVER "Enable BotsServer" OFF)
set(DOCBOTS_DEPENDENCIES_REPOSITORY "${CMAKE_SOURCE_DIR}/dep" CACHE STRING "Path to dependencies repository folder")
set(DOCBOTS_DEPENDENCIES_BUILD "${CMAKE_BINARY_DIR}/dep" CACHE STRING "Path to dependencies build folder")

# Common options
include("cmake/LanguageOptions.cmake")
include("cmake/OutputOptions.cmake")
include("cmake/MakeFolders.cmake")

# Programs and dependencies
include("cmake/FindGit.cmake")
include("cmake/FindDpp.cmake")

# Subprojects
add_subdirectory(src)
