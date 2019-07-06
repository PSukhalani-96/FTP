#ifndef FTP_CLIENT_H
#define FTP_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define PROMPT "FTP>> "
#define PORT 10075
#define MAXLINE 1024

extern char buf[1024];
extern char file_name[1024];
extern int clientSocket;
extern char buffer[1024];

void store_command();
void pass_command();
void quit_command();
void retr_result();
void abor_command();
void store_file(char *dest, char file[1024]);

#endif