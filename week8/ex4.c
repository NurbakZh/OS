#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/resource.h>
#include <string.h>

int main() {
	int mb = 10 * pow(2,20);  //for making it in MB
	struct rusage usage;
	for (int i = 0; i < 10; i++) {
		int *pin = malloc(mb);
		memset(pin, 0, mb);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	}
	return 0;
}
