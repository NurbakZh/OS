#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
//what I observed: swapout(so) are always 0, and most of the swapins(si) are also 0's.
//It might show that I have big amount of RAM memory

int main() {
	size_t mb = 10 * pow(2,20); //for making it in MB
	for (int i = 0; i < 10; i++) {
		int *pin = malloc(mb);
		memset(pin, 0, mb);
		sleep(1);
	}
	return 0;
}
