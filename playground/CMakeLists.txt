add_executable(Playground)

set(SrcDirectory src/)
set(SrcFiles "main.cpp")
list(TRANSFORM SrcFiles PREPEND ${SrcDirectory})

target_sources(
    Playground
    PRIVATE
    ${SrcFiles}
)

target_link_libraries(
    Playground PRIVATE 
    ASMMathLib
)

