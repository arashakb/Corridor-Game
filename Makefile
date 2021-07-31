
all: server client

open_client:
	@vim client.cpp
open_server:
	@vim server.cpp
server:
	@g++ -std=c++11 -o server server.cpp -lpthread -I.
client:
	@g++ -std=c++11 -o client client.cpp -lpthread -I.

