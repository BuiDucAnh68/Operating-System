#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<time.h>

int x = 0;

void *ProcessA()
{
	while(1)
	{
		x = x + 1;
		if(x ==20)
			x =0;
		printf("PA: x= %d\n",x);
	}
}

void *ProcessB()
{
	while(1)
	{
		x =x +1;
		if(x == 20)
			x = 0;
		printf("PB: x = %d\n",x);
	}
}
int main()
{
	pthread_t pA,pB;
	pthread_create(&pA,NULL,&ProcessA,NULL);
	pthread_create(&pB,NULL,&ProcessB,NULL);
	while(1){}
	return 0;
}
