#include <unistd.h>
#include <string.h>
#include <errno.h>
#ifndef RIO_H
#define RIO_H

#define RIO_BUFSIZE 8192
typedef struct
{
  int rio_fd;
  int rio_cnt;
  char* rio_bufptr;
  char rio_buf[RIO_BUFSIZE];
} rio_t;
ssize_t rio_readn(int fd,void* usrbuf,size_t n);
ssize_t rio_writen(int fd,void* usrbuf,size_t n);
void rio_readinib(rio_t* rp,int fd);
static ssize_t rio_read(rio_t* rp,char* usrbuf,size_t n);
ssize_t rio_readlineb(rio_t* rp,void* usrbuf,size_t maxlen);
ssize_t rio_readnb(rio_t* rp,void* usrbuf,size_t n);
#endif 
