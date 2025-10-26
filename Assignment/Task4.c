/*
Name: Eisha Muzaffar
Reg. No: 23-NTU-CS-1147
Task 4 – Thread Return Values
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
// Function executed by the thread
void* computeFactorial(void* arg) {
    int n = *(int*)arg;   // Get the number
    unsigned long long *fact = malloc(sizeof(unsigned long long)); // allocate memory for result
    *fact = 1;
    for (int i = 1; i <= n; i++) {
        *fact *= i;
    }
    pthread_exit((void*)fact); // Return pointer to result
}
int main() {
    pthread_t thread;
    int num;
    unsigned long long *result;
    // Take input
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    // Create thread
    pthread_create(&thread, NULL, computeFactorial, &num);
    // Wait for thread to complete and get return value
    pthread_join(thread, (void**)&result);
    printf("Factorial of %d is: %llu\n", num, *result);
    // Free allocated memory
    free(result);
    printf("Main thread: Work completed.\n");
    return 0;
}

