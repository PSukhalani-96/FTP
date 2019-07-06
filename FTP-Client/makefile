CC=gcc

CFLAGS=-c -Wall

all: ftpclient

ftpclient:	main.o passCommand.o quitCommand.o retrCommand.o sendFile.o
			$(CC) main.o passCommand.o quitCommand.o retrCommand.o sendFile.o -o ftpclient

main.o:	main.c
		$(CC) $(CFLAGS) main.c

passCommand.o:	passCommand.c
		$(CC) $(CFLAGS) passCommand.c

quitCommand.o:	quitCommand.c
		$(CC) $(CFLAGS) quitCommand.c

retrCommand.o:	retrCommand.c
		$(CC) $(CFLAGS) retrCommand.c

sendFile.o:	sendFile.c
		$(CC) $(CFLAGS) sendFile.c

clean:
	rm -rf *o ftpclient
	rm -rf ./ftpclient

run:
	./ftpclient 127.0.0.1