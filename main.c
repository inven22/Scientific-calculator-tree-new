#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int g=1,invalid=0;
	while(g==1){
	invalid=0;
	
//	display_animation("Loading");
	menu();
	float hasil,a=2,c=1.5;
	char input[30],temp;
	address P;
	Stack S;
	Queue Z;
	node Q;
	Z.First=NULL;
	Z.Last=NULL;
	S.Head=NULL;
		
	printf("enter expression:");
	hasil=Perpangkatan(a,c);
	scanf("%s",&input);fflush(stdin);
	convertPostfix(&Z,&S,input,&invalid);
//	temp=PopStack(&X);
//	ViewAsc(Z);
//	ViewAscStack(X);
//	printf("input: %s", input);
//	InfixToPostfix("1*(2+3)/4^5-6", postfix);
//	printf("postfix: %s", postfix);
	if(invalid==0){
	P=Create_Tree(Z);
	hasil=kalkulasi(P);
	printf("hasilnya adalah %g\n",hasil);
//	printf("PostFix: ");
//	PostOrder(P);

	}
	
	printf("\n1.lanjut \n 0.tidak\n pilihan anda:");
	scanf("%d",&g);fflush(stdin);
	
	system("cls");
	
	
	}
	display_animation("Terimakasih telah mencoba ");
	return 0;
}
