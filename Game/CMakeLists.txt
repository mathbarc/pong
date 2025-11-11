find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


set(INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${MODELS_INCLUDE_DIR}
        ${OpenGL_INCLUDE_DIRS}
        ${GLUT_INCLUDE_DIRS}
)

file(GLOB GAME_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)

include_directories(${INCLUDE_DIRS})

add_executable(Pong ${GAME_SOURCES})
target_link_libraries(Pong ${GLUT_LIBRARIES} OpenGL::GL OpenGL::GLU)
