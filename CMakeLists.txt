# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
project(opengui)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

#glad
aux_source_directory(${PROJECT_SOURCE_DIR}/vendor/glad/src/ GLAD_SRCS)

# imgui
set(IMGUI_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/ ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends)
file(GLOB IMGUI_SRC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.* 
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3* 
)

# glm
set(GLM_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm/glm-0.9.9.7/glm )

# stb
set(STB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb)

# 包含子项目。
add_subdirectory("app")
add_subdirectory("vendor")
