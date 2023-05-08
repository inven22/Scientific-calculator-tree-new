#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header.h"



float Perkalian(float bilangan1, float bilangan2){
	return bilangan1*bilangan2;
}

float akar_pangkat_n(int x,int n){
 double eps = 1e-8;  // toleransi error
    double a, b, c;
    if (x >= 0) {  // jika x >= 0, maka interval awal adalah [0, x]
        a = 0;
        b = x;
    } else {       // jika x < 0 dan n ganjil, maka interval awal adalah [x, 0]
        if (n % 2 == 1) {
            a = x;
            b = 0;
        } else {   // jika x < 0 dan n genap, maka akar tidak terdefinisi
            printf("Akar tidak terdefinisi\n");
            return 0;
        }
    }
    c = (a + b) / 2;
    while (fabs(pow(c, n) - x) > eps) {
        if (pow(c, n) < x) {
            a = c;
        } else {
            b = c;
        }
        c = (a + b) / 2;
    }
    return c;

}


float Perpangkatan(float bilangan, float pangkat){
 	float hasil;
 	hasil=1;
 	float power=pangkat+0.0001,pow=pangkat,temp=1;
 	float i=1,n=1,j=1;
 	int tamp1=bilangan;
 	
 	if(bilangan!=0&&pangkat!=0){
 	
	while(n<=pangkat){
	 	n++;
	 	power--;
	 }
//	 if(power!=0){
////	 	pow=pow-power;
////	 	power=10*power;
////	 	pow=10*pangkat;
////	 	temp=pow+power;
//	 power=1/power;
//	 pow=pangkat*power;
//	 }
 	while(i<=pow){
 		hasil=hasil*tamp1;
 		i++;
	 } 
	 if(power!=0){
		 power=power*10;
		 while(j<=power){
	 		temp=temp*tamp1;
	 		j++;
		 } 
		 temp=akar_pangkat_n(temp,10);
		 hasil=hasil*temp;
	 }
//	 if(power!=0){
//	 hasil=akar_pangkat_n(hasil,power);
////		hasil=akar_pangkat_n(hasil,10);
//
//	 }
 	return hasil;
 	}else if(bilangan!=0&&pangkat==0){
 		return 1;
	}else{
	 	return 0;
	}
 	
 }
 
 
 float log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
}

float loga(int a){
	return log10(a);
}

float cosecan(float oprtr){
	return (1/sinus(oprtr));
}

float secan(float oprtr){
	return (1/cosinus(oprtr));
}

float cotangen(float oprtr){
	return (1/tangen(oprtr));
}



void display_animation(char *loading) {
    // Define the animation frames
    const char* frames[] = {"|", "/", "-", "\\"};
    const int num_frames = sizeof(frames) / sizeof(frames[0]);
    int i=0;
    // Loop through the animation frames
    
    while (i < 100000) {
        printf("\t\t\t\t\t\t%s %s %s\r", frames[i % num_frames],loading, frames[i % num_frames]);
       
        fflush(stdout);
        usleep(1000000);  // Wait for 100 milliseconds
        i++;
    }
    printf("\nFinish loading. click enter\n");
    system("pause");
    system("cls");
}




void menu(){
	printf("------------------------------------------\n");
	printf("|  sin  |   asin  |   *   |   V   |   ^  |\t\t\t Aturan\n");
	printf("------------------------------------------\t\t\t ------\n");
	printf("|  cos  |   acos  |   7   |   8   |   9  |  1. TrigonoMetri: Operasi Trigonometri(sudut). misal :sin(90)\n");
	printf("------------------------------------------  2. Logaritma: log(angka) atau (basis)log(angka) misal: log(10) atau 2log(2)\n");
	printf("|  tan  |   atan  |   4   |   5   |   6  |\n");
	printf("------------------------------------------\n");
	printf("|  csc  |   cot   |   1   |   2   |   3  |\n");
	printf("------------------------------------------\n");
	printf("|  sec  |   log   |   +   |   -   |   /  |\n");
	printf("-------------------------------------------\n");
	
}
