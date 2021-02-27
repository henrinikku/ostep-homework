#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "common_threads.h"

dispatch_semaphore_t sem;

void *child(void *arg) {
    sleep(1);
    printf("child\n");
    Sem_post(sem);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    printf("parent: begin\n");
    sem = Sem_create(0);
    Pthread_create(&p, NULL, child, NULL);
    Sem_wait(sem);
    printf("parent: end\n");
    return 0;
}

