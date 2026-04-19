add_library(ASMMathLib STATIC)

set(IncludeDirectory include/)

set(HeaderFiles "Scalars.h;MathConcepts.h")
list(TRANSFORM HeaderFiles PREPEND ${IncludeDirectory})
set(TemplateDefinitionFiles "Scalars.tpp")
list(TRANSFORM TemplateDefinitionFiles PREPEND ${IncludeDirectory})

set (ScalarASMDir src/scalars/)
set(ScalarASMFiles "add.asm;")
list(TRANSFORM ScalarASMFiles PREPEND ${ScalarASMDir})

target_compile_features(ASMMathLib INTERFACE cxx_std_20)
set_target_properties(ASMMathLib PROPERTIES INTERFACE_CXX_STANDARD_REQUIRED ON)

target_sources(
    ASMMathLib 

    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${IncludeDirectory}
    FILES ${HeaderFiles} ${TemplateDefinitionFiles}

    PRIVATE
    ${ScalarASMFiles}
)

target_include_directories(
    ASMMathLib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

source_group(
    TREE "${CMAKE_CURRENT_SOURCE_DIR}/src"
    PREFIX "Source Files"
    FILES ${ScalarASMFiles}
)
