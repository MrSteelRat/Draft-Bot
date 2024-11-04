# Find Git
find_package(Git)
if(Git_FOUND)
    message("Git found: ${GIT_EXECUTABLE}")
else()
    message(ERROR
        "Git not found!\n"
        "Install Git using command:\n"
        "\n"
        "    sudo apt install git"
    )
endif()
