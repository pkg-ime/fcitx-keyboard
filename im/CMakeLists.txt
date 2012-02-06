include_directories (
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/xkb
    ${FCITX4_FCITX_UTILS_INCLUDE_DIRS}
    ${FCITX4_FCITX_CONFIG_INCLUDE_DIRS}
    ${FCITX4_FCITX_INCLUDE_DIRS}
    ${LIBINTL_INCLUDE_DIR}
    ${LIBXML2_INCLUDE_DIR}
    ${LIBICONV_INCLUDE_DIR}
    ${ICU_INCLUDE_DIRS}
    )

set(fcitx_keyboard_SOURCES
    keyboard.c
    isocodes.c
    keyboardconfig.c
)

fcitx_add_addon(fcitx-keyboard ${fcitx_keyboard_SOURCES})
target_link_libraries(fcitx-keyboard ${ENCHANT_LIBRARIES} ${LIBXML2_LIBRARIES} ${LIBICONV_LIBRARIES} ${ICU_LIBRARIES})

fcitx_add_addon_conf_file(fcitx-keyboard.conf)
fcitx_add_configdesc_file(fcitx-keyboard.desc)