#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "header.h"

//TENDY


int derajatOperator(infotype oper){
//Dimasukkan parameter passing by value pada modul ini 
//Tujuan: untuk mengetahui derajat dari suatu operator

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

float operasi_trigono(char *tes, float oprtr, int *invalid){
//Tujuan: mengetahui operasi trigonometri yang digunakan 

	float hasil;
	if (strcmp(tes, "sin(") == 0){
		hasil = sinus(oprtr);
		return hasil;
	}else if (strcmp(tes, "cos(") == 0){
		hasil = cosinus(oprtr);
		return hasil;
	}else if (strcmp(tes, "tan(") == 0){
		hasil = tangen(oprtr);
		return hasil;
	}else if(strcmp(tes, "csc(") == 0){
		hasil = cosecan(oprtr);
		return hasil;
	}else if(strcmp(tes, "sec(") == 0){
		hasil = secan(oprtr);
		return hasil;
	}else if(strcmp(tes, "cot(") == 0){
		hasil = cotangen(oprtr);
		return hasil;
	}else if(strcmp(tes, "asin(") == 0){
		hasil = asinus(oprtr);
		return hasil;
	}else if(strcmp(tes, "acos(") == 0){
		hasil = acosinus(oprtr);
		return hasil;
	}else if(strcmp(tes, "atan(") == 0){
		hasil = atangen(oprtr);
		return hasil;
	}
	else{
		printf("format salah");
		*invalid = 1;
		return 0;
	}
}

float operasilog(float a, float b, char *tes, int basis_bebas){
//Tujuan: mengetahui operasi logaritma yang digunakan 

	float hasil;
	if(strcmp(tes,"log(") == 0){
		if(basis_bebas==1){
			hasil = log_a_to_base_b(b,a);
			return hasil;	
		}
		else{
			hasil = log_a_to_base_b(b,10);
			return hasil;
		}
	}else{
		printf("format yang dimasukkan. mungkin yang anda maksud:basislog(angka)");
		return 0;
	}
}

int isOperator(infotype oper){
//Tujuan: mengetahui char dari string apakah sebuah operator

	if(oper=='+' || oper=='-' || oper=='*' || oper=='/' || oper=='^' || oper=='v'){
		return 1;
	} 
	return 0;
}

address CreateNode(infotype data){
//Tujuan: membuat node bertipe Tree

	address P;
	
	P = (address) malloc (sizeof (Tree));
	Data(P) = data;
	right(P) = Nil;
	left(P) = Nil;
	return P;
}

void PostOrder(address P){
//Tujuan: traversal Tree secara PostOrder	

	if(P != Nil){
		PostOrder(left(P));
		PostOrder(right(P));
		if(P->isOperator == 1){
			printf("%c ", P->data);
		}else{
			printf("%g ", P->operand);
		}
	}
}

void PreOrder(address P){
//Tujuan: traversal Tree secara PreOrder
	
	if(P != Nil){
		if(P->isOperator == 1){
			printf("%c ", P->data);
		}else{
			printf("%g ", P->operand);
		}
		PostOrder(left(P));
		PostOrder(right(P));
	}
}

void InOrder(address P){
//Tujuan: traversal Tree secara InOrder	

	if(P != Nil){
		PostOrder(left(P));
		if(P->isOperator==1){
			printf("%c ", P->data);
		}else{
			printf("%g ",P->operand);
		}
		PostOrder(right(P));
	}
}

void PushStack(Stack *First, char item, node *P){
//Tujuan: memasukkan suatu char kedalam stack

	*P = (node) malloc (sizeof (ElmtList));
	if(P == NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->oprtr = item;
		(*P)->isoperator = 1;
		(*P)->next = NULL;
		if(First->Head == NULL){
			(*First).Head = *P;
			(*First).Head->next = NULL;	
		}else{
			(*P)->next = First->Head;
			First->Head = *P;
		}
	}
}

char PopStack(Stack *First){
//Tujuan: mengeluarkan top dari stack dan mengembalikan isinya

	node P;
	P = First->Head;
	First->Head = P->next;
	return P->oprtr;
	free(P);
}

void ViewAsc(Queue First){
//Tujuan: menampilkan queue secara ascending

	node P;
	P = First.First;
	if(P != NULL){	
		while(P != NULL){
			if(P->isoperator == 1){
				printf("%c ", P->oprtr);
			}else{
				printf("%g ", P->operand);
			}
		P = P->next;
		}
	}
	else if(P == NULL){
		printf("list kosong");
	}
}

void ViewAscStack(Stack First){
//Tujuan: menampilkan stack secara ascending

	node P;
	P = First.Head;
	if(P != NULL){
		while(P != NULL){
			if(P->isoperator == 1){
				printf("%c ", P->oprtr);
			}else{
				printf("%g ", P->operand);
			}
		P = P->next;
		}
	}
	else if(P == NULL){
		printf("list kosong");
	}
}

void EnqueOperator(Queue *First, char item, node *P){
//Tujuan: memasukkan operator bertipe data char ke queue

	*P = (node) malloc (sizeof (ElmtList));
	if(P == NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->oprtr = item;
		(*P)->next = NULL;
		(*P)->isoperator = 1;
		if(First->First == NULL){
			(*First).First = *P;
			(*First).Last = *P;
			(*First).Last->next = NULL;	
		}else{
			(*P)->next = NULL;
			First->Last->next = *P;
			First->Last = *P;
		}
	}
}

void EnqueOperand(Queue *First, float item, node *P){
//Tujuan: memasukkan operand bertipe data integer ke queue	

	*P = (node) malloc (sizeof (ElmtList));
	if(P == NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->operand = item;
		(*P)->next = NULL;
		(*P)->isoperator = 0;
		if(First->First == NULL){
			(*First).First = *P;
			(*First).Last = *P;
			(*First).Last->next = NULL;	
		}else{
			(*P)->next = NULL;
			First->Last->next = *P;
			First->Last = *P;
		}
	}
}

void convertPostfix(Queue *Z, Stack *X, char *input, int *invalid){
//Tujuan: mengubah string berupa operasi infix menjadi postfix
//Bentuk: queue

	//kamus data lokal
	node P;
	char token, c, negatif;
	int num3 = 10;
	int i, temp;
	float num = 0, num2;
	
	//program
	for(i = 0; i < strlen(input); i++){
		token = input[i];
		//identifikasi bil. desimal, negatif, operasi dalam kurung
		if(isdigit(token) || token=='.' || (token=='-' && (isOperator(input[i-1]) || i == 0 || input[i-1]=='('))){
			if(isdigit(token)){
				num = num*10 + (token-'0');
			}else if(token == '.'){ 
				i++;
				while(isdigit(input[i])){
					num2 = (input[i]-'0');
					num = num+(num2/num3);	
					num3 = num3*10;
					i++;
				}
				num3 = 10;
				i--;
			}else if(token == '-'){ 
				negatif = '-';
			}
			if(isdigit(input[i+1]) != 1 && input[i+1] != '.'){
				if(negatif == '-'){
					num = num*-1;
				}
				negatif = '\0';
				EnqueOperand(&(*Z), num, &P);
				num = 0;
			}
		}else if(isOperator(token) && X->Head != NULL && X->Head->oprtr != '('){
			c = X->Head->oprtr;
			while(derajatOperator(token) <= derajatOperator(c) && X->Head != NULL && X->Head->oprtr != '('){
				EnqueOperator(&(*Z), PopStack(&(*X)), &P);
			}
			PushStack(&*X, token, &P);
		}else if(token == ')'){
			c = X->Head->oprtr;
			while(c != '(' && X->Head->next != NULL){
				EnqueOperator(&(*Z), PopStack(&(*X)), &P);
				c = X->Head->oprtr;
			}
			if(c == '('){
				PopStack(&(*X));
			}else{
				printf("format yang dimasukkan salah\n");	
			}
		}
		else if(token == '('){
			PushStack(&(*X), token, &P);
		}else if(token == 's' || token == 'c' || token == 't'){
			//operasi trigonometri
			//kamus data lokal
			float hasil3 = 0, hasil2;
			int o = 1, t = 1;
			char valid[5];
			
			valid[4] = '\0';
			valid[5] = '\0';
			valid[0] = token;
			i++;
			while(t < 4){
				valid[o] = input[i];
				i++;
				o++;
				t++;
			}
			while((isdigit(input[i]) || input[i] == '.') && input[i] != ')'){
				if(isdigit(input[i])){
					hasil3 = hasil3*10 + (input[i]-'0');
					i++;
				}	
			}
			if(input[i] == ')'){
				hasil2 = operasi_trigono(valid, hasil3, &(*invalid));
				EnqueOperand(&(*Z), hasil2, &P);
			}else{
				printf("format yang dimasukkan salah");
				*invalid = 1;
			}
		}else if(token == 'a'){
			//operasi invers trigonometri
			//kamus data lokal
			float hasil3 = 0, hasil2, hasil1 = 10;
			int o = 1,t = 1;
			char valid[6];
			
			valid[5] = '\0';
			valid[6] = '\0';
			valid[0] = token;
			i++;
			while(t < 5){
				valid[o] = input[i];
				i++;
				o++;
				t++;
			}
			while((isdigit(input[i]) || input[i] == '.') && input[i] != ')'){
				if(isdigit(input[i])){
					hasil3 = hasil3*10 + (input[i]-'0');
					i++;
				}
				else if(input[i]=='.'){
					i++;
					while(isdigit(input[i])){
						hasil2 = (input[i]-'0');
						hasil3 = hasil3 + (hasil2/hasil1);	
						hasil1 = hasil1*10;
						i++;
					}
					hasil1 = 10;
					i--;
					i++;
				}
			}
			if(input[i] == ')'){
				hasil2 = operasi_trigono(valid, hasil3, &(*invalid));
				EnqueOperand(&(*Z), hasil2, &P);
			}else{
				printf("format yang dimasukkan salah");
				*invalid = 1;
			}
		}
		else if(token == 'l'){
			//operasi logaritma
			//kamus data lokal
			float b;
			int basis_bebas = 0;
			
			if(isdigit(input[i-1])){
				b = DequeOperand(&(*Z));
				basis_bebas = 1;
			}
			
			//kamus data lokal
			double hasil3 = 0, hasil2 = 0;
			int o = 1, t = 1;
			char valid[5];
			
			valid[4] = '\0';
			valid[5] = '\0';
			valid[0] = token;
			i++;
			while(t < 4){
				valid[o] = input[i];
				i++;
				o++;
				t++;
			}
			while((isdigit(input[i]) || input[i] == '.') && input[i] != ')'){
				if(isdigit(input[i])){
					hasil3 = hasil3*10 + (input[i]-'0');
					i++;
				}
			}
			if(input[i] == ')'){
				hasil2 = operasilog(b, hasil3, valid, basis_bebas);
				EnqueOperand(&(*Z), hasil2, &P);
			}else{
				printf("format yang dimasukkan salah");
				*invalid = 1;
			}
		}else if(token == '!'){
			//operasi faktorial
			//kamus data lokal
			float a, c;
			char t;
			
			t = token;
			if(isdigit(input[i-1])){
				a = DequeOperand(&(*Z));
				c = faktorial(a);
				EnqueOperand(&(*Z), c, &P);
				
			}else{
				printf("format yang anda masukkan salah: ");
				*invalid = 1;
			}
		}
		else{
			PushStack(&(*X), token, &P);
		}
	}
	while(X->Head != NULL){
		c = PopStack(&(*X));
		EnqueOperator(&(*Z), c, &P);
	}	
}

address Create_Tree(Queue Z){
//Tujuan: membentuk tree dari queue yang telah disediakan berisi operasi postfix 
	
	address P;
	address stack[50];
	node Q;
	int i, len, top = -1;
	infotype c;
	float d;
	
	Q = Z.First;
	
	while(Q != NULL){
		if(Q->isoperator == 1){
			c = Q->oprtr;
			P = CreateNodeOperator(c);
			right(P) = stack[top--];
			left(P) = stack[top--];
		}else{
			d = Q->operand;
			P = CreateNodeOperand(d);
		}
		stack[++top] = P;
		Q = Q->next;
	}
	return(stack[0]);
}

address CreateNodeOperand(float input){
//Tujuan: membuat node bertipe tree yang berisi operand dari queue postfix

	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand = input;
	P->isOperator = 0;
	P->left = NULL;
	P->right = NULL;
	return P;
}

address CreateNodeOperator(char input){
//Tujuan: membuat node bertipe tree yang berisi operator dari queue postfix

	address P;
	P = (address) malloc (sizeof (Tree));
	P->data = input;
	P->isOperator = 1;
	P->left = NULL;
	P->right = NULL;
	return P;
}

double kalkulasi(address P){
//Tujuan: mengalkulasikan isi dari tree

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

float DequeOperand(Queue *A){
//Tujuan: menghapus queue terakhir dari suatu queue yang berisi operand
	//kamus data lokal
	float q;
	node First, Last,Throw;
	
	//program
	First = A->First;
	Last = A->Last;
	if(First == NULL){
		printf("Queue Empty");
	}else{
		if(First != Last){
			while(First->next != Last){
				First = First->next;
			}
			Throw = Last;
			q = Last->operand;
			A->Last = First;
			A->Last->next = NULL;
			free(Throw);
			return q;
		}else{
			Throw = Last;
			q = Last->operand;
			A->Last = NULL;
			A->First = NULL;
			free(Throw);
			return q;
		}	
	}
}

