/*######################################
# University of Information Technology #
# IT007 Operating System #
# <Your name>, <your Student ID> #
# File: example_thread_structure.c #
######################################*/
#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 2

struct struct_print_parms{
char character;
int count;
};
void* char_print (void* args) {
struct struct_print_parms* p = (struct struct_print_parms*) args;
int i;
for (i=0; i <p->count; i++)
printf ("%c\n", p->character);
return NULL;
}
int main () {
pthread_t tid;
struct struct_print_parms th_args;
th_args.character = 'X';
th_args.count = 5;
pthread_create(&tid, NULL, &char_print, &th_args);
pthread_join (tid, NULL);
return 0;
}
