#ifndef LIBMS_H
#define LIBMS_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define MAXLINE 1024
#define MAXNAME 36

typedef struct sockaddr SA;
void MSprint();
void MSsearch(int sock);
void MSaddBK(int sock);
void MSdeleteBK(int sock);
void MSadduser(int sock);
void MSdeleteuser(int sock);

#endif
