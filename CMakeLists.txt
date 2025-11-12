cmake_minimum_required(VERSION 3.25)

project("Pong" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(Models)
add_subdirectory(Game)

# Include CPack
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "Pong")
#set(CPACK_PACKAGE_VENDOR "MyCompany")
set(CPACK_PACKAGE_CONTACT "matheus.barcelos@solv.tec.br")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Pong")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
#set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
#set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

if(LINUX)
    # Common install location defaults
    set(CPACK_INSTALL_PREFIX "/usr")
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")

    # --- Linux: .deb ---
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER ".Solv") # required
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libglut3 (>= 3.12)")
    set(CPACK_DEBIAN_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})
    set(CPACK_DEBIAN_PACKAGE_SECTION "games")
    set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
    set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

    # --- Linux: AppImage ---
    # Note: CPackAppImage is available since CMake 3.21+
    set(CPACK_GENERATOR "${CPACK_GENERATOR};AppImage")
    set(CPACK_APPIMAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-x86_64.AppImage")
    #set(CPACK_APPIMAGE_DESKTOP_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Pong.desktop")
    #set(CPACK_APPIMAGE_ICON_FILE "${CMAKE_CURRENT_SOURCE_DIR}/resources/icon.svg")


elseif(WIN32)
    # --- Windows: NSIS installer ---
    set(CPACK_GENERATOR "${CPACK_GENERATOR};NSIS")
    set(CPACK_NSIS_PACKAGE_NAME "Pong")
    set(CPACK_NSIS_DISPLAY_NAME "Pong ${PROJECT_VERSION}")
    set(CPACK_NSIS_CONTACT "matheus.barcelos@solv.tec.br")
    set(CPACK_NSIS_MENU_LINKS "bin\\Pong.exe" "Pong game")
    set(CPACK_NSIS_HELP_LINK "https://github.com/mathbarc/pong")
    set(CPACK_NSIS_URL_INFO_ABOUT "https://github.com/mathbarc/pong")
    #set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/resources/appicon.ico")
    #set(CPACK_NSIS_MUI_UNIICON "${CMAKE_CURRENT_SOURCE_DIR}/resources/appicon.ico")
endif()
# --- Final inclusion ---
include(CPack)
