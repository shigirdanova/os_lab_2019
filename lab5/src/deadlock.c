#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static pthread_mutex_t mtx_first = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mtx_second = PTHREAD_MUTEX_INITIALIZER;

static void fun1() {
    int i;
    printf("start of fun1\n");
    pthread_mutex_lock(&mtx_first);
    do{
        i++;
    }while(1);
    pthread_mutex_unlock(&mtx_first);
    printf("end of fun1\n");
}

static void fun2() {
    int i;
    printf("start of fun2\n");
    pthread_mutex_lock(&mtx_second);
    do{
        i++;
    }while(1);
    pthread_mutex_unlock(&mtx_second);
    printf("end of fun2\n");
}

int main(int argc, char* argv[]) {
    pthread_t thread1, thread2;

    if ((&thread1, NULL, (void*)fun1, NULL)!=0) {
        printf("Error: cannot create first thread\n");
        return -1;
    }
    if (pthread_create(&thread2, NULL, (void*)fun2, NULL)!=0) {
        printf("Error: cannot create second thread\n");
        return -1;
    }

    if (pthread_join(thread1, 0) != 0) {
        printf("Error: cannot join first thread\n");
        return -1;
    }

    if (pthread_join(thread2, 0) != 0) {
        printf("Error: cannot join second thread\n");
        return -1;
    }
}













// gcc deadlock.c -o deadlock && ./deadlock