#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
	int fd1;

	fd1 = open("data.txt", O_RDWR|O_CREAT);

	close(1);

	//dup(fd1);
	fcntl(fd1, F_DUPFD, 0);
	printf("HelloSteve");
	return 0;
}
