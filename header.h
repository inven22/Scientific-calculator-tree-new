#ifndef kalku_h
#define kalku_h
#define Data(P) (P)->data
#define right(P) (P)->right
#define left(P) (P)->left
#define Nil NULL
#include <ctype.h>

typedef char infotype;
typedef struct Elemen *address;
typedef struct Elemen {
	infotype data;
	float operand;
	address right;
	address left;
	int isOperator;
} Tree;

typedef struct Node *node;
typedef struct Node {
	node next;
	infotype oprtr;
	float operand;
	int isoperator;
} ElmtList;

typedef struct {
	node Head;
} Stack;

typedef struct {
	node First;
	node Last;
} Queue;


int derajatOperator(infotype oper);
/*
Dimasukkan parameter passing by value pada modul ini 
Tujuan: untuk mengetahui derajat dari suatu operator
*/
int isOperator(infotype oper);
//modul ini digunakan untuk mengetahui operasi logaritma mana yang digunakan 
//serta mengetahui format yang salah pada input
address CreateNode(infotype data);
//modul ini digunakan untuk membuat  node yang bertype tree
void PostOrder(address P);
//modul ini digunakan untuk tranversal Tree secara PostOrder
void PreOrder(address P);
//modul ini digunakan untuk tranversal Tree secara PreOrder
void InOrder(address P);
//modul ini digunakan untuk tranversal Tree secara InOrder
void ViewAsc(Queue First);
//modul ini digunakan untuk menampilkan queue secara ascending
void EnqueOperand(Queue *First,float item,node *P);
//modul yang digunakan untuk memasukkan interger yang merupakan operand ke queue
void EnqueOperator(Queue *First,char item,node *P);
//modul yang digunakan untuk memasukkan char yang merupakan operator ke queue
void convertPostfix(Queue *Z,Stack *X,char *input,int *invalid);
// modul  yang digunakan untuk merubah string yang berupa operasi infix menjadi postfix
// bentuk :queue
void ViewAscStack(Stack First);
//modul ini digunakan untuk menampilkan stack secara ascending
void PushStack(Stack *First,char item,node *P);
//modul ini digunakan untuk memasukkan suatu char kedalam stack
char PopStack(Stack *First);
//modul ini digunakan untuk mengeluarkan top dari stack dan mereturnkan isinya
address Create_Tree(Queue Z);
//membentuk tree  dari  queue yang telah disediakan yang berisikan postfix
address CreateNodeOperand(float input);
//untuk membuat node dengan tipe tree yang berisikan operand dari queue postfix
address CreateNodeOperator(char input);
//untuk membuat node dengan tipe tree yang berisikan  operator dari queue postfix
double kalkulasi(address P);
//// untuk mengkalkulasikan isi dari tree
float operasi_trigono(char* tes,float oprtr,int *invalid);
//modul ini digunakan untuk mengetahui operasi trigono mana yang digunakan 
//serta mengetahui format yang salah pada input
float DequeOperand(Queue *A);
//float operasi_trigono(char* tes,float oprtr);
float operasilog(float a,float b,char *tes,int basis_bebas);
//modul ini digunakan untuk mengetahui operasi logaritma mana yang digunakan 
//serta mengetahui format yang salah pada input
//Tendy
float Perkalian(float bilangan1, float bilangan2);
float akar_pangkat_n(int x,int n);
float Perpangkatan(float bilangan, float pangkat);
float cosecan(float oprtr);
float secan(float oprtr);
float cotangen(float oprtr);
void menu();
void loading();
void display_animation(char *loading);


//Mahira
float persen(float bil);
float faktorial(float bil);
float asinus(float bil);
float acosinus(float bil);
float atangen(float bil);

float mutlak(float bil);
float arcsin(float bil);
float squareroot(float x);

//Agista
double cosinus(double degree);
double tangen(double degree);
double sinus(double degree);
double to_radian(double degree);


//Ahmad
float loga(int a);
float log_a_to_base_b(int a, int b);


#endif


