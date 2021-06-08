#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	execl("/usr/bin/gedit","gedit","foo.c",NULL);
	printf("ERROR!!! execl() is failed\n");
	exit(0);
}
