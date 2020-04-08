#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
	int fd = 0;
	int ret = 0;

	fd = open("./file.txt", O_RDWR|O_TRUNC);
	//fd = open("./file.txt", O_RDONLY);
	if(-1 == fd) {
		printf("open fail\n");
		return 1;
	}else {
		printf("open ok\n");
	}
}
