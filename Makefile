CC = g++
CFLAGS= -I.
DEPS = Corridor.h
OBJ = server.o Corridor.o 
all: server client

server: $(OBJ)
	$(CC) -std=c++11 -o $@ $^ -lpthread $(CFLAGS)

client: client.cpp
	$(CC) -std=c++11 -o client $< -lpthread $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -std=c++11 -c -o $@ $< -lpthread $(CFLAGS)

clean:
	rm -f *.o server client

