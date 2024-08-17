#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[2];
int main(int argc, char* argv[]) {
	int p1[2], p2[2];
	
	pipe(p1);
	pipe(p2);
	if (fork() == 0) {
		close(0);
		int fd = dup(p1[0]);
		close(p1[0]);
		close(p1[1]);
		read(fd, buf, 2);
		printf("%d: received ping\n", getpid());
		close(fd);
//		write(1, buf, 1);
//		printf("%c\n", buf[0]);

		//close(p1[1]);
		//read(p1[0], buf, 2);
		//close(p1[0]);
		//printf("%d: received ping\n", getpid());

		close(p2[0]);
		write(p2[1], buf, 1);
		close(p2[1]);	
	}
	else {
		close(p1[0]);
		write(p1[1], "m\n", 2);
		close(p1[1]);
		wait(0);
		
		//close(p2[1]);
		//read(p2[0], buf, 1);
		//close(p2[0]);
		//printf("%d: received pong\n", getpid());

		close(0);
		int fd = dup(p2[0]);
		close(p2[0]);
		close(p2[1]);
		read(fd, buf, 1);
		printf("%d: received pong\n", getpid());
		close(fd);
//		printf("%c\n", buf[0]);
	}
	exit(0);
}
