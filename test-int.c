#include <stdio.h>
#include <sys/syscall.h>
#include <sched.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define __NR_sched_setlimit 378

#define NR_CHILDREN (8)

int counter[NR_CHILDREN];

void signal_handler(int signum) {
    int i;
    for (i = 0; i < NR_CHILDREN; i++) {
        printf("worker %d: count = %d\n", i, counter[i]);
    }
    exit(signum);
}

void worker(int worker_id) {
    int limit;
    struct sched_param param;

    param.sched_priority = 0;

    if (worker_id < NR_CHILDREN / 2)
        limit = 0;
    else
        limit = 50;

    // set scheduler
    if (syscall(__NR_sched_setscheduler, 0, 6, &param) == -1) {
        perror("sched_setscheduler");
    }

    // set usage limit
    if (syscall(__NR_sched_setlimit, 0, limit)) {
        perror("sched_setlimit");
    }

    for ( ; ; ) {
        int i = counter[worker_id]++;
        if (i % 1000000 == 0) {
            printf("worker %d: loop %d\n", worker_id, i / 1000000);
        }
    }
}

int main() {
    int i, error;
    pid_t pid;
    
    signal(SIGINT, signal_handler);
    
    memset(counter, 0, sizeof(counter));
    
    while (1);

    for (i = 0; i < NR_CHILDREN; ++i) {
        pid = fork();
        if (pid == -1) {
            perror("fork");
            return 1;
        }
        if (pid == 0) {
            // child process
            worker(i);
            return 0;
        }
    }

    // Only the main process goes here.
    printf("start waiting\n");
    for (i = 0; i < NR_CHILDREN; ++i) {
        if (wait(&error) == -1) {
            perror("wait");
            return 1;
        }
    }
    printf("finish waiting\n");
    return 0;
}
