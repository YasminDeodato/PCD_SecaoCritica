#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS 4

int SOMA = 0, request = 0, respond = 0;

void incrementa(){
  int local = SOMA;
  sleep(rand()%2);
  SOMA = local + 1;
  printf("%d\n", SOMA);
}


void *lockCliente(void *t){
    int threadsT = 1;
    while (threadsT){
        long tLocal = (long)t;
        while (respond != tLocal){
            request = tLocal;
        }
        incrementa();
        respond = 0;
    }
}


void *lockServidor(){
    int threadsT = 1;
    while (threadsT){
        while (request == 0) {
        }
        respond = request;
        while (respond != 0) {
        }
        request = 0;
    }
}


void main(){
    pthread_t t[THREADS];

    long x = 1;
    pthread_create(&t[0], NULL, lockServidor, NULL);
    pthread_create(&t[1], NULL, lockCliente, (void*) x);
    x++;
    pthread_create(&t[2], NULL, lockCliente, (void*) x);
    x++;
    pthread_create(&t[3], NULL, lockCliente, (void*) x);

    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
}