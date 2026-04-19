cmake_minimum_required(VERSION 3.25)
project(ASMMath LANGUAGES CXX ASM_MASM)

add_library(ProjectStrictWarnings INTERFACE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Clang Formatter
find_program(CLANG_FORMATTER NAMES clang-format)

if(CLANG_FORMATTER)
    file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h *.cxx *.hxx *.hpp *.cc *.hh *.tpp *.inl)

    add_custom_target(format
        COMMAND ${CLANG_FORMATTER} -i -style=file ${ALL_SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Formatting source files..."
    )
else()
    message(WARNING "clang-format not found")
endif()

option(ENABLE_STRICT "Enable ASan and Strict Warnings" OFF) # To turn on ASan, use cmake -D

# Doxygen
find_package(Doxygen)
if (DOXYGEN_FOUND)
    message(STATUS "Doxygen found!")
    doxygen_add_docs(
        docs
        ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating documentation with doxygen..."
        CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
        ALL
    )
else()
    message(WARN "Doxygen not found! Skipping documentation generation.")
endif()

# Turn on solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Enables Address Sanitizer for all the projects globally.
if(ENABLE_STRICT)
    message(STATUS "Turning on Address Sanitizer")
    if(MSVC)
        add_compile_options($<$<COMPILE_LANGUAGE:CXX>:/fsanitize=address>)
        target_compile_options(ProjectStrictWarnings INTERFACE $<$<COMPILE_LANGUAGE:CXX>:/WX /W4 /permissive- /fp:strict>)
    else()
        add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fsanitize=address>)
        add_link_options(-fsanitize=address)
        target_compile_options(ProjectStrictWarnings INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-fno-omit-frame-pointer -Wall -Wextra -Werror -pedantic-errors>)
    endif()
endif()

include(dependencies.cmake)

add_subdirectory(asm-math)
add_subdirectory(benchmark-suite)
add_subdirectory(playground)
add_subdirectory(test-suite)

target_link_libraries(ASMMathLib PRIVATE ProjectStrictWarnings)
target_link_libraries(TestSuite PRIVATE ProjectStrictWarnings)
target_link_libraries(BenchmarkSuite PRIVATE ProjectStrictWarnings)
target_link_libraries(Playground PRIVATE ProjectStrictWarnings)

set_target_properties(format docs PROPERTIES FOLDER "Dev Tools")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Playground)