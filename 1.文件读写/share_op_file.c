#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
void print_error(char* str) {
	perror(str);
	exit(-1);
}
int main() {
	int fd1, fd2;

	fd1 = open("./file.txt", O_RDWR);

	if(-1 == fd1) print_error("open fail");
	
	fd2 = open("./file.txt", O_RDWR);

	if(-1 == fd2) print_error("open fail");
	return 0;
}
