#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *data) {
    int *finished = data;
    while (!*finished) {
        printf("feed me input!\n");
        sleep(1);
    }

}

int main(void) {

    int finished = 0;
    // TODO: create a thread
    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        (void *)&finished       // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );


    // TODO: print out lines
    char line[1024] = {0};
    while (1) {
        scanf("%s", line);
        printf("%s\n", line);
        finished = 1;
    }


    // TODO: cancel the thread upon completion
    return 0;
}
