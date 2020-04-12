#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
int main() {
	int ret, fd;
	char buf[100] = {0};

	ret  = mkfifo("./fifo1", 0664);
	if(ret == -1) {
		perror("wrong");
		return 0;
	}

	fd = open("./fifo1", O_WRONLY|O_CREAT, 0664);
	if(fd == -1) {
		perror("open wrong");
		return 0;
	}

	while(1) {
		bzero(buf, sizeof(buf));
		scanf("%s", buf);
		write(fd, buf, sizeof(buf));
	}
	return 0;
}
