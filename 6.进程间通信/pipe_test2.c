#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	int fd[2], fd2[2], ret, i;
	ret = pipe(fd);

	if(ret < 0) {
		perror("error");
		exit(-1);
	}
	
	ret = pipe(fd2);

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
			char buf[100] = {0};
			read(fd2[0], buf, sizeof(buf));
			printf("parent, receive: %s\n", buf);
		}
	}else if(pid == 0) {
		while(1) {
			char buf[100] = {0};
			read(fd[0], buf, sizeof(buf));
			printf("child, receive: %s\n", buf);
			write(fd2[1], "how do you do", 13);
		}
	}
	
	return 0;
}
