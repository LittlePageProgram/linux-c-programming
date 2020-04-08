#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
	int fd = 1, ret = 0;

	char buf[] = "steve\n";
	write(fd, buf, sizeof(buf));

	close(fd);
	return 0;
}
