#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t pt1;
pthread_t pt2;
pthread_t pt3;

int lohanstat=0;
int crabstat=0;
int choice=0;

void* bglohan(void *arg){
	for(lohanstat=100;lohanstat>0; lohanstat=lohanstat-15){
		sleep(10);
		printf("Crab's stat: %d\n", crabstat);
		printf("Lohan's stat: %d\n", lohanstat);
		if(lohanstat>100)exit(1);
	}
	exit(1);
}

void* bgcrab(void *arg){
	for(crabstat=100;crabstat>0; crabstat=crabstat-10){
		sleep(20);
		printf("Crab's stat: %d\n", crabstat);
		printf("Lohan's stat: %d\n", lohanstat);
		if(crabstat>100)exit(1);
	}
	exit(1);
}

void* fore(void *arg){
	printf("======MENU======\n");
	printf("=1. Feed Crab  =\n");
	printf("=2. Feed Lohan =\n");
	printf("=3. Exit       =\n");
	printf("================\n");
	while(1){
		printf("Your choice: ");scanf("%d", &choice);
		if(choice==1){
			crabstat+=10;
			//printf("Crab's stat: %d\n", crabstat);
			//printf("Lohan's stat: %d\n", lohanstat);
		}
		else if(choice==2){
			lohanstat+=10;
			//printf("Crab's stat: %d\n", crabstat);
			//printf("Lohan's stat: %d\n", lohanstat);
		}
		else if(choice==3){
			exit(1);
		}
		else {
			printf("Please choose from the MENU\n");
		}
	}
}

int main(){
	
	pthread_create(&(pt1),NULL,&bglohan, NULL);
	pthread_create(&(pt2),NULL,&bgcrab, NULL);
	pthread_create(&(pt3),NULL,&fore, NULL);
	
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	pthread_join(pt3,NULL);
	return 0;
}
