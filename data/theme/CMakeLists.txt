SET(THEME_SRCS
	panel.css 
	pasteboard-delete-bg.png 
	pasteboard-delete-hover.png 
	pasteboard-delete.png 
	pasteboard-item-delete-hover.png 
	pasteboard-item-delete.png 
	pasteboard-item-hover.png 
	pasteboard-items-list-bg.png 
	pasteboard-search-bg.png 
	placeholder-bg.png 
	search-entry-bg.png 
	search-entry-clear-hover.png 
	search-entry-clear.png 
	search-entry-separator.png
    )

INSTALL(FILES ${THEME_SRCS} DESTINATION ${PKG_DATADIR}/gogoo-panel-pasteboard/theme)



