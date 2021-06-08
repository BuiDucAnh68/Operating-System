#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<semaphore.h>

sem_t sem;
int n,i=0,count = 0 , a[10000];
void *processA()
{
	while(1)
	{
		if(count < n)
		{
			i++;
			a[i] = rand() %(n-1);
			count++;
			printf("\n pA: Number of elements in array a: %d",count);
		}
		sem_post(&sem);
	}
}

void *processB()
{
	while(1)
	{
		sem_wait(&sem);
		if(count == 0)
			printf("\nKhong co gia tri trong mang a");
		else
		{
			count--;
			int b =a[0];
			for(int j =0 ;j<n;j++)
				a[j]= a[j+1];
			printf("\npB:Number of elements in array a: %d",count);

		}
			
	}
}

int main()
{
	sem_init(&sem,0,0);
	pthread_t pA,pB;
	printf("Nhap n:");
	scanf("%d",&n);
	pthread_create(&pA,NULL,&processA,NULL);
	pthread_create(&pB,NULL,&processB,NULL);
	while(1){}
	return 0;
	
}
