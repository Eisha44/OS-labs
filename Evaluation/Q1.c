// Question 1/1
// Write a C program that uses threads to perform operations on shared variables:
// 1.  Create two global variables:
//   initialized to 0
//   initialized to 0
// 2.  Create 3 threads:
//     Thread 1: Adds all of the numbers between 1 to 100 to 100 times
//    Thread 2: Adds all of the numbers between 101 to 200 to 100 times
//    Thread 3: Adds all of the numbers between 201 to 300 to 100 times
// 3.  Use mutex to protect access to both shared variables
// 4.  Each thread prints when it starts and finishes
// 5.  Main thread prints final results:
//   Total sum (should be 45150, which is sum of 1 to 300)   Total count (should be 300)
#include <stdio.h>
#include <pthread.h>
long long totalSum = 0;   
int totalCount = 0;      
pthread_mutex_t lock;     

typedef struct {
    int start; 
    int end;
} Range;

void* addNumbers(void* arg) {
    Range* r = (Range*)arg; //typecasting 
    int start = r->start;
    int end = r->end;

    printf("Thread for range %d,%d started.\n", start, end);
    for (int i = 0; i < 100; i++) {      //numbers ko 100 times print karna hai
        for (int num = start; num <= end; num++) { //range k according karein
            pthread_mutex_lock(&lock);     
            totalSum += num;             
            totalCount++;                  
            pthread_mutex_unlock(&lock);  
        }
    }

    printf("Thread for range %d,%d finished.\n", start, end);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    pthread_mutex_init(&lock, NULL);

    Range r1 = {1, 100};
    Range r2 = {101, 200};
    Range r3 = {201, 300};
   
    pthread_create(&t1, NULL, addNumbers, &r1);
    pthread_create(&t2, NULL, addNumbers, &r2);
    pthread_create(&t3, NULL, addNumbers, &r3);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_mutex_destroy(&lock);
    printf("\nFinal Results:\n");
    printf("Final Total sum is given by: %lld\n", totalSum);
    printf("Final Total Count is Given by:%d\n", totalCount);

return 0;
}
