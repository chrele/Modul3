#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void seller();
void addstock();
void stocklist();

int *w1,*w2,*w3,*w4,*w5,*w6;
int weap1,weap2,weap3,weap4,weap5,weap6;

void addstock(){
	char name[10];
	int num=0;
	scanf("%s %d", name, &num);
	if (!strcmp(name,"MP4A1")) *w1+=num;
	else if (!strcmp(name,"PM2-V1")) *w2+=num;
	else if (!strcmp(name,"SPR-3")) *w3+=num;
	else if (!strcmp(name,"SS2-V5")) *w4+=num;
	else if (!strcmp(name,"SPG-V3")) *w5+=num;
	else if (!strcmp(name,"MINE")) *w6+=num;
}

void stocklist(){
	if(*w1>0)printf("MP4A1=%d\n",*w1);
	if(*w2>0)printf("PM2-V1=%d\n",*w2);
	if(*w3>0)printf("SPR-3=%d\n",*w3);
	if(*w4>0)printf("SS2-V5=%d\n",*w4);
	if(*w5>0)printf("SPG-V3=%d\n",*w5);
	if(*w6>0)printf("MINE=%d\n",*w6);
}

void seller(){
	int choice=0;
	printf("=====Seller=====\n");
	printf("=1. Add        =\n");
	printf("=2. Stocklist  =\n");
	printf("=3. Exit       =\n");
	printf("================\n");
	while(1){
		printf("Your choice: "); scanf("%d", &choice);
		if(choice==1){
			addstock();
		}
		else if(choice==2){
			stocklist();
		}
		else if(choice==3){
			return;
		}
		else {
			printf("Please choose from the MENU\n");
		}
	}
	
}

int main(){
	
	while(1){
		weap1 = shmget(1, sizeof(int), IPC_CREAT | 0666);
		w1 = shmat(weap1, NULL, 0);
		weap2 = shmget(2, sizeof(int), IPC_CREAT | 0666);
		w2 = shmat(weap2, NULL, 0);
		weap3 = shmget(3, sizeof(int), IPC_CREAT | 0666);
		w3 = shmat(weap3, NULL, 0);
		weap4 = shmget(4, sizeof(int), IPC_CREAT | 0666);
		w4 = shmat(weap4, NULL, 0);
		weap5 = shmget(5, sizeof(int), IPC_CREAT | 0666);
		w5 = shmat(weap5, NULL, 0);
		weap6 = shmget(6, sizeof(int), IPC_CREAT | 0666);
		w6 = shmat(weap6, NULL, 0);
		
		seller();
		
		break;
	}
	shmdt(w1);
        shmctl(weap1, IPC_RMID, NULL);
	shmdt(w2);
        shmctl(weap2, IPC_RMID, NULL);
	shmdt(w3);
        shmctl(weap3, IPC_RMID, NULL);
	shmdt(w4);
        shmctl(weap4, IPC_RMID, NULL);
	shmdt(w5);
        shmctl(weap5, IPC_RMID, NULL);
	shmdt(w6);
        shmctl(weap6, IPC_RMID, NULL);
}