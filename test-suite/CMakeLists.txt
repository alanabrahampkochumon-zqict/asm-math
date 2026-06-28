add_executable(TestSuite)

set(TestDir "src/")
set(IncludeDir "include/")


set(TestFiles "ScalarTests.cpp;MathConceptsTests.cpp")
list(TRANSFORM TestFiles PREPEND ${TestDir})

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


target_include_directories(
    TestSuite PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(
    TestSuite PRIVATE
    GTest::gtest_main
    ASMMathLib
)


include(GoogleTest)
gtest_discover_tests(TestSuite)