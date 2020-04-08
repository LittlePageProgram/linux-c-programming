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
	ret = lstat(argv[1], &s);

	if(-1 == ret) {
		print_error("查看属性失败");
	}
	
	/* 获取文件属性 */
	printf("%d %lu %d %ld %ld %ld\n", s.st_mode, s.st_nlink, s.st_gid, 
			s.st_uid, s.st_size, s.st_atime);
	
	/* 打印文件类型 */
	char file_type = '0';

	if(S_ISLNK(s.st_mode)) file_type = 'l'; // link
	else if(S_ISREG(s.st_mode)) file_type = '-'; // regular
	else if(S_ISDIR(s.st_mode)) file_type = 'd'; // dictionary
	else if(S_ISCHR(s.st_mode)) file_type = 'c'; // char
	else if(S_ISBLK(s.st_mode)) file_type = 'b'; // block
	else if(S_ISFIFO(s.st_mode)) file_type = 'p'; // pipe
	else if(S_ISSOCK(s.st_mode)) file_type = 's'; // socket
	
	putchar(file_type);

	char buf[10] = { '\0' };
	char tmp_buf[] = "rwxrwxrwx";
	/*
	if(s.st_mode & S_IRUSR) buf[0] = 'r';
	else buf[0] = '-';
	if(s.st_mode & S_IWUSR) buf[1] = 'w';
	else buf[1] = '=';
	*/
	int i = 0;
	for(i = 0; i <= 8; i++) {
		if(s.st_mode & (1 << (8 - i))) buf[i] = tmp_buf[i];
		else buf[i] = '-';
	}
	printf("%s", buf);
	putchar('\n');
	return 9;
}
