#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]) {
	setvbuf(stdout, NULL, _IOLBF, BUFSIZ); //_IOLBF - line buffered.
	printf("%c", 'H'); sleep(1);
	printf("%c", 'e'); sleep(1);
	printf("%c", 'l'); sleep(1);
	printf("%c", 'l'); sleep(1);
	printf("%c", 'o'); sleep(1);
}