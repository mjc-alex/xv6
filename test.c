#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//int
//atoi(const char *s)
//{
//  int n;
//
//  n = 0;
//  while('0' <= *s && *s <= '9')
//    n = n*10 + *s++ - '0';
//  return n;
//}

int atoi(const char *s) {
	int ans = 0;
	for (int i = strlen(s) - 1; i >= 0; i--) {
		ans += (s[i] - '0') * pow(10, (strlen(s) - i - 1));	
	}
	return ans;
}
int main() {
//	char s[10];
//	scanf("%s", s);
//  int n = atoi(s);		
//	printf("%d\n", n);
	int p[10];
	*p = 10;
	printf("%d, %d, %d, %d", *p, p, *p + 1, *(p+1)); 	
	return 0;
}
