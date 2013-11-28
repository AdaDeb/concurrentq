#include<stdio.h> 
#include<stdlib.h>
#include<pthread.h>
#include <time.h>
#include <sys/time.h>  
#include "concurrent_queue.h"
#include "concurrent_queue_2locks.h"


int x = 100000;
void *run_op();
int n; // number of threads


int main(int argc, char **argv)
{
   if (argc < 2)
    {
      printf("need number of threads!\n");
      return 1;
    }

  n = atoi(argv[1]);

  initialize_queue();	
  
  int i;
  struct timeval begin, end; // for time measurement

  
  pthread_t threads[n];
  
  // set seed
  srand(time(NULL));
  
  // enqueue 100 random in queue
  for(i=0;i<100;i++){
    enqueue(rand()%500);
  }
 
  gettimeofday(&begin, NULL); //start measuring time
  // spwan N threads
  i=0;
   while(i < n)
    {
      int result = pthread_create(&(threads[i]), NULL, &run_op, NULL);
      if (result != 0)
	printf("error creating a thread"); 
        i++;
    }

   i=0;
   // run random queue operations
   while(i < n)
    {
      pthread_join(threads[i], NULL);     
      i++;
    }
   gettimeofday(&end, NULL); // stop measuring time

   long sec  = end.tv_sec  - begin.tv_sec;
   long microsec = end.tv_usec - begin.tv_usec;
   long mtime = ((sec) * 1000 + microsec/1000.0) + 0.5;

   printf("Elapsed time: %ld milliseconds\n", mtime);   
   return 0;
 }

void *run_op(){
  int i;
  for(i=0;i<x/n;i++){ 
    int op = rand()%2; // pick which op to run always 0?
    printf("Op about to do: %d\n", op);   

    if (op==0)
      enqueue(rand()%500);
    else { 
      int extracted;
      dequeue(&extracted);
    }
  }
}
