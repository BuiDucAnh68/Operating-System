#include <pthread.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
int loop = 1;
void on_signt(){
	printf("You pressed Ctrl+C Goodbye");
	loop = 0;
}
int main(){
	loop = 1;
	printf("Hello Duc Anh");
	system("vi abc.txt");
	signal(SIGINT,on_signt);
	while(loop){}
	return 0;
}


