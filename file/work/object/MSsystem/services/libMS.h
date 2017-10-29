#ifndef LIBMS_H
#define LIBMS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <mysql/mysql.h>
#define RIO_BUFSIZE 8192
#define LISTENQ 1024
#define MAXLIEN 1024
#define MAXNAME 36
#define MAXPWD  32
#define MAXQUERY 1024
#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "931210"
#define DATABASE "mysql"
typedef struct sockaddr SA;
typedef struct
{
  int rio_fd;
  int rio_cnt;
  char* rio_bufptr;
  char rio_buf[RIO_BUFSIZE];
} rio_t;
typedef struct
{
  int maxfd;
  int maxi;
  int nready;
  int clientfd[FD_SETSIZE];
  rio_t clientrio[FD_SETSIZE];
  fd_set read_set;
  fd_set ready_set;
}pool;

ssize_t rio_readn(int fd,void* usrbuf,size_t n);
ssize_t rio_writen(int fd,void* usrbuf,size_t n);
void rio_readinib(rio_t* rp,int fd);
static ssize_t rio_read(rio_t* rp,char* usrbuf,size_t n);
ssize_t rio_readlineb(rio_t* rp,void* usrbuf,size_t maxlen);
ssize_t rio_readnb(rio_t* rp,void* usrbuf,size_t n);
int open_listenfd(int port);
void init_pool(int listenfd,pool* p);
void add_client(int connfd,pool* p);
void check_clients(pool* p,MYSQL* BKmysql);
int login(int sock,MYSQL* usermysql,char* user);
int MSquery(int sock,char* name,MYSQL* mysql);
int MSinsert(int sock,char* msg,MYSQL* mysql,char* tables);
int MSdelete(int sock,char* msg,MYSQL* mysql,char* tables);
#endif 

