file(GLOB_RECURSE gladC **.c)
file(GLOB_RECURSE gladH **.h)

set_source_files_properties(${gladC} ${gladH} PROPERTIES LANGUAGE C)

set(QUADCOPTER_INCLUDES
    ${QUADCOPTER_INCLUDES}
    ${CMAKE_CURRENT_LIST_DIR}/glad/include
CACHE INTERNAL "")

add_library(glad STATIC ${gladC} ${gladH})
set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)

target_include_directories(glad PUBLIC
	glad/include/
)
