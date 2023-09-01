project(app)

include_directories("../vendor/glfw/include")
include_directories("../vendor/glad/include")
include_directories(${IMGUI_INC_DIR})
include_directories((${GLM_INC_DIR}))

add_executable(${PROJECT_NAME} 
                "main.cpp"
                ${GLAD_SRCS}
                ${IMGUI_SRC})

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

add_dependencies(${PROJECT_NAME} glfw imgui)

target_link_libraries(${PROJECT_NAME} 
                glfw 
                imgui
                )

# test
add_executable(test "test.cpp")
target_include_directories(test PUBLIC ${STB_INC_DIR})