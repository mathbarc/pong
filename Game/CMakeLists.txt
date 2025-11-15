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
target_link_libraries(Pong GLUT::GLUT OpenGL::GL OpenGL::GLU)

install(TARGETS Pong DESTINATION bin)

if(WIN32)
    install(FILES GLUT::GLUT RUNTIME DESTINATION bin)
    install(FILES OpenGL::GL RUNTIME DESTINATION bin)
    install(FILES OpenGL::GLUT RUNTIME DESTINATION bin)
endif()
