#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_t tid[100];
char *arr[100];
int x;

void* count (void *arg){
    int i;
    pthread_t id = pthread_self();
    for(i=0; i<x; i++){
        if(pthread_equal(id,tid[i])){
    	    FILE *fp;
	    int sum=0;
	    char read[1000];
	    fp=fopen("Novel.txt", "r");
	    while(!feof(fp)){
	        fscanf(fp, "%s", read);
		if(strstr(read, arr[i])!=NULL)
		    sum++;
	    }
	    fclose(fp);
	    printf("jumlah %s=%d ",arr[i],sum);
	}
    }
}

int main(int argc, char **argv)
{
    int i, j, num;
    x=0;
    while(1){
       if(argv[x+1] == NULL) break;
       arr[x]=argv[x+1];
       x++;
    } 
    for(i=0; i<x; i++){
       pthread_create (&tid[i],NULL,&count,NULL);
    }
    for(j=0; j<x; j++){
       pthread_join(tid[j],NULL);
    }
    printf("\n");
    return 0;
}
