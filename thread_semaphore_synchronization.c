#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t s;
void *fun(void *arg)
{
 sem_wait(&s);
 printf("Thread Running\n");
 sem_post(&s);
 return NULL;
}
int main()
{
 pthread_t t1, t2;

 sem_init(&s, 0, 1);
 pthread_create(&t1, NULL, fun, NULL);
 pthread_create(&t2, NULL, fun, NULL);
 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 sem_destroy(&s);
 return 0;
}
