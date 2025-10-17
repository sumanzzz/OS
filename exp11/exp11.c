//Semaphores

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 3

sem_t semaphore;

void* thread_function(void* arg){
    int thread_id = *(int*)arg;

    printf("Thread %d: Waiting to enter critical section..\n",thread_id);

    sem_wait(&semaphore);
    
    printf("Thread %d: Entered critical section.\n",thread_id);
    sleep(2);
    printf("Thread %d: Leaving critical section.\n",thread_id);
    sem_post(&semaphore);

    return NULL;
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    sem_init(&semaphore,0,1);

    for(int i=0;i<NUM_THREADS;i++){
        thread_ids[i] = i+1;
        pthread_create(&threads[i],NULL,thread_function,&thread_ids[i]);
    }

    for(int i=0;i<NUM_THREADS;i++){
        pthread_join(threads[i],NULL);
    }

    sem_destroy(&semaphore);

    printf("All threads have finished execution.\n");

    return 0;
}