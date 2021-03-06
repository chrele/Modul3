#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[100];
int arr[100];
int x;

void* faktorial (void *arg){
    int i, j;
    pthread_t id=pthread_self();
    for(i=0; i<x; i++){
        if(pthread_equal(id,tid[i])){
	    unsigned long long int fak=1;
    	    for(j=1; j<=arr[i]; j++) 
		fak*=j;
	    printf("%d!=%llu  ",arr[i],fak);
	}
    }
}

int main(int argc, char **argv)
{
    int i, j, num;
    x=0;
    while(1){
       if(argv[x+1] == NULL) break;
       num = atoi(argv[x+1]);
       arr[x] = num;
       x++;
    } 
    for(i=0; i<x; i++){
       pthread_create (&tid[i],NULL,&faktorial,NULL);
    }
    for(j=0; j<x; j++){
       pthread_join(tid[j],NULL);
    }
    printf("\n");
    return 0;
}
