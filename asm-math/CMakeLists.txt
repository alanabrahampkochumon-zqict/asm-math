add_library(Math STATIC)

set(IncludeDirectory include/)

set(HeaderFiles "Math.h")
list(TRANSFORM HeaderFiles PREPEND ${IncludeDirectory})
set(TemplateDefinitionFiles "Math.h")
list(TRANSFORM TemplateDefinitionFiles PREPEND ${IncludeDirectory})

set (ScalarASMFolder src/scalars/)
set(ScalarASMFiles "add.asm;")
list(TRANSFORM ScalarASMFiles PREPEND ${ScalarASMFolder})

target_sources(
    Math 

    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${IncludeDirectory}
    FILES ${HeaderFiles} ${TemplateDefinitionFiles}

    PRIVATE
    ${ScalarASMFiles}
)

target_include_directories(
    Math PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

source_group(
    TREE "${CMAKE_CURRENT_SOURCE_DIR}/src"
    PREFIX "Source Files"
    FILES ${ScalarASMFiles}
)

# add_custom_target(
#     MathInterface 
#     ALL 
#     SOURCES ${HeaderFiles}
# )