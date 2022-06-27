file(GLOB_RECURSE QuadcopterSources **.cpp **.h **.vert **.frag)
file(GLOB_RECURSE QuadcopterHeaders **.h)

add_executable(Quadcopter ${QuadcopterSources})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders/)

target_include_directories(Quadcopter PUBLIC
    ${QUADCOPTER_INCLUDES}
    ${QuadcopterHeaders}
)

target_link_libraries(Quadcopter PUBLIC
    glad
    glfw
    ${GLFW_LIBRARIES}
)
