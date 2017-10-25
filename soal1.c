#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int store[7];
void menu();
void seller();
void addstock();
void stocklist();
void buyer();
void buy();

void menu(){
	int choice=0;
	printf("======MainMenu======\n");
	printf("=1. Seller's Menu  =\n");
	printf("=2. Buyer's Menu   =\n");
	printf("=3. Exit           =\n");
	printf("====================\n");
	while(1){
		printf("Your choice: ");scanf("%d", &choice);
		if(choice==1){
			seller();
		}
		else if(choice==2){
			buyer();
		}
		else if(choice==3){
			exit(1);
		}
		else {
			printf("Please choose from the MENU\n");
		}
	}
}

void addstock(){
	char name[10], c, f, s, t, flag=0;
	int num=0;
	while(1){
		if(flag==1){
			menu();
			break;
		}
		scanf("%s %d", name, &num);
		f=name[0];
		s=name[1];
		t=name[2];
		if(f=='S'){
			if(s=='P'){
				if(t=='R'){
					store[2]+=num;
				}
				else if(t=='G'){
					store[4]+=num;
				}
			}
			else if(s=='S'){
				store[3]+=num;
			}
		}
		else if(f=='M'){
			if(s=='P'){
				store[0]+=num;
			}
			else if(s=='I'){
				store[5]+=num;
			}
		}
		else if(f=='P'){
			store[1]+=num;
		}
		printf("Do you want to add more weapon?(Y/N)"); scanf("%c", &c);
		if(c=='N'){
			flag==1;
		}
	}
}

void stocklist(){
	for(int i=0;i<6;i++){
		if(store[i]!=0){
			if(i==0){
				printf("MP4A1 %d\n", store[i]);
			}
			else if(i==1){
				printf("PM2-V1 %d\n", store[i]);
			}
			else if(i==2){
				printf("SPR-3 %d\n", store[i]);
			}
			else if(i==3){
				printf("SS2-V5 %d\n", store[i]);
			}
			else if(i==4){
				printf("SPG1-V3 %d\n", store[i]);
			}
			else if(i==5){
				printf("MINE %d\n", store[i]);
			}
		}
	}
}

void seller(){
	int choice=0;
	printf("=====Seller=====\n");
	printf("=1. Add        =\n");
	printf("=2. Stocklist  =\n");
	printf("=3. Back       =\n");
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
			menu();
		}
		else {
			printf("Please choose from the MENU\n");
		}
	}
	
}

void buyer(){
	int choice=0;
	printf("=====Buyer=====\n");
	printf("=1. Buy        =\n");
	printf("=2. Stocklist  =\n");
	printf("=3. Back       =\n");
	printf("================\n");
	while(1){
		printf("Your choice: "); scanf("%d", &choice);
		if(choice==1){
			buy();
		}
		else if(choice==2){
			stocklist();
		}
		else if(choice==3){
			menu();
		}
		else {
			printf("Please choose from the MENU\n");
		}
	}
	
}

void buy(){
	char name[10], c, f, s, t, flag=0;
	int num=0;
	while(1){
		if(flag==1){
			menu();
			break;
		}
		scanf("%s %d", name, &num);
		if(f=='S'){
			if(s=='P'){
				if(t=='R'){
					store[2]-=num;
					if(store[2]<=0){
						store[2]+=num;
						printf("Not enough stock!");
					}
				}
				else if(t=='G'){
					store[4]-=num;
					if(store[4]<=0){
						store[4]+=num;
						printf("Not enough stock!");
					}
				}
			}
			else if(s=='S'){
				store[3]-=num;
				if(store[3]<=0){
					store[3]+=num;
					printf("Not enough stock!");
				}
			}
		}
		else if(f=='M'){
			if(s=='P'){
				store[0]-=num;
				if(store[0]<=0){
					store[0]+=num;
					printf("Not enough stock!");
				}
			}
			else if(s=='I'){
				store[5]-=num;
				if(store[5]<=0){
					store[5]+=num;
					printf("Not enough stock!");
				}
			}
		}
		else if(f=='P'){
			store[1]-=num;
			if(store[1]<=0){
				store[1]+=num;
				printf("Not enough stock!");
			}
		}
		printf("Do you want to buy more weapon?(Y/N)"); scanf("%c", &c);
		if(c=='N'){
			flag=1;
		}
	}
}

int main(){
	for(int i=0;i<6;i++){
		store[i]=0;
	}
	menu();
	return 0;
}
