#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
	long mtype;
	char mtext[1024];
};
int main(int argc, char **argv) {
	int msgid;
	key_t key;
	int fd, ret;
	char msg_buf[1024];
	long recv_msgtype;

	if(argc != 2) {
		perror("argc err, input msgtype");
		return 1;
	}
	recv_msgtype = atol(argv[1]);	

	fd = open("./f", O_RDWR|O_CREAT, 0664);
	close(fd);


	key = ftok("./f", 'a');
	msgid = msgget(key, 0664|IPC_CREAT);

	ret = fork();
	if(ret > 0) {
		struct msgbuf m;
		// 发送消息
		while(1){
			bzero(&m, sizeof(m));
			// 从键盘读取消息封装消息包
			scanf("%[^\n]", m.mtext);
			printf("input msgtype\n");
			scanf("%ld", &m.mtype);
			msgsnd(msgid, &m, 1024, 0);
		}
	} else if(ret == 0){
		struct msgbuf m;
		// 接受
		while(1){
			bzero(&m, sizeof(m));
			msgrcv(msgid, &m, 1024, recv_msgtype, 0);
			printf("%ld:%s\n", m.mtype, m.mtext);
		}
	}
	
	return 0;
}
