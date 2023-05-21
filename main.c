#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	//kamus data
	int g = 1, invalid = 0;
	char input[30], temp;
	double hasil;
	address P;
	Stack S;
	Queue Z;
	node Q;
	
	while(g == 1){
		invalid = 0;
		menu();
		Z.First = NULL;
		Z.Last = NULL;
		S.Head = NULL;
		
		//scan by user 	
		printf("enter expression: ");
		scanf("%s", &input);
		fflush(stdin);
		convertPostfix(&Z, &S, input, &invalid); //mengubah operasi menjadi postfix
	
		if(invalid == 0){
			P = Create_Tree(Z); //membentuk tree
			hasil = kalkulasi(P); //mengalkulasi operasi
			printf("hasilnya adalah %g\n", hasil);
		}
		
		printf("\n 1. Lanjut \n 0. Tidak\n Pilihan Anda: ");
		scanf("%d", &g);
		fflush(stdin);
		system("cls");
	}
	display_animation("Terima kasih telah mencoba ");
	return 0;
}
