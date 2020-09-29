#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

int main() {
	int a;
	int* ar;
	printf("please enter the number of elements in ur arrrray:");
	scanf("%d", &a);
	ar = (int*)malloc(a * sizeof(int));
	for(int i = 0; i < a; i++) {
		ar[i]=i;
		printf("%d ",ar[i]);
	}
	printf("\n");
	free(ar);
	exit(1);
}