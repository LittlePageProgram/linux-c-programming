#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void) {
	pid_t ret = 0;
	ret = fork();
	if(ret > 0) {
		int fd = 0;
		fd = open("./a.txt", O_RDWR|O_CREAT, 0664);
		write(fd, "hello\n", 6);
	} else if(ret == 0) {
		int fd = 0;
		fd = open("./a.txt", O_RDWR|O_CREAT, 0664);
		write(fd, "hello\n", 6);
	}
	return 0;
}
