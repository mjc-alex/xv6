#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
	if (argc < 2) {
    fprintf(2, "Usage: sleep n ticks...\n");
    exit(1);
	}
	int n = atoi(argv[1]);
  if (sleep(n) == -1) {
		fprintf(2, "sleep error\n");
		exit(1);
	}		
  exit(0);
}
