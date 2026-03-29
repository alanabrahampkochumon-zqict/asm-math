add_library(Math INTERFACE)

set(IncludeDirectory include/)

set(HeaderFiles "Math.h")
list(TRANSFORM HeaderFiles PREPEND ${IncludeDirectory})
set(TemplateDefinitionFiles "Math.h")
list(TRANSFORM TemplateDefinitionFiles PREPEND ${IncludeDirectory})

target_sources(
    Math 
    INTERFACE
    
    FILE_SET HEADERS
    INCLUDE_DIRS ${IncludeDirectory}
    FILES ${HeaderFiles} ${TemplateDefinitionFiles}
)

target_link_directories(
    Math INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)