#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void print_error(char* str) {
	perror(str);
	exit(-1);
}
int main(int argc, char **argv) {
	int ret = 0;

	if(argc != 2) print_error("argc is wrong");

	
	struct stat s = {0};
	ret = stat(argv[1], &s);

	if(-1 == ret) {
		print_error("查看属性失败");
	}

	printf("%d %lu %d %ld %ld %ld\n", s.st_mode, s.st_nlink, s.st_gid, 
			s.st_uid, s.st_size, s.st_atime);
	return 9;
}
