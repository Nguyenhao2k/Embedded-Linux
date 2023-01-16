all: 
	make run

server.o: server.c
	gcc -o server.o server.c

client.o: client.c
	gcc -o client.o client.c

run: server.o client.o
	gnome-terminal -- ./server.o
	gnome-terminal -- ./client.o
clear:
	rm -r server.o
	rm -r client.o
