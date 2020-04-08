#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = 0;
	mode_t ret = 0;

	truncate("new_file.txt", 10);

	return 0;
}
