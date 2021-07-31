
all: server client

main: client.cpp server.cpp Corridor.cpp
	g++ -std=c++11 -o server Corridor.cpp server.cpp -lpthread -I.
	g++ -std=c++11 -o client client.cpp -lpthread -I.

open_client:
	@vim client.cpp
open_server:
	@vim server.cpp
server:
	@g++ -std=c++11 -o server server.cpp -lpthread -I.
client:
	@g++ -std=c++11 -o client client.cpp -lpthread -I.

