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

get_target_property(GL_DLL OpenGL::GL IMPORTED_LOCATION_RELEASE)
if(GL_DLL)
    message(STATUS "GL runtime: ${GL_DLL}")
    install(FILES "${GL_DLL}" DESTINATION bin)
endif()


get_target_property(GLU_DLL OpenGL::GLU IMPORTED_LOCATION_RELEASE)
if(GLU_DLL)
    message(STATUS "GLU runtime: ${GLU_DLL}")
    install(FILES "${GLU_DLL}" DESTINATION bin)
endif()


get_target_property(GLUT_DLL GLUT::GLUT IMPORTED_LOCATION_RELEASE)
if(GLUT_DLL)
    message(STATUS "GLUT runtime: ${GLUT_DLL}")
    install(FILES "${GLUT_DLL}" DESTINATION bin)
endif()
