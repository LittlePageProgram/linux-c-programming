#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = 0;
	mode_t ret = 0;

	// 掩码改为0
	ret = umask(0);
	printf("old mask: %d\n", ret);


	fd = open("./new_file.txt", O_RDWR|O_CREAT, 0777);
	if(-1 == fd) {
		perror("open fail\n");
		return 1;
	}
	return 0;
}
