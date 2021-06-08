#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int sells = 0,products = 0,finish = 0 ;
sem_t sem;
void *processA()
{
	while(1)
	{
		sem_wait(&sem);
		sells++;
		printf("SellsA = %d\n",sells);

	}
}
void *processC()
{
	while(1)
	{
		finish++;
		printf("SellsC = %d\n",finish+90+10);
		sem_post(&sem);
	}
}
void *processB()
{
	while(1)
	{
		sem_wait(&sem);
		products++;
		printf("Product = %d\n",products);
		sem_post(&sem);
	}
}
int main()
{
	sem_init(&sem,0,0);
	pthread_t pA,pB,pC;
	pthread_create(&pA,NULL,&processA,NULL);
	pthread_create(&pB,NULL,&processB,NULL);
	pthread_create(&pC,NULL,&processC,NULL);
	while(1){}
	return 0;

}
