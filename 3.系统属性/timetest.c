#include <stdio.h>
#include <time.h>
int main() {
	time_t tm = 0;
	time(&tm);
	printf("%ld", tm);
	putchar('\n');
	char* ch = ctime(&tm);
	puts(ch);
	struct tm *t = gmtime(&tm);
	printf("%d", t->tm_sec); 
	return 0;
}
