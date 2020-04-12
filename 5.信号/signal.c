#include <stdio.h>
#include <signal.h>
void signal_fun(int signo) {
	printf("SIGINT signo=%d", signo);
	putchar('\n');
}
int main() {
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, SIG_DFL);
	signal(SIGINT, signal_fun);
	while(1) {}
	return 0;
}
