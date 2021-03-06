#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>

#define LISTENQ 1024

typedef struct sockaddr SA;

int open_listenfd(int port)
{
  int listenfd,optval=1;
  struct sockaddr_in serveraddr;
  
  if((listenfd=socket(AF_INET,SOCK_STREAM,0))<0)
     return -1;
  if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(const void*)&optval,sizeof(int))<0)
     return -1;
  bzero((char*)&serveraddr,sizeof(serveraddr));
  serveraddr.sin_family=AF_INET;
  serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
  serveraddr.sin_port=(htons((unsigned short)port));
  if(bind(listenfd,(SA*)&serveraddr,sizeof(serveraddr))<0)
     return -1;
  if(listen(listenfd,LISTENQ)<0)
     return -1;
  return listenfd;
}

