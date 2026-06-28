add_executable(Playground)

set(SourceDir src/)

set(SourceFiles "main.cpp")
list(TRANSFORM SourceFiles PREPEND ${SourceDir})

target_sources(
    Playground
    PRIVATE
    ${SourceFiles}
)

target_link_libraries(
    Playground PRIVATE 
    ASMMathLib
)

