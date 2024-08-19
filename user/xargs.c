#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

int main(int argc, char* argv[]) {
  char buf[MAXARG * 10];
  char c = ' ';
  int n = 0;
  while (read(0, &c, 1) > 0) {
    buf[n++] = c;
  };
  printf("buf: %s\nsizeof buf: %d\nn: %d\n", buf, sizeof buf, n);

  char parseBuf[MAXARG][MAXARG] = {0};
  int tokens = 0;
  for (int i = 0, k = -1; i < n; i++) {
    if (buf[i] != '\n') {
      parseBuf[tokens][i - k - 1] = buf[i];
    }
    else {
      tokens++;
      k = i;
    }
  }
  if (buf[n-1] != '\n') {
    tokens++;
  }

  printf("tokens: %d\nparseBuf: ", tokens);
  for (int i = 0; i < tokens; i++) {
    printf("%s\n", parseBuf[i]);
  }

  if (argc - 1 + tokens > MAXARG) {
    fprintf(2, "xargs: too many args\n");
    exit(1);
  }
  char *nargv[MAXARG];
  for (int i = 0; i < argc - 1; i++) {
    nargv[i] = argv[i + 1];
  }
  for (int i = 0; i < tokens; i++) {
    nargv[argc - 1] = parseBuf[i];
    if (fork() == 0) {
      exec(argv[1], nargv);
    }
    else {
      wait(0);
    }
  }

  exit(0);
}