add_executable(TestSuite)

set(TestDir "src/")
set(TestFiles "SampleTest.cpp")
list(TRANSFORM TestFiles PREPEND ${TestDir})

set(IncludeDir "include/")
set(IncludeFiles "Utils.h")
list(TRANSFORM IncludeFiles PREPEND ${IncludeDir})

target_sources(
    TestSuite
    PRIVATE
    ${TestFiles}

    PRIVATE
    FILE_SET HEADERS
    BASE_DIRS ${IncludeDir}
    FILES ${IncludeFiles}
)

if (ENABLE_STRICT)
    if(MSVC)
        target_compile_options(TestSuite PRIVATE $<$<COMPILE_LANGUAGE:CXX>:/WX /W4 /permissive- /fp:strict>)
    else()
        target_compile_options(TestSuite PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fno-omit-frame-pointer -Wall -Wextra -Werror -pedantic-errors>)
    endif()
endif()

target_include_directories(
    TestSuite PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(
    TestSuite PRIVATE
    GTest::gtest_main
    Math
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(TestSuite)