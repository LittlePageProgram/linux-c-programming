#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("arguments need port! Example: ./server 8080");
    return 1;
  }
  
  // 1. 创建socket
  int listenFd;
  if((listenFd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return -1;
  }

  // 2.服务端地址信息
  struct sockaddr_in servaddr; 
  memset(&servaddr, 0, sizeof(servaddr)); 
  servaddr.sin_family = AF_INET; // 协议族
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 任意ip
  servaddr.sin_port = htons(atoi(argv[1])); // 通讯端口
  if(bind(listenFd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
    perror("bind");
    close(listenFd);
    return -1;
  }

  // 3. socket监听模式
  if(listen(listenFd, 5) != 0) {
    perror("listen");
    close(listenFd);
    return -1;
  }

  // 4. 客户端连接
  int clientFd;
  socklen_t socklen = sizeof(struct sockaddr_in);
  struct sockaddr_in clientaddr;
  clientFd = accept(listenFd, (struct sockaddr *)&clientaddr, &socklen);
  printf("客户端(%s)已经连接\n", inet_ntoa(clientaddr.sin_addr));

  // 5. 与客户端通信
  char buffer[1024];
  while(1) {
    int iret;
    memset(buffer, 0, sizeof(buffer));
    if((iret = recv(clientFd, buffer, sizeof(buffer), 0) <= 0)) {
      printf("iret=%d\n", iret);
      break;
    }
    printf("接受: %s\n", buffer);
  }
  return 0;
}