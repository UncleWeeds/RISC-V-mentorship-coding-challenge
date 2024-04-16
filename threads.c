#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

// Structure to hold shared data
typedef struct {
    int counter;
    pthread_mutex_t lock;
} SharedData;

// Shared memory ID and data pointer
int shmid;
SharedData *shared_data;
pthread_t tid1, tid2;

// Signal handler for SIGINT
void handle_sigint(int sig) {
    printf("SIGINT received, cleaning up...\n");

    // Cleanup
    pthread_mutex_destroy(&shared_data->lock);
    shmdt(shared_data);
    shmctl(shmid, IPC_RMID, NULL);

    pthread_cancel(tid1);
    pthread_cancel(tid2);

    exit(0);  // Exit the program after cleanup
}

// Function that each thread will execute
void *increment_counter(void *arg) {
    SharedData *data = (SharedData *)arg;
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&data->lock);
        data->counter++;
        printf("Thread %ld, Counter: %d\n", pthread_self(), data->counter);
        pthread_mutex_unlock(&data->lock);
        usleep(100000);  // Sleep for a short time to simulate work
    }
    return NULL;
}

int main() {
    // Allocate shared memory
    shmid = shmget(IPC_PRIVATE, sizeof(SharedData), 0666 | IPC_CREAT);
    shared_data = (SharedData *)shmat(shmid, NULL, 0);

    // Initialize the mutex and shared data
    pthread_mutex_init(&shared_data->lock, NULL);
    shared_data->counter = 0;

    // Register the signal handler
    signal(SIGINT, handle_sigint);

    // Create threads
    pthread_create(&tid1, NULL, increment_counter, (void *)shared_data);
    pthread_create(&tid2, NULL, increment_counter, (void *)shared_data);

    // Wait for threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // Final cleanup, in case SIGINT was not received
    pthread_mutex_destroy(&shared_data->lock);
    shmdt(shared_data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
