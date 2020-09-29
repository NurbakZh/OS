#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

int main() {
	char **s;
	char foo[] = "Hello World";
	s = malloc(sizeof(char*));
	*s = foo;
	printf("s is %p\n",s);
	s[0] = foo;
	printf("s[0] is %s\n",s[0]);
	return(0);
}