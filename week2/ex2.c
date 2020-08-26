#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <string.h>


int main() {
	char banana[1000], new[1000];
	int start = 0, c = 0;
	printf("Enter your word:\n");
	gets(banana);
	while(banana[c] != '\0') c++;
	int end = c-1;
	while(start<c) {
		new[start] = banana[end];
		end--; start++;	
	}
	new[start] = '\0';
	printf("Your new word: %s\n", new);
	return 0;
}
