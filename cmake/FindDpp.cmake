# Add reference to DPP
function(add_reference_dpp TARGET_NAME)
    # Source parameters
    set(DPP_SOURCE_PATH "${DOCBOTS_DEPENDENCIES_REPOSITORY}/dpp")
    set(DPP_BUILD_PATH "${DOCBOTS_DEPENDENCIES_BUILD}/dpp")
    set(DPP_VERSION "10.0.33")
    set(DPP_REPOSITORY "https://github.com/brainboxdotcc/DPP.git")
    set(DPP_TARGET_NAME "dpp")

    # Fetch dependency
    if(NOT EXISTS ${DPP_SOURCE_PATH})
        execute_process(
            COMMAND ${GIT_EXECUTABLE} clone --depth 1 --branch v${DPP_VERSION} ${DPP_REPOSITORY} ${DPP_SOURCE_PATH}
        )
    endif()

    # Build parameters
    set(BUILD_VOICE_SUPPORT OFF)
    set(DPP_BUILD_TEST OFF)
    set(DPP_NO_CONAN ON)
    set(DPP_NO_VCPKG ON)

    # Add subproject
    add_subdirectory(${DPP_SOURCE_PATH} ${DPP_BUILD_PATH})

    # Add reference
    add_dependencies(${TARGET_NAME} ${DPP_TARGET_NAME})
    target_include_directories(${TARGET_NAME} PRIVATE ${DPP_SOURCE_PATH}/include)
    target_link_libraries(${TARGET_NAME} PRIVATE ${DPP_TARGET_NAME})
endfunction()
