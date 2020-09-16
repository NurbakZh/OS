#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define Num_Of_Threads 10  

void *iam(void *threadik) {
	printf("I am thread of number %ld\n", threadik);
	pthread_exit(NULL);
}

int main() {
	pthread_t thread[Num_Of_Threads];  
	for(int i = 0; i < Num_Of_Threads; i++) {
    	printf("Thread of number %d is borning\n", i);
    	if(pthread_create(thread+i, NULL, iam, (void *)i)) {
      		printf("ERRRRRRROR: can't born a thread\n");
          exit(-1);
    	}
    	pthread_join(thread[i], NULL);
  	}
  	pthread_exit(NULL);
}
