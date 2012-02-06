include_directories(
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/xkb
    ${PROJECT_SOURCE_DIR}/im
    ${FCITX4_FCITX_UTILS_INCLUDE_DIRS}
    ${FCITX4_FCITX_CONFIG_INCLUDE_DIRS}
    ${FCITX4_FCITX_INCLUDE_DIRS}
    ${LIBXML2_INCLUDE_DIR}
    )

add_executable(testrules
    testrules.c
    ../xkb/rules.c
    )

target_link_libraries(testrules ${FCITX4_FCITX_UTILS_LIBRARIES} ${LIBXML2_LIBRARIES})
    
add_executable(testisocodes
    testisocodes.c
    ../im/isocodes.c
    )

target_link_libraries(testisocodes ${FCITX4_FCITX_UTILS_LIBRARIES} ${LIBXML2_LIBRARIES})

add_test(NAME testrules
         COMMAND testrules "${CMAKE_CURRENT_SOURCE_DIR}/evdev.xml")
add_test(NAME testisocodes
         COMMAND testisocodes)