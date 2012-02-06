cmake_minimum_required(VERSION 2.6)

project(fcitx-xkb)

option(ENABLE_TEST "Enable Unit test" Off)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(Fcitx 4.2.0 REQUIRED)
find_package(LibXml2 REQUIRED)
find_package(X11 REQUIRED)
find_package(XkbFile REQUIRED)
find_package(Enchant REQUIRED)
find_package(IsoCodes REQUIRED)
find_package(Gettext REQUIRED)
find_package(Libiconv REQUIRED)
find_package(ICU REQUIRED)

if (NOT X11_Xkb_FOUND)
    message(FATAL_ERROR "Xkb is needed")
endif (NOT X11_Xkb_FOUND)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -fvisibility=hidden ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -fvisibility=hidden ${CMAKE_CXX_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed ${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "-Wl,--as-needed ${CMAKE_MODULE_LINKER_FLAGS}")
add_definitions(-D_GNU_SOURCE)

set(LOCALEDIR ${CMAKE_INSTALL_PREFIX}/share/locale)

find_program(some_x_program NAMES iceauth xrdb xterm)
if (NOT some_x_program)
    set(some_x_program /usr/bin/xrdb)
    message("Warning: Could not determine X binary directory. Assuming /usr/bin.")
endif (NOT some_x_program)
get_filename_component(proto_xbindir "${some_x_program}" PATH)
get_filename_component(XBINDIR "${proto_xbindir}" ABSOLUTE)
get_filename_component(xrootdir "${XBINDIR}" PATH)
set(XLIBDIR "${xrootdir}/lib/X11")

configure_file(config.h.in config.h)

add_subdirectory(xkb)
add_subdirectory(im)
add_subdirectory(po)

if (ENABLE_TEST)
    enable_testing()
    add_subdirectory(test)
endif(ENABLE_TEST)