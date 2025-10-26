/*
Name: Eisha Muzaffar
Reg. No: 23-NTU-CS-1147
Task 3 – Number Info Thread
*/
#include <stdio.h>
#include <pthread.h>
// Function executed by the thread
void* numberInfo(void* arg) {
    int num = *(int*)arg; // Dereference pointer to get the number

    printf("Thread: The number is %d\n", num);
    printf("Thread: Square = %d\n", num * num);
    printf("Thread: Cube = %d\n", num * num * num);

    pthread_exit(NULL); // Exit thread cleanly
}
int main() {
    pthread_t thread;
    int number;
    // Take user input
    printf("Enter an integer: ");
    scanf("%d", &number);
    // Create a thread and pass number as argument
    pthread_create(&thread, NULL, numberInfo, &number);
    // Wait for thread to complete
    pthread_join(thread, NULL);
    printf("Main thread: Work completed.\n");
    return 0;
}
