#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
char buf[] = "nabdjbwjbndaiwbdhbd";
int main() {
	int fd, ret, key, shmid;

	fd = open("./f", O_WRONLY|O_CREAT, 0664);
	if(fd == -1) {
		perror("open failed");
		return 1;
	}
	close(fd);
	// 创建共享内存
	key = ftok("./f", 'a');

	if(key == -1) {
		perror("get key failed");
		return 1;
	}

	shmid = shmget(key, 1024, 0664|IPC_CREAT);
	
	void *shmaddr = NULL;

	shmaddr = shmat(shmid, NULL, 0);

	if(shmaddr == (void*)-1) {
		perror("shmat fail");
		return 0;
	}

	sleep(10);
	while(1) {
		if(strlen((char*)shmaddr) != 0) {
			printf("%s\n", (char *)shmaddr);
			return 0;
		}
	}	
	return 0;
}
