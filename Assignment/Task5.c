/*
Name: Eisha Muzaffar
Reg. No: 23-NTU-CS-1147
Task 5 – Student Database Thread Simulation
*/
#include <stdio.h>
#include <pthread.h>
// Define Student structure
typedef struct {
    int student_id;
    char name[50];
    float gpa;
} Student;
// Shared counter for Dean’s List students
int deanCount = 0;
pthread_mutex_t lock; // To protect shared variable
// Thread function
void* checkDeanList(void* arg) {
    Student* s = (Student*)arg;  // Cast argument to Student pointer
    printf("\nStudent ID: %d\n", s->student_id);
    printf("Name: %s\n", s->name);
    printf("GPA: %.2f\n", s->gpa);

    // Check Dean’s List eligibility
    if (s->gpa >= 3.5) {
        printf("%s is on the Deans List!\n", s->name);
        pthread_mutex_lock(&lock);
        deanCount++;
        pthread_mutex_unlock(&lock);
    } else {
        printf("%s is not on the Deans List.\n", s->name);
    }

    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);
    // Create 3 students
    Student s1 = {101, "Amina", 3.8};
    Student s2 = {102, "maha", 3.2};
    Student s3 = {103, "Eman", 3.6};
    // Create 3 threads for 3 students
    pthread_create(&t1, NULL, checkDeanList, &s1);
    pthread_create(&t2, NULL, checkDeanList, &s2);
    pthread_create(&t3, NULL, checkDeanList, &s3);
    // Wait for all threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    // Print total Dean’s List count
    printf("\n------------------------------------\n");
    printf("Total Students on Deans List: %d\n", deanCount);
    printf("------------------------------------\n");
    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
