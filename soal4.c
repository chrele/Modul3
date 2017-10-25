#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[100];
int N, T;
int status=0;

void* faktorial (void *arg, ){
    int i, j;
    pthread_t id=pthread_self();
    for(i=1; i<x; i++){
        if(pthread_equal(id,tid[i])){
	    
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
