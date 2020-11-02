all: server client

server:
	cc -o server server.c

client:
	cc -o client client.c

clean:
	rm server client
