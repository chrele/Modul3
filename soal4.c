#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[100];
int status=0;
int arr[100];

int faktorial(int arr[i]){
    int z, k;
    z=arr[i];
    for(k=1; k<=z; k++) 
	z=z*k;
    return z;
}

void* show (void *arg){
    int i, j;
    pthread_t id=pthread_self();
    for(i=1; i<x; i++){
        if(pthread_equal(id,tid[i])){
	    printf("%d", faktorial(arr[i]);
	}
    }
}

int main(int argc, char **argv)
{
    int i, num;
    x=0;
    while(1){
       if(argv[x+1]==NULL) break;
       num = atoi(argv[x+1]);
       arr[x] = num;
       x++; 
    } 
    for(i=1; i<x; i++){
       pthread_create (&tid[i], NULL, &faktorial, NULL);
    }
    printf("\n");
    return 0;
}        
