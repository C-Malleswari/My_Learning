## write a program to reproduce deadlock (use 2 processes and 2 shared resources)
//process 1 is holding resource 1 and wating for resource 2 and process 2 is holding resource 2 and waiting for resource 1

#include<stdio.h>
#include<pthread.h>
#include<string.h>

pthread_mutex_t resource1;
pthread_mutex_t resource2;

void* thread1_fun(void* arg)
{
        pthread_mutex_lock(&resource1);
        printf("thread1 locked the resource1\n");
        sleep(1);

        pthread_mutex_lock(&resource2);
        printf("thread1 locked resource2\n");

        pthread_mutex_unlock(&resource2);
        pthread_mutex_unlock(&resource1);
}
void* thread2_fun(void* arg)
{
        pthread_mutex_lock(&resource2);
        printf("thread2 locked resource2\n");
        sleep(1);

        pthread_mutex_lock(&resource1);
        printf("thread2 locked resource1\n");

        pthread_mutex_unlock(&resource1);
        pthread_mutex_unlock(&resource2);
}
int main()
{
        //pthread id
        pthread_t t1,t2;
//initalize mutexes
        pthread_mutex_init(&resource1,NULL);
        pthread_mutex_init(&resource2,NULL);
//create threads
        pthread_create(&t1,NULL,thread1_fun,NULL);
        pthread_create(&t2,NULL,thread2_fun,NULL);
//wait for threads
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
//destroy mutexes
        pthread_mutex_destroy(&resource1);
        pthread_mutex_destroy(&resource2);

}
