#include <unistd.h>
#include <stdio.h>
int main() {
	int ret = 0;
	char buf[30] = {0};
	ret = read(0, (void *)buf, 30);
	if(-1 == ret) {
		perror("read fail");
		return -1;
	}
	puts(buf);
	return 0;
}
