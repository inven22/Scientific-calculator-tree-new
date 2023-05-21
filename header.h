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
//Dimasukkan parameter passing by value pada modul ini 
//Tujuan: untuk mengetahui derajat dari suatu operator

float operasi_trigono(char *tes, float oprtr, int *invalid);
//Tujuan: mengetahui operasi trigonometri yang digunakan 

float operasilog(float a, float b, char *tes, int basis_bebas);
//Tujuan: mengetahui operasi logaritma yang digunakan 

int isOperator(infotype oper);
//Tujuan: mengetahui char dari string apakah sebuah operator

address CreateNode(infotype data);
//Tujuan: membuat node bertipe Tree

void PostOrder(address P);
//Tujuan: traversal Tree secara PostOrder

void PreOrder(address P);
//Tujuan: traversal Tree secara PreOrder

void InOrder(address P);
//Tujuan: traversal Tree secara InOrder

void PushStack(Stack *First, char item, node *P);
//Tujuan: memasukkan suatu char kedalam stack

char PopStack(Stack *First);
//Tujuan: mengeluarkan top dari stack dan mengembalikan isinya

void ViewAsc(Queue First);
//Tujuan: menampilkan queue secara ascending

void ViewAscStack(Stack First);
//Tujuan: menampilkan stack secara ascending

void EnqueOperator(Queue *First, char item, node *P);
//Tujuan: memasukkan operator bertipe data char ke queue

void EnqueOperand(Queue *First, float item, node *P);
//Tujuan: memasukkan operand bertipe data integer ke queue

void convertPostfix(Queue *Z, Stack *X, char *input, int *invalid);
//Tujuan: mengubah string berupa operasi infix menjadi postfix
//Bentuk: queue

address Create_Tree(Queue Z);
//Tujuan: membentuk tree dari queue yang telah disediakan berisi operasi postfix

address CreateNodeOperand(float input);
//Tujuan: membuat node bertipe tree yang berisi operand dari queue postfix

address CreateNodeOperator(char input);
//Tujuan: membuat node bertipe tree yang berisi operator dari queue postfix

double kalkulasi(address P);
//Tujuan: mengalkulasikan isi dari tree

float DequeOperand(Queue *A);
//Tujuan: menghapus queue terakhir dari suatu queue yang berisi operand


/* ===================================== Function ===================================== */

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
double log_a_to_base_b(double x, double b);



#endif
