#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

#define N 34
int buf[N];

void panic(char *s)
{
  fprintf(2, "%s\n", s);
  exit(1);
}

int fork1(void)
{
  int pid;

  pid = fork();
  if(pid == -1)
    panic("fork");
  return pid;
}

void sieve(int round, int nums[], int n) {
	if (n == 0) return;
	int p[2];	
	if (pipe(p) < 0) {
		panic("pipe");
	}

	if (fork1() == 0) {
		close(0);
		int fd = dup(p[0]);
		close(p[0]);
		close(p[1]);

		int cnt = 0, x = 0;
		do {
			x = read(fd, buf + cnt / 4, 4);
			cnt += x;
			//printf("x = %d ", x);
		}while (x > 0);
		if (cnt == 0) {
			return;
		}	
		else if(cnt < 0) {
			panic("read");
		}
		else{
			//for (int i = 0; i < cnt / 4; i++) {
			//	printf("%d ", buf[i]);
			//}
			sieve(n--, buf, cnt / 4);
		}
		close(fd);
	}
	else {
		int x = nums[0];	
		printf("prime %d\n", x);
		close(p[0]);
		for (int i = 0; i < n; i++) {
			if (nums[i] % x != 0) {
				write(p[1], nums + i, 4);
			}
		}
		close(p[1]);		
		wait(0);
	}

}


int main(int argc, char *argv[]) {
	int nums[N];
	for (int i = 0; i < N; i++) {
		nums[i] = i + 2;
	}	
	sieve(N, nums, N);
	exit(0);
}
