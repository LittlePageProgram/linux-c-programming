#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int fd = 0, ret = 0;
	
	fd = open("./file.txt", O_RDONLY);
	
	if(-1 == fd) {
		perror("file open failed");
		exit(-1);
	}

	ret = lseek(fd, 0, SEEK_END);
	
	printf("文件大小%d\n", ret);
	return 0;
}

//int open(const char *pathname, int flags);
