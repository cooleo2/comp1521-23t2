#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    char *string = data;
    while (1) {
        printf("%s\n", string);
    }
    return NULL;
}

int main(void) {
    // TODO: create a thread
    pthread_t thread;
    char message[] = "Hello";
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        (void *) &message        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    

    // TODO: print the main message
    while (1) {
        printf("there!\n");
    }

    pthread_join(thread, NULL);
    return 0;
}
