#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int i = 0;
int i2 = 0;

void* myturn(void* arg) {
    while (1) {
        sleep(1);
        printf("my turn [%d] i2: [%d]\n", i, i2);
        i++;
        i2++;
    }
    return NULL;
}

void* yourturn(void* arg) {
    while (1) {
        sleep(2);
        printf("your turn [%d] i2: [%d]\n", i, i2);
        i++;
        i2++;
    }
}

int main() {
    pthread_t newthread;
    pthread_t yourthread;

    pthread_create(&newthread, NULL, myturn, NULL);
    pthread_create(&yourthread, NULL, yourturn, NULL);

    pthread_join(newthread, NULL); // Wait for the 'myturn' thread to finish
    pthread_join(yourthread, NULL); // Wait for the 'yourturn' thread to finish

    return 0;
}

