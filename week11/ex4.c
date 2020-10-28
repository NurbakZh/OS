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
	int a = open("ex1.txt", O_RDWR);                  //file to take the text
	int b = open("ex1.memcpy.txt", O_RDWR);			  //file to put the text
	size_t sizE = lseek(a, 0, SEEK_END);			  //get the size of ex1.txt
	ftruncate(b, sizE); 							  //change size of ex1.memcpy.txt according to size of ex1.txt
	char *maP = mmap(NULL, sizE, PROT_READ|PROT_WRITE, MAP_SHARED, a, 0); //mmap function usage
	if(maP == MAP_FAILED) printf("Map error");		  //debugging
	char *maP1 = mmap(NULL, sizE, PROT_READ|PROT_WRITE, MAP_SHARED, b, 0); //mmap function usage
	if(maP == MAP_FAILED) printf("Map error");		  //debugging
	memcpy(maP1, maP, sizE);						  //copy text
}	