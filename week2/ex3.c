#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main() {
	int a;
	scanf("%d", &a);
	int c = a-1;
	for(int i = 1; i<=2*a-1; i=i+2) {
		int f = 0;
		while(f<c) {
			printf("%c",' ');
			f++;
		}
		int g = 0;
		while(g<i) {
			printf("%c",'*');
			g++;
		}
		while(f>0) {
			printf("%c",' ');
			f--;
		}
		printf("\n");
		c--;
	}
	return 0;
}
