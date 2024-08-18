#include <stdio.h>
#include <string.h>
// char* strcat1(const char *s1, const char *s2) {
// 	char s[100];
//     int i = 0;
//     for (i = 0; i < strlen(s1); i++) {
//         s[i] = s1[i];
//     }
// 	while(*s2) {
// 		s[i] = *s2++;
// 		++i;
// 	}
// 	s[i] = '\0';
// 	return s;
// }
char* strcat2(char* dest, const char* source){
	if (dest == NULL || source == NULL){		//合法性校验
		return dest;
	}
	char* p = dest;			//将目的数组赋给p
	while (*p != '\0'){		//循环看大小
		p++;
	}
	while (*source != '\0'){			//注意指针的用法
		*p = *source;
		p++;			//依次加加进行连接
		source++;
	}
	*p = '\0';
	return dest;
}
int main(int argc, char *argv[])
{
	char s1[111] = "hello ";
	char s2[231] = "world!";
	strcat(s1, s2);	
	printf("s: %s\nstrlen(s): %ld\n", s1, strlen(s1));
}