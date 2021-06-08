#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid =fork();
	if(pid == 0)
		printf("Child process,pid = %d\n",pid);
	else{
		wait(NULL);
		printf("Parent process,pid =%d <-- This is PID of child process\n",pid);
	}
	exit(0);
}
