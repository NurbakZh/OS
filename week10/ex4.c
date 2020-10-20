#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
	//open directory tmp
	char n[] = "tmp";
	DIR* dirp = opendir(n);
	if(dirp == NULL) return -1;
	struct dirent *dp;
	struct stat s;
	//to parse files till the last file in the tmp directory
	while((dp=readdir(dirp))!=NULL) {
		char a[128];
		//add file name to a array, for creating a path to it
		strcpy(a,n);
		strcat(a,"/");
		strcat(a,dp->d_name);
		//search for files with more than one hard links to it
		//also add exception of adding the current and previous 
		//directories("." && "..")
		if((!stat(a,&s)) && s.st_nlink > 1 && strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")) {
			printf("File: %s Its' i-node:%llu\n", dp->d_name, dp->d_ino);
		}
		
	}
	return 0;
}