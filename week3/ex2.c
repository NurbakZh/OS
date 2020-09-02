#include <stdio.h>

void bubble_sort(int d[], int c) 
{ 
	int l;
	for (int f = 0; f<c-1; f++)  { 
		for (int k = 0; k<c-1; k++) { 
			if (d[k] > d[k+1]) {
              l = d[k];
              d[k] = d[k+1];
              d[k+1] = l; 
              }
    	}
    }
} 

int main() {
	int a;
	printf("what are your favorable number of elements in array? \n");
	scanf("%d",&a);
	int b[a];
	for(int i = 0; i<a; i++) {
		scanf("%d", &b[i]);
	}
	int c = sizeof(b)/sizeof(b[0]);
	bubble_sort(b,c);
	printf("here is you new array: \n");
	for(int j = 0; j<c; j++) {
		printf("%d ", b[j]);
	}
	return 0;
}

