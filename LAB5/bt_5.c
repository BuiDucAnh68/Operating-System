#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

sem_t p0,p1,p2,p3,p4,p5,p6;
int x1 = 1,x2 =2,x3=3,x4=4,x5=5,x6=6;
int x,y,z,w,v;
int ans = 0;

void *ProcessA()
{
	w =x1 *x2;
	printf("w = %d\n",w);
	sem_post(&p0);
}
void *ProcessB()
{
	v = x3 * x4;
	printf("v = %d\n",v);
	sem_post(&p1);
}

void  *ProcessC()
{
	sem_wait(&p1);
	y = v * x5;
	printf("y=%d\n",y);
	sem_post(&p2);
}
void *ProcessD()
{
	z = v *x6;
	printf("z = %d\n",z);
	sem_post(&p3);

}
void *ProcessE()
{
	sem_wait(&p2);
	y = w *y;
	printf("y =%d\n",y);
	sem_post(&p4);
}

void *ProcessF()
{
	sem_wait(&p3);
	z =w *z;
	printf("z = %d\n",z);
	sem_post(&p5);
}
void *ProcessG()
{
	sem_wait(&p5);
	ans = y+z;
	printf("ans = %d\n",ans);
	sem_post(&p6);
}

int main()
{
	sem_init(&p0,0,0);
	sem_init(&p1,0,0);
	sem_init(&p2,0,0);
	sem_init(&p3,0,0);
	sem_init(&p4,0,0);
	sem_init(&p5,0,0);
	sem_init(&p6,0,0);
	pthread_t pA,pB,pC,pD,pE,pF,pG;
	pthread_create(&pA,NULL,&ProcessA,NULL);
	pthread_create(&pB,NULL,&ProcessB,NULL);
	pthread_create(&pC,NULL,&ProcessC,NULL);
	pthread_create(&pD,NULL,&ProcessD,NULL);
	pthread_create(&pE,NULL,&ProcessE,NULL);
	pthread_create(&pF,NULL,&ProcessF,NULL);
	pthread_create(&pG,NULL,&ProcessG,NULL);
	while(1){}
	return 0;
}
