#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int x = INT_MAX;
	double y = DBL_MAX;
	float z = FLT_MAX;

	printf("size of integer is %ld\n", sizeof(x));
	printf("max value of integer is %d\n", x);
	printf("size of double is %ld\n", sizeof(y));
	printf("max value of double is %g\n", y);
	printf("size of float is %ld\n", sizeof(z));
	printf("max value of float is %g\n", z);
}
