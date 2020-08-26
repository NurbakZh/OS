#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main() {
	printf("Hello, please enter the number for figure:\n 1 - Rectangle, 2 - Right Triangle, 3 - right-side-up triangle and 4 - triangle on vertical:\n");
	int j;
	scanf("%d", &j);
	if(j==3) {
		printf("Now enter number of elements for height: ");
		int a;	
		scanf("%d",&a);
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
	}	
	else if(j==1) {
		printf("Enter height and width by space: ");
		int h,w;
		scanf("%d %d", &h,&w);
		for(int i = 0; i < h; i++) {
			for(int f = 0; f < w; f++) {
				printf("*");	
			}
			printf("\n");
		}
	}
	else if(j==2) {
		printf("Now enter number of elements for height: ");
		int a;
		scanf("%d",&a);
		for(int i = 1; i <= a; i++) {
			for(int f = 1; f <= i; f++) {
				printf("*");
			}
			printf("\n");
		}
	}
	else if(j==4) {
			printf("Now enter number of elements for height: ");
			int a;
			scanf("%d",&a);
			int f;
			for(int i = 1; i <= a; i++) {
				if(i<a/2+1) {
					for(f = 1; f <= i; f++) {
						printf("*");
					}
					printf("\n");
				}
				if(i>a/2 && a%2==0) {
					for(int k = a/2 - (i-a/2)+1 ; k > 0 ; k--) {
						printf("*");
					}
					printf("\n");
				}
				if(i>a/2 && a%2!=0) {
				int k;
					for(k = a/2 - (i-a/2)+2; k > 0 ; k--) {
						printf("*");
					}
					printf("\n");
				}
			}
		}
	else {
		printf("please reload the program and enter one of the 4 presented numbers: {1,2,3,4}\n"); 
	}
	return 0;
}

