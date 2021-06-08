#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	execl("/usr/bin/vim","vim","abcd.txt",NULL);
	printf("ERROR!!! execl() is failed!\n");
	exit(1);
}
