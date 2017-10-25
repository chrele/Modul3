#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t pt1;
pthread_t pt2;

int score1=0,score2=0,mines[3][17];
char p1[10],p2[10];
int stat=0,count=0,hole,fill,guess;

void point(){
    printf("Point of %s is : %d\n",p1,score1);
    printf("Point of %s is : %d\n",p2,score2);
}

void* turnp1(void *arg){
	while(score1<10){
		while(stat==1){}
		if(stat==-999){
			return NULL;
		}
    	for(int k=0;k<2;k++){
    		for(int l=0;l<16;l++){
    			if(mines[k][l]==1){
    				count++;
    			}
    		}
    	}
    	if(count==32){
    		break;
    	}
    	printf("Please %s state the number of hole that want to be filled(<=4)\n",p1);
    	scanf("%d",&hole);
    	for(int k=1;k<=hole;k++){
    		printf("Hole number: "); scanf("%d",&fill);
    		while(mines[0][fill]!=0){
			printf("The hole is already filled, please choose another hole.");
			scanf("%d", &fill);
		}
		mines[0][fill]=1;
    	}
    	printf("Please %s guess the hole's number: ",p2);
    	for(int k=1;k<=4;k++){
    		scanf("%d",&guess);
    		while(mines[0][guess]==-99){
			printf("You already guessed this hole before and you got the bomb, please guess the other");scanf("%d", &guess);
		}
		if(mines[0][guess]==1){score1++;mines[0][guess]==-99;}
    		else score2++;
    	}
    	point();
    	stat=1;
	}
	printf("Game Over!\n");
	point();
	if(score1>score2){
	printf("%s is the winner!\n",p1);
	}
	else if(score1<score2){
	printf("%s is the winner!\n",p2);
	}
	else{
	printf("It's a draw!\n");
	}
	stat=-999;
	return NULL;
}

void* turnp2(void *arg){
	while(score2<10){
        while(stat==0){}
        if(stat==-999){
            return NULL;
        }
        for(int k=0;k<2;k++){
            for(int l=0;l<16;l++){
                if(mines[k][l]==1){
                    count++;
                }
            }
        }
        if(count==32){
            break;
        }
        printf("Please %s state the number of hole that want to be filled(<=4)\n",p2);
        scanf("%d",&hole);
    	for(int k=1;k<=hole;k++){
    		printf("Hole number: "); scanf("%d",&fill);
		while(mines[1][fill]!=0){
			printf("The hole is already filled, please choose another hole.");
			scanf("%d", &fill);
		}
    		mines[1][fill]=1;
    	}
    	printf("Please %s guess the hole's number",p1);
    	for(int k=1;k<=4;k++){
    		scanf("%d",&guess);
		while(mines[1][guess]==-99){
			printf("You already guessed this hole before and you got the bomb, please guess the other");scanf("%d", &guess);
		}
    		if(mines[1][guess]==1){score2++;mines[1][guess]==-99;}
    		else score1++;
    	}
    	point();
    	stat=0;
	}
	printf("Game Over!\n");
	point();
	if(score1>score2){
	printf("%s is the winner!\n",p1);
	}
	else if(score1<score2){
	printf("%s is the winner!\n",p2);
	}
	else{
	printf("It's a draw!\n");
	}
	stat=-999;
	return NULL;
}

int main(){
	for(int i=0;i<2;i++){
		for(int j=0;j<16;j++){
			mines[i][j]=0;
		}
	}
	printf("Name of both players(separate with (space): ");
	scanf("%s %s", p1,p2);
	
	pthread_create(&(pt1),NULL,&turnp1, NULL);
	pthread_create(&(pt2),NULL,&turnp2, NULL);
	
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	return 0;
}
