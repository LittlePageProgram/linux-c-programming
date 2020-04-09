#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
int main() {
	struct passwd *pw;
 	pw = getpwuid(1);
	
	printf("%s:%s:%d:%d:%s:%s:%s", pw->pw_name, pw->pw_passwd, pw->pw_uid, pw->pw_gid, pw->pw_gecos, pw->pw_dir, pw->pw_shell);
	putchar('\n');
	return 0;
}
