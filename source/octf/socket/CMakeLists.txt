add_subdirectory(internal)
target_sources(octf
PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/SocketFactory.cpp
	${CMAKE_CURRENT_LIST_DIR}/ISocketConnection.h
	${CMAKE_CURRENT_LIST_DIR}/SocketManager.cpp
	${CMAKE_CURRENT_LIST_DIR}/SocketFactory.h
	${CMAKE_CURRENT_LIST_DIR}/ISocketClient.h
	${CMAKE_CURRENT_LIST_DIR}/SocketConfig.h
	${CMAKE_CURRENT_LIST_DIR}/SocketManager.h
	${CMAKE_CURRENT_LIST_DIR}/ConnectionTransceiver.cpp
	${CMAKE_CURRENT_LIST_DIR}/ISocketListener.h
	${CMAKE_CURRENT_LIST_DIR}/SocketConfig.cpp
	${CMAKE_CURRENT_LIST_DIR}/ConnectionTransceiver.h
	${CMAKE_CURRENT_LIST_DIR}/ISocketConnection.cpp
	${CMAKE_CURRENT_LIST_DIR}/ISocketServer.h
	${CMAKE_CURRENT_LIST_DIR}/IConnectionTransceiverListener.h
)
