#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

int x = 0;
pthread_mutex_t mutex;

void *ProcessA()
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		x = x + 1;
		if(x ==20)
			x =0;
		printf("PA: x= %d\n",x);
		pthread_mutex_unlock(&mutex);
	}
}

void *ProcessB()
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		x =x +1;
		if(x == 20)
			x = 0;
		printf("PB: x = %d\n",x);
		pthread_mutex_unlock(&mutex);
	}
}
int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_t pA,pB;
	pthread_create(&pA,NULL,&ProcessA,NULL);
	pthread_create(&pB,NULL,&ProcessB,NULL);
	while(1){}
	return 0;
}
