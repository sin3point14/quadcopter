file(GLOB_RECURSE QuadcopterSources **.cpp **.h)
file(GLOB_RECURSE QuadcopterHeaders **.h)

add_executable(Quadcopter ${QuadcopterSources})

target_include_directories(Quadcopter PUBLIC
    ${QUADCOPTER_INCLUDES}
    ${QuadcopterHeaders}
)

target_link_libraries(Quadcopter PUBLIC
    glad
    glfw
    ${GLFW_LIBRARIES}
)
