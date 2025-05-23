//
// Created by Joel Malagarriga Duarte on 25.02.25.
//

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void * thread_function1(){
  printf("Thread: Im going to KMS.\n");
  pthread_exit(NULL);
}

void * thread_function2(void* arg) {
  int num = *((int*)arg);  // Extract the argument
  free(arg);
  printf("Thread: Im going to KMS, THREAD:%d\n", num);
  sleep(num / 100);
  pthread_exit(NULL);
}

void * thread_function3(void* arg) {
  int num = *((int*)arg);  // Extract the argument
  free(arg);
  printf("Thread: Im going to KMS, THREAD:%d\n", num);
  sleep(0.5);
  pthread_exit(NULL);
}


int main(){
//-------------------------Assignment1--------------------------------------
  printf("-------------------------Assignment1--------------------------------------\n");
  pthread_t thread;
  printf("Main: Creating thread.\n");
  pthread_create(&thread, NULL, thread_function1, NULL);
  pthread_join(thread, NULL);
  printf("Main: Thread has terminated.\n");
//-------------------------Assignment2--------------------------------------
  printf("-------------------------Assignment2--------------------------------------\n");
  pthread_t threads[5];
  printf("Main: Creating threads.\n");
  for (int i = 0; i < 5; i++) {
    int* num = malloc(sizeof(int));
    *num = 5 - i;
    pthread_create(&threads[i], NULL, thread_function2, (void * )num);
    pthread_join(threads[i], NULL);
  }
//-------------------------Assignment3--------------------------------------
  printf("-------------------------Assignment3--------------------------------------\n");
  pthread_t manyThreads[1000];
  printf("Main: Creating threads.\n");
  for (int i = 0; i < 1000; i++) {
    int* num = malloc(sizeof(int));
    *num = i + 1;
    pthread_create(&manyThreads[i], NULL, thread_function3, (void * )num);
    pthread_join(manyThreads[i], NULL);
  }
  return 0;
}