#ifndef PROJ_FTP_H
#define PROJ_FTP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/dir.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define USER 1
#define PASS 2
#define MKD  3
#define CWD  4
#define RMD  5
#define PWD  6
#define RETR 7
#define STOR 8
#define LIST 9
#define ABOR 10
#define QUIT 11
#define NOOP 12
#define DELE 13
#define CDUP 14
#define HELP 15
#define INVALID 0
#define MAXLINE 1024

#define PORT 10075

extern char USERNAME[10][100];
extern char PASSWORD[10][100];
extern struct stat st;
extern char arg[1024];
extern int command;
extern bool logged_in;
extern int newSocket;
extern bool user_done;
extern char list[1024];
extern char file_name[100];
extern char file[1024];
extern int store_port[1000];
extern char pwdbuf[256];
extern int count;

void split(char *pathname);
char *reply_message(int status);
int verify_username(char *username);
int verify_password(char *password);
void parseCommand(char *buf);
int make_directory(char *directory);
int change_directory(char *directory);
int show_cwd();
int remove_directory(const char *path_name);
int list_directories();
int send_file(char * filename);
void split(char *pathname);
int store_file(char *pathname);
int exit_service();
int abort_service();
int request_handler(char *arg);

#endif