#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <float.h>

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	int a, b;
	printf("Enter your a and b, dividing them by space\n");
	scanf("%d %d", &a, &b); 
	swap(&a,&b);
	printf("your new a is: %d\n",a);
	printf("your new b is: %d\n",b);
}
