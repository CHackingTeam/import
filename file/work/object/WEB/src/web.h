#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rio.h"

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#ifndef WEB_H
#define WEB_H

#define LISTENQ 64

#define MAXLEN  1024
#define MAXBUF  1024
#define MAXLINE 1024

extern char** environ;
typedef struct sockaddr SA;

int open_listenfd(int fd);
void doit(int fd);
void clienterror(int fd,char* cause,char* errnum,char* shortmsg,char* longmsg);
void read_requesthdrs(rio_t* rp);
int parse_uri(char* uri,char* filename,char* cgiargs);
void server_static(int fd,char* filename,int filesize);
void get_filetype(char* filename,char* filetype);
void server_dynamic(int fd,char* filename,char* cgiargs);

#endif

