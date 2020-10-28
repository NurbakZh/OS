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
	int a = open("ex1.txt", O_RDWR);                 //open file ex1.txt
	const char *name = "This is a nice day";         //create text to put in
	ftruncate(a,strlen(name));          			 //change fiel till length of our text
	size_t sizE = strlen(name);
	char *maP = mmap(NULL, sizE, PROT_READ|PROT_WRITE, MAP_SHARED, a, 0); //mmap function usage
	if(maP == MAP_FAILED) printf("Map error");		 //debugging
	for(int i = 0; i <= sizE; i++) { 				 //fill the string into the file
		maP[i]=name[i];
	}
}