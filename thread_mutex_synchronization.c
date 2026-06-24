#include <stdio.h> 
#include <pthread.h>
pthread_mutex_t m;
void *fun(void *arg) {
 pthread_mutex_lock(&m);
printf("Thread Running\n");
pthread_mutex_unlock(&m);
return NULL;
}
int main() { 
pthread_t t1, t2;
pthread_mutex_init(&m, NULL);
pthread_create(&t1, NULL, fun, NULL);
pthread_create(&t2, NULL, fun, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_mutex_destroy(&m);
return 0;
}
