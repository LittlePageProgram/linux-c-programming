#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	int fd[2], ret, i;
	ret = pipe(fd);

	if(ret < 0) {
		perror("error");
		exit(-1);
	}
	
	//printf("%d%d\n", fd[0], fd[1]);

	pid_t pid = fork();
	
	if(pid > 0) {
		while(1) {
			write(fd[1], "hi", 2);
			sleep(1);
		}
	}else if(pid == 0) {
		while(1) {
			char buf[100] = {0};
			read(fd[0], buf, sizeof(buf));
			printf("child, receive: %s\n", buf);
		}
	}
	
	return 0;
}
