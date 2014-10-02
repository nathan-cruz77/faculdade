#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t sem;
pthread_mutex_t sem2;

void* p1(void* args){
    pthread_mutex_lock(&sem);
    printf("C");
    printf("E");
    pthread_mutex_unlock(&sem2);
}

void* p2(void* args){
    printf("A");
    pthread_mutex_unlock(&sem);
    pthread_mutex_lock(&sem2);
    printf("R");
    printf("O");
}

int main(){
    pthread_t t1, t2;

    pthread_mutex_lock(&sem);
    pthread_mutex_lock(&sem2);

    pthread_create(&t1, NULL, p1, NULL);
    pthread_create(&t2, NULL, p2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\n");

    return 0;
}
