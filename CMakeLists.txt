project(chess)

set(code_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/code/main.cpp
	
	${PROJECT_SOURCE_DIR}/code/GameManager.h
	${PROJECT_SOURCE_DIR}/code/ViewManager.h
	${PROJECT_SOURCE_DIR}/code/Player.h
	${PROJECT_SOURCE_DIR}/code/Position.h
	${PROJECT_SOURCE_DIR}/code/King.h
	${PROJECT_SOURCE_DIR}/code/Queen.h
	${PROJECT_SOURCE_DIR}/code/Knight.h
	${PROJECT_SOURCE_DIR}/code/Bishop.h
	${PROJECT_SOURCE_DIR}/code/Pawn.h
	${PROJECT_SOURCE_DIR}/code/Rook.h
)

add_executable(chess ${code_SRC_LIST})