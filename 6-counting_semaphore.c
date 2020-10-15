#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct semaphore{
    int s;
}semaphore;
semaphore S;
void P()
{
    while(S.s<=0);
    S.s--;
}
void V()
{
    S.s++;
}
void* fun1()
{
    P(); 
    int t=5;
    while(t--)
    printf("Process 1\n");
    V(); 
}
void* fun2()
{
    P();
    int t=5;
    while(t--)
    printf("Process 2\n");
    V();
}
void* fun3()
{
    P();
    int t=5;
    while(t--)
    printf("Process 3\n");
    V();
}
void* fun4()
{
    
    P();
    int t=5;
    while(t--)
    printf("Process 4\n");
    V();
}
int main()
{
    pthread_t t1,t2,t3,t4;
    S.s=3;
    pthread_create(&t1,NULL,fun1,NULL); 
    pthread_create(&t2,NULL,fun2,NULL); 
    pthread_create(&t3,NULL,fun3,NULL);
    pthread_create(&t4,NULL,fun4,NULL);
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    return 0;
}
