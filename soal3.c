#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t pt1;
pthread_t pt2;
pthread_t pt3;

int lohanstat=100;
int crabstat=100;
int choice=0;

void* bgcrab(void *arg){
	for(lohanstat;lohanstat>0 && lohanstat<=100; lohanstat=lohanstat-15){
		sleep(10);
		printf("Crab's stat: %d\n", crabstat);
		printf("Lohan's stat: %d\n", lohanstat);
	}
	exit(1);
}

void* bglohan(void *arg){
	for(crabstat;crabstat>0 && crabstat<=100; crabstat=crabstat-10){
		sleep(20);
		printf("Crab's stat: %d\n", crabstat);
		printf("Lohan's stat: %d\n", lohanstat);
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
			printf("Crab's stat: %d\n", crabstat);
			printf("Lohan's stat: %d\n", lohanstat);
		}
		else if(choice==2){
			lohanstat+=10;
			printf("Crab's stat: %d\n", crabstat);
			printf("Lohan's stat: %d\n", lohanstat);
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
