ADD_EXECUTABLE(
        tests_sortCols
	main.c
)

TARGET_LINK_LIBRARIES(
	tests_sortCols
	nnlsm
        in_out
	m
)

INSTALL(
        TARGETS tests_sortCols
        DESTINATION bin
        PERMISSIONS     OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
                         OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE
)
