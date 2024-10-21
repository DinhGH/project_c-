#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char may(){
	srand(time(NULL));
	int random=rand()%3;
	char mayra;
	switch(random){
		case 0: 
			return 'k';
			break;
		case 1:
			return 'b';
			break;
		case 2:
			return 'p';
			break;
	}
}
char user(){
	char userra;
	printf("Ban chon 1 trong 3: k=keo\\b=bua\\p=bao\n");
	printf("You choose:");
	scanf("%c",&userra);
	return userra;	
}
char result(char userpick,char maypick){
	char result;
	if(userpick==maypick)return 'h';
	else if((userpick=='k'&&maypick=='p')||(userpick=='b'&&maypick=='k')||(userpick=='p'&&maypick=='b'))return 'w';
	else return 'd';
}
int main(){
	char ng=user();
	char m=may();
	char kq=result(ng,m);
	if(ng=='k'||ng=='b'||ng=='p'){
		printf("Boss choose:%c\n",may());
		if(kq=='w')printf("You: win\nBoss: loss");
		else if(kq=='h')printf("You and Boss are draw");
		else printf("Boss: win\nYou: loss");
	}
	else printf("vui long chon 1 trong 3");
}
