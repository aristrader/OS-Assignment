#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int n = 0;

void *myThreadFunc(void *var){
    sleep(1);

    int *arr = (int *)var;

    arr[0] = 1; arr[1] = 1;

    for(int i=2; i<n; i++)
        arr[i] = arr[i-1] + arr[i-2];

    pthread_exit(0);
}

int main() {
    pthread_t thread_id;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++)
        arr[i] = i;

    pthread_create(&thread_id, NULL, myThreadFunc, (void *)arr);
    pthread_join(thread_id, NULL);

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
} 
 