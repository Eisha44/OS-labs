/*
 * Task 2 – Personalized Greeting Thread
 * Name: Eisha Muzaffar
 * Reg No: 23-NTU-CS-1147
 * Description:
 * This program creates a thread that prints a personalized greeting
 * message using the user's name passed as an argument.
 */

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

// Thread function to print greeting
void* greet(void* arg) {
    char* name = (char*)arg;  // Cast the argument to string
    printf("Thread says: Hello, %s! Welcome to the world of threads.\n", name);
    return NULL;
}

int main() {
    pthread_t thread;
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);  // Take user input
    printf("Main thread: Waiting for greeting...\n");
    // Create a thread and pass name as argument
    pthread_create(&thread, NULL, greet, (void*)name);
    // Wait for the thread to complete
    pthread_join(thread, NULL);
    printf("Main thread: Greeting completed.\n");
    return 0;
}
