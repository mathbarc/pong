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


    foreach(glut_lib ${GLUT_LIBRARIES})
        message(${glut_lib})
        get_filename_component(GLUT_LIB_DIR ${glut_lib} DIRECTORY)
        if(${GLUT_LIB_DIR})
            break()
        endif()
    endforeach()

    message("freeglut DIR: ${GLUT_LIB_DIR}")
    execute_process(COMMAND dir ${GLUT_LIB_DIR})
    execute_process(COMMAND dir ${GLUT_LIB_DIR}"/..")
    execute_process(COMMAND dir ${GLUT_LIB_DIR}"/../bin")

    # Try common DLL locations
    set(GLUT_DLL_CANDIDATES
    "${GLUT_LIB_DIR}/freeglut.dll"
    "${GLUT_LIB_DIR}/../bin/freeglut.dll"
    "${GLUT_LIB_DIR}/../lib/freeglut.dll"
    "${GLUT_LIB_DIR}/../freeglut.dll"
)
    foreach(path ${GLUT_DLL_CANDIDATES})
        if(EXISTS "${path}")
            set(GLUT_DLL "${path}")
        endif()
    endforeach()

    if(NOT GLUT_DLL)
        message(FATAL_ERROR "Could not locate freeglut DLL!")
    endif()

    message(STATUS "Found GLUT DLL: ${GLUT_DLL}")

    install(FILES "${GLUT_DLL}" DESTINATION bin)

endif()
