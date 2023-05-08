#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "header.h"

//TENDY


int derajatOperator(infotype oper){
	if(oper=='+' || oper=='-'){
		return 1;
	} else if(oper=='*' || oper=='/'){
		return 2;
	} else if(oper=='^' || oper=='v'){
		return 3;
	} else{
		printf("Error, Operator Tidak Diketahui: %c", oper);
        exit(1);
	}
}
/*
Dimasukkan parameter passing by value pada modul ini 
Tujuan: untuk mengetahui derajat dari suatu operator
*/
float operasi_trigono(char* tes,float oprtr,int *invalid){
	float hasil;
	if (strcmp(tes,"sin(")==0){
		hasil=sinus(oprtr);
		return hasil;
	}else if (strcmp(tes,"cos(")==0){
		hasil=cosinus(oprtr);
		return hasil;
	}else if (strcmp(tes,"tan(")==0){
		hasil=tangen(oprtr);
		return hasil;
	}else if(strcmp(tes,"csc(")==0){
		hasil=cosecan(oprtr);
		return hasil;
	}else if(strcmp(tes,"sec(")==0){
		hasil=cosecan(oprtr);
		return hasil;
	}else if(strcmp(tes,"cot(")==0){
		hasil=cotangen(oprtr);
		return hasil;
	}else if(strcmp(tes,"asin(")==0){
		hasil=asinus(oprtr);
		return hasil;
	}else if(strcmp(tes,"acos(")==0){
		hasil=acosinus(oprtr);
		return hasil;
	}else if(strcmp(tes,"atan(")==0){
		hasil=atangen(oprtr);
		return hasil;
	}
	else{
		printf("format salah");
		*invalid=1;
		return 0;
	}
}
//modul ini digunakan untuk mengetahui operasi trigono mana yang digunakan 
//serta mengetahui format yang salah pada input
float operasilog(float a,float b,char *tes,int basis_bebas){
	float hasil;
	if(strcmp(tes,"log(")==0){
		if(basis_bebas==1){
		hasil=log_a_to_base_b(b,a);
		return hasil;	
		}
		else{
		hasil=loga(b);
		return hasil;
		}
	}else{
	printf("format yang dimasukkan. mungkin yang anda maksud:basislog(angka)");
	return 0;
	}
	
}
//modul ini digunakan untuk mengetahui operasi logaritma mana yang digunakan 
//serta mengetahui format yang salah pada input
int isOperator(infotype oper){
	if(oper=='+' || oper=='-' || oper=='*' || oper=='/' || oper=='^' || oper=='v'){
		return 1;
	} 
	return 0;
}
//modul  ini digunakan untuk mengetahui char dari string operator atau bukan
address CreateNode(infotype data){
	address P;
	
	P = (address) malloc (sizeof (Tree));
	Data(P)=data;
	right(P)=Nil;
	left(P)=Nil;
	
	return P;
}
//modul ini digunakan untuk membuat  node yang bertype tree

void PostOrder(address P){
	
	if(P!=Nil){
		PostOrder(left(P));
		PostOrder(right(P));
		if(P->isOperator==1){
		printf("%c ", P->data);
		}else{
		printf("%g ",P->operand);
		}
	}
}
//modul ini digunakan untuk tranversal Tree secara PostOrder
void PreOrder(address P){
	
	if(P!=Nil){
		if(P->isOperator==1){
		printf("%c ", P->data);
		}else{
		printf("%g ",P->operand);
		}
		PostOrder(left(P));
		PostOrder(right(P));
	}
}
//modul ini digunakan untuk tranversal Tree secara PreOrder

void InOrder(address P){
	
	if(P!=Nil){
		PostOrder(left(P));
		if(P->isOperator==1){
		printf("%c ", P->data);
		}else{
		printf("%g ",P->operand);
		}
		PostOrder(right(P));
	}
}
//modul ini digunakan untuk tranversal Tree secara InOrder

void PushStack(Stack *First,char item,node *P){
	*P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{

		(*P)->oprtr=item;
		(*P)->isoperator=1;
		(*P)->next=NULL;
		if(First->Head==NULL){
		(*First).Head=*P;
		(*First).Head->next=NULL;	
		}else{
		(*P)->next=First->Head;
		First->Head=*P;
		}
	
	
}
}
//modul ini digunakan untuk memasukkan suatu char kedalam stack
char PopStack(Stack *First){
	node P;
	P=First->Head;
	First->Head=P->next;
	return P->oprtr;
	free(P);
}
//modul ini digunakan untuk mengeluarkan top dari stack dan mereturnkan isinya
void ViewAsc(Queue First){
	node P;
	P=First.First;
	if(P!=NULL){
		
	while(P!=NULL){
		if(P->isoperator==1){
			printf("%c ",P->oprtr);
		}else{
			printf("%g ",P->operand);
		}
	P=P->next;
	}
	}
	else if(P==NULL){
		printf("list kosong");
	}
}
//modul ini digunakan untuk menampilkan queue secara ascending
void ViewAscStack(Stack First){
	node P;
	P=First.Head;
	if(P!=NULL){
		
	while(P!=NULL){
		if(P->isoperator==1){
			printf("%c ",P->oprtr);
		}else{
			printf("%g ",P->operand);
		}
	P=P->next;
	}
	}
	else if(P==NULL){
		printf("list kosong");
	}
}
//modul ini digunakan untuk menampilkan stack secara ascending
void EnqueOperator(Queue *First,char item,node *P){
	*P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->oprtr=item;
		(*P)->next=NULL;
		(*P)->isoperator=1;
		if(First->First==NULL){
		(*First).First=*P;
		(*First).Last=*P;
		(*First).Last->next=NULL;	
		}else{
		(*P)->next=NULL;
		First->Last->next=*P;
		First->Last=*P;
		}
	
}
}
//modul yang digunakan untuk memasukkan char yang merupakan operator ke queue
void EnqueOperand(Queue *First,float item,node *P){
	
	*P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->operand=item;
		(*P)->next=NULL;
		(*P)->isoperator=0;
		if(First->First==NULL){
		(*First).First=*P;
		(*First).Last=*P;
		(*First).Last->next=NULL;	
		}else{
		(*P)->next=NULL;
		First->Last->next=*P;
		First->Last=*P;
		}
	
}
}
//modul yang digunakan untuk memasukkan interger yang merupakan operand ke queue
void convertPostfix(Queue *Z,Stack *X,char *input,int *invalid){
	node P;
	char token,c,negatif;
	int num3=10;
	int i,temp;
	float num=0,num2;
	for(i=0;i<strlen(input);i++){
		token=input[i];
		if(isdigit(token)||token=='.'||(token=='-'&&(isOperator(input[i-1])||i==0||input[i-1]=='('))){
			if(isdigit(token)){
				num=num*10+(token-'0');
			}else if(token=='.'){
				i++;
				while(isdigit(input[i])){
				num2=(input[i]-'0');
				num=num+(num2/num3);	
				num3=num3*10;
				i++;
			}
			num3=10;
			i--;
			}else if(token=='-'){
				negatif='-';
			}
			 if(isdigit(input[i+1])!=1&&input[i+1]!='.'){
			 	if(negatif=='-'){
			 		num=num*-1;
				 }
				negatif='\0';
				EnqueOperand(&*Z, num,&P);
				num=0;
			}
		}else if(isOperator(token)&&X->Head!=NULL&&X->Head->oprtr!='('){
			c=X->Head->oprtr;
			while(derajatOperator(token)<=derajatOperator(c)&&X->Head!=NULL&&X->Head->oprtr!='('){
				EnqueOperator(&*Z,PopStack(&*X),&P);
			}
			PushStack(&*X,token,&P);
		}else if(token==')'){
			c=X->Head->oprtr;
			while(c!='('&&X->Head->next!=NULL){
				EnqueOperator(&*Z,PopStack(&*X),&P);
				c=X->Head->oprtr;
			}
			if(c=='('){
				PopStack(&*X);
			}else{
				printf("format yang dimasukkan salah\n");
				
			}
		}
		else if(token=='('){
			PushStack(&*X,token,&P);
		}else if(token=='s'||token=='c'||token=='t'){
			float hasil3=0,hasil2;
			int o=1,t=1;
			char valid[5];
			valid[4]='\0';
			valid[5]='\0';
			valid[0]=token;
			i++;
			while(t<4){
				valid[o]=input[i];
				i++;
				o++;
				t++;
			}
			while((isdigit(input[i])||input[i]=='.')&&input[i]!=')'){
				if(isdigit(input[i])){
				hasil3=hasil3*10+(input[i]-'0');
				i++;
				}
				
			}
			if(input[i]==')'){
				hasil2=operasi_trigono(valid,hasil3,&*invalid);
				EnqueOperand(&*Z,hasil2,&P);
			}else{
				printf("format yang dimasukkan salah");
				*invalid=1;
		
			}
		}else if(token=='a'){
			float hasil3=0,hasil2,hasil1=10;
			int o=1,t=1;
			char valid[6];
			valid[5]='\0';
			valid[6]='\0';
			valid[0]=token;
			i++;
			while(t<5){
				valid[o]=input[i];
				i++;
				o++;
				t++;
			}
			while((isdigit(input[i])||input[i]=='.')&&input[i]!=')'){
				if(isdigit(input[i])){
				hasil3=hasil3*10+(input[i]-'0');
				i++;
				}
				else if(input[i]=='.'){
				i++;
				while(isdigit(input[i])){
				hasil2=(input[i]-'0');
				hasil3=hasil3+(hasil2/hasil1);	
				hasil1=hasil1*10;
				i++;
			}
			hasil1=10;
			i--;
			i++;
			}
			}
			if(input[i]==')'){
				hasil2=operasi_trigono(valid,hasil3,&*invalid);
				EnqueOperand(&*Z,hasil2,&P);
			}else{
				printf("format yang dimasukkan salah");
				*invalid=1;
			}
		}else if(token=='l'){
			float b;
			int basis_bebas=0;
			if(isdigit(input[i-1])){
				b=DequeOperand(&*Z);
				basis_bebas=1;
			}
			double hasil3=0,hasil2=0;
			int o=1,t=1;
			char valid[5];
			valid[4]='\0';
			valid[5]='\0';
			valid[0]=token;
			i++;
			while(t<4){
				valid[o]=input[i];
				i++;
				o++;
				t++;
			}
			while((isdigit(input[i])||input[i]=='.')&&input[i]!=')'){
				if(isdigit(input[i])){
				hasil3=hasil3*10+(input[i]-'0');
				i++;
				}
			}
			if(input[i]==')'){
				hasil2=operasilog(b,hasil3,valid,basis_bebas);
				EnqueOperand(&*Z,hasil2,&P);
			}else{
				printf("format yang dimasukkan salah");
				*invalid=1;
			}
		}else if(token=='!'){
			float a,c;
			char t;
			t=token;
			if(isdigit(input[i-1])){
				a=DequeOperand(&*Z);
				c=faktorial(a);
				EnqueOperand(&*Z,c,&P);
				
			}else{
				printf("format yang anda masukkan salah: ");
				*invalid=1;
			}
		}
		else{
			PushStack(&*X,token,&P);
		}
	}
	while(X->Head!=NULL){
		c=PopStack(&*X);
	EnqueOperator(&*Z,c,&P);
	}
	
	
}
// modul  yang digunakan untuk merubah string yang berupa operasi infix menjadi postfix
// bentuk :queue
address Create_Tree(Queue Z){
	
	address P;
	address stack[50];
	node Q;
	int i, len, top=-1;
	infotype c;
	float d;
	
	Q=Z.First;
	
	while(Q!=NULL){
		if(Q->isoperator==1){
			c=Q->oprtr;
			P=CreateNodeOperator(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}else{
			d=Q->operand;
			P=CreateNodeOperand(d);
		}
//		if(isdigit(c)){
//			P=CreateNode(c);
//		} else{
//			P=CreateNode(c);
//			right(P)=stack[top--];
//			left(P)=stack[top--];
//		}
		stack[++top]=P;
		Q=Q->next;
	}
	return(stack[0]);
}
//membentuk tree  dari  queue yang telah disediakan yang berisikan postfix
address CreateNodeOperand(float input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand=input;
	P->isOperator=0;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}
//untuk membuat node dengan tipe tree yang berisikan operand dari queue postfix
address CreateNodeOperator(char input){
		address P;
	P = (address) malloc (sizeof (Tree));
	P->data=input;
	P->isOperator=1;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}
//untuk membuat node dengan tipe tree yang berisikan  operator dari queue postfix
double kalkulasi(address P){
	if(P->isOperator==1){
		if(P->data=='+'){
			return kalkulasi(P->left) + kalkulasi(P->right);
		}else if(P->data=='-'){
			return kalkulasi(P->left) - kalkulasi(P->right);
		}else if(P->data=='-'){
			return kalkulasi(P->left) - kalkulasi(P->right);
		}else if(P->data=='/'){
			return kalkulasi(P->left) / kalkulasi(P->right);
		}else if(P->data=='*'){
			return Perkalian(kalkulasi(P->left),kalkulasi(P->right));
		}else if(P->data=='^'){
			return Perpangkatan(kalkulasi(P->left) , kalkulasi(P->right));
		}else if(P->data=='V'){
			return akar_pangkat_n(kalkulasi(P->right),kalkulasi(P->left));
		}
	}
	
	return P->operand;
}
// untuk mengkalkulasikan isi dari tree
float DequeOperand(Queue *A){
	
	
	float q;
	node First,Last,Throw;
	First=A->First;
	Last=A->Last;
	if(First==NULL){
		printf("Queue Empty");
	}else{
		if(First!=Last){
			while(First->next!=Last){
				First=First->next;
			}
			Throw=Last;
			q=Last->operand;
			A->Last=First;
			A->Last->next=NULL;
			free(Throw);
			return q;
		}else{
			Throw=Last;
			q=Last->operand;
			A->Last=NULL;
			A->First=NULL;
			free(Throw);
			return q;
		}
		
	}
}
// mendelete queue terakhir dari suatu queue yang berisikan operand


