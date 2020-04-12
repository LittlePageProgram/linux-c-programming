#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
	pid_t ret = 0;
	int fd;

	fd = open("./f", O_RDWR|O_CREAT|O_TRUNC, 0664);	
	ret = fork();
	
	if(ret > 0) {
		while(1) {
			write(fd, "hello ", 6);
			sleep(1);
			write(fd, "world\n", 6);
		}
	} else if(ret == 0) {
		while(1) {
			write(fd, "hhhww ", 6);
			sleep(2);
			write(fd, "wwwww ", 6);
		}
	}
	close(fd);	
	return 0;
}
