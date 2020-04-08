#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
	int fd = 0;
	int ret = 0;

	fd = open("./file2.txt", O_RDWR|O_CREAT|O_EXCL, 0664);
	//fd = open("./file.txt", O_RDONLY);
	if(-1 == fd) {
		printf("open fail\n");
		return 1;
	}else {
		printf("open ok\n");
	}

	char buf[] = "Steve Yu, today is nice";
	ret = write(fd, (void *)buf, sizeof(buf));
	if(ret == -1) printf("write fail\n");	

	lseek(fd, SEEK_SET, 0);

	char buf2[30] = {0};
	ret = read(fd, buf2, sizeof(buf));
	if(ret == -1) printf("read fail\n");	

	puts(buf2);

	close(fd);
	return 0;
}
