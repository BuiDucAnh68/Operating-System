#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 2

void*thread_print(void*threadid)
{
	long tid;
	tid=(long)threadid;
	printf("Hello IT007! I'm Thread #%ld !!!\n",tid);
	sleep(100);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int check;
	long tID;

	for(tID=0;tID < NUM_THREADS;tID++){
		printf("I'm Main Thread: Create Thread: #%ld",tID);
		check=pthread_create(
				&threads[tID],
				NULL,
				thread_print,
				(void*)tID);
		if(check !=0){
			printf("ERROR!!!I'm Main Thread, I can't create Thread  #%ld",tID);
			exit(-1);
		}
		pthread_join(threads[tID],NULL);
	}
	pthread_exit(NULL);
}
