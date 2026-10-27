#include <stdio.h>
#include <pthread.h>

void *contar_descendente(void *arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("Hilo: %d\n", i);
    }
    return NULL;
}

int main(void) {
    pthread_t hilo;

    if (pthread_create(&hilo, NULL, contar_descendente, NULL) != 0) {
        perror("Error al crear el hilo");
        return 1;
    }

    for (int i = 1; i <= 10000; i++) {
        printf("Proceso principal: %d\n", i);
    }

    pthread_join(hilo, NULL);

    return 0;
}

