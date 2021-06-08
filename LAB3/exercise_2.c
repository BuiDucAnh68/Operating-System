#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;
	int num_coconuts = 17;
	pid=fork();
	if(pid==0)
	{
		num_coconuts = 42;
		exit(0);
	}
	else
	{
		wait(NULL);
	}
	printf("I see %d coconuts!\n",num_coconuts);
	exit(0);
}
