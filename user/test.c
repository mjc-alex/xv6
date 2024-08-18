#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

int main(int argc, char *argv[])
{
	char s1[111] = "hello ";
	char *s2 = "world!";
	//strcat(s1, s2);	
	printf("%s %d\n", s1, strlen(s1));
	printf("%d %d\n", strlen(s1), strlen(s2));
	exit(0);
}
