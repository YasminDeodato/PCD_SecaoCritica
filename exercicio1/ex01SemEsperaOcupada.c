#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS 4

int SOMA = 0;

void *incrementa(void *t){
    while(1) {
        int local = SOMA;
        sleep(rand()%2);
        SOMA = local + 1;
        printf("Thread %d - Soma %d\n", (long)t, SOMA);
    }
}


void main(){
    pthread_t t[THREADS];
    long x=1;
    pthread_create(&t[0], NULL, incrementa, (void*) x);
    x++;
    pthread_create(&t[1], NULL, incrementa, (void*) x);
    x++;
    pthread_create(&t[2], NULL, incrementa, (void*) x);
    x++;
    pthread_create(&t[3], NULL, incrementa, (void*) x);

    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
}