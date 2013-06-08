ADD_SUBDIRECTORY(theme)

########### Add .desktop target ###############
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/gogoo-panel-pasteboard.desktop.in"
  "${CMAKE_CURRENT_BINARY_DIR}/gogoo-panel-pasteboard.desktop"
  IMMEDIATE @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/gogoo-panel-pasteboard.desktop DESTINATION share/mutter-neetbook/panels)

