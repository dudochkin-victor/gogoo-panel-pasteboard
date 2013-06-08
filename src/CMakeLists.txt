SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 0)
SET(VERSION_PATCH 0)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${MPL_INCLUDE_DIRS}
    )


SET (PROGRAMS gogoo-panel-pasteboard)

ADD_DEFINITIONS(-DLOCALEDIR="${LOCALEDIR}")
ADD_DEFINITIONS(-DMX_CACHE="${DATADIR}/mx.cache")
ADD_DEFINITIONS(-DTHEMEDIR="${PKG_DATADIR}/${PROGRAMS}/theme")
ADD_DEFINITIONS(-DGETTEXT_PACKAGE="${GETTEXT_PACKAGE}")
ADD_DEFINITIONS(-DDATADIR="${PKG_DATADIR}/${PROGRAMS}")

SET(PROGRAM_SRCS
	mnb-clipboard-item.c 		
	mnb-clipboard-item.h 		
	mnb-clipboard-store.c 		
	mnb-clipboard-store.h 		
	mnb-clipboard-view.c 		
	mnb-clipboard-view.h 		
	meego-panel-pasteboard.c
    )

SET(PROGRAM_HEADERS
    )

SET(MARSHALS
        ${CMAKE_CURRENT_BINARY_DIR}/mnb-pasteboard-marshal.c
        ${CMAKE_CURRENT_BINARY_DIR}/mnb-pasteboard-marshal.h
)

########### Add marshal target ###############
ADD_CUSTOM_COMMAND(
   OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/mnb-pasteboard-marshal.h
   COMMAND glib-genmarshal --prefix=mnb_pasteboard_marshal --header ${CMAKE_SOURCE_DIR}/src/mnb-pasteboard-marshal.list > ${CMAKE_CURRENT_BINARY_DIR}/mnb-pasteboard-marshal.h
   )

ADD_CUSTOM_COMMAND(
   OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/mnb-pasteboard-marshal.c
   COMMAND glib-genmarshal --prefix=mnb_pasteboard_marshal --body ${CMAKE_SOURCE_DIR}/src/mnb-pasteboard-marshal.list --body > ${CMAKE_CURRENT_BINARY_DIR}/mnb-pasteboard-marshal.c
   DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/mnb-pasteboard-marshal.h
   )

ADD_EXECUTABLE(${PROGRAMS} ${PROGRAM_SRCS} ${PROGRAM_HEADERS} ${MARSHALS})

   
TARGET_LINK_LIBRARIES(${PROGRAMS}
    ${MPL_LIBRARIES}
    )

INSTALL(TARGETS ${PROGRAMS} RUNTIME DESTINATION ${PKG_LIBEXECDIR})

########### Add .desktop target ###############
#CONFIGURE_FILE(
#  "${CMAKE_CURRENT_SOURCE_DIR}/meego-panel-internet.desktop.in"
#  "${CMAKE_CURRENT_BINARY_DIR}/meego-panel-internet.desktop"
#  IMMEDIATE @ONLY)
#INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/meego-panel-internet.desktop DESTINATION share/mutter-netbook/panels)

########### Add .service target ###############
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/com.meego.UX.Shell.Panels.pasteboard.service.in"
  "${CMAKE_CURRENT_BINARY_DIR}/com.meego.UX.Shell.Panels.pasteboard.service"
  IMMEDIATE @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/com.meego.UX.Shell.Panels.pasteboard.service DESTINATION share/dbus-1/services)


