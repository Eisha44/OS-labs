#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>   
#include <time.h>   

#define NUM_THREADS 5

// Thread function
void* thread_function(void* arg) {
    int thread_num = *(int*)arg; 
    pthread_t tid = pthread_self(); 

    int sleep_time = (rand() % 3) + 1;

    printf("Thread %d started | Thread ID: %lu | Sleeping for %d seconds\n",
           thread_num, tid, sleep_time);
    sleep(sleep_time); 

    printf("Thread %d (ID: %lu) finished after %d seconds\n",
           thread_num, tid, sleep_time);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    srand(time(NULL)); 

    printf("Creating %d Threads\n\n", NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i + 1; 
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n All Threads Completed\n");
    return 0;
}