CC=gcc

CFLAGS=-c -Wall

all: ftpserver

ftpserver:	changeDirectory.o listDirectory.o main.o makeDirectory.o ParseCOMMAND.o removeDirectory.o replyMessage.o requestHandler.o sendFile.o showCWD.o storeFile.o terminateService.o Verification.o
			$(CC) changeDirectory.o listDirectory.o main.o makeDirectory.o ParseCOMMAND.o removeDirectory.o replyMessage.o requestHandler.o sendFile.o showCWD.o storeFile.o terminateService.o Verification.o -o ftpserver

changeDirectory.o: changeDirectory.c
			$(CC) $(CFLAGS) changeDirectory.c

listDirectory.o: listDirectory.c
			$(CC) $(CFLAGS) listDirectory.c

main.o: main.c
			$(CC) $(CFLAGS) main.c

makeDirectory.o: makeDirectory.c
			$(CC) $(CFLAGS) makeDirectory.c

ParseCOMMAND.o:	ParseCOMMAND.c
			$(CC) $(CFLAGS) ParseCOMMAND.c

removeDirectory.o:	removeDirectory.c
			$(CC) $(CFLAGS) removeDirectory.c

replyMessage.o:	replyMessage.c
			$(CC) $(CFLAGS) replyMessage.c

requestHandler.o: requestHandler.c
			$(CC) $(CFLAGS) requestHandler.c

sendFile.o:	sendFile.c
			$(CC) $(CFLAGS) sendFile.c

showCWD.o: showCWD.c
			$(CC) $(CFLAGS) showCWD.c

storeFile.o: storeFile.c
			$(CC) $(CFLAGS) storeFile.c

terminateService.o: terminateService.c
			$(CC) $(CFLAGS) terminateService.c

Verification.o: Verification.c
			$(CC) $(CFLAGS) Verification.c

clean:
	rm -rf *o ftpserver
	rm -rf ./ftpserver

run:
	./ftpserver			