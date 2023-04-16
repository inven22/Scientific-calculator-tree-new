#include <stdio.h>
#include <stdlib.h>
#include "header.h"

double penjumlahan(double a, double b) {
    return a + b;
}

double pengurangan(double a, double b) {
    return a - b;
}

//double sinus(double degree){
//	double hasil;
//	hasil = (sin(degree*(phi/180)));
//	return hasil;
//}
//
//double cosinus(double degree){
//	double hasil;
//	hasil = (cos(degree*(phi/180)));
//	return hasil;
//}
//
//double tangen(double degree){
//	double hasil;
//	hasil = (tan(degree*(phi/180)));
//	return hasil;
//}
//
//double pembulatan(double num){
//    return round(num);
//}

// konversi sudut dalam derajat ke radian
double to_radian(double degree) {
    return degree * (3.14159265359 / 180.0);
}

// menghitung nilai sinus
double sinus(double degree) {
    double radian = to_radian(degree);
    double result = radian;
    double term = radian;
    int i;

    for (i = 1; i <= 10; i++) {
        term = -term * radian * radian / ((2 * i) * (2 * i + 1));
        result += term;
    }

    return result;
}

// menghitung nilai kosinus
double cosinus(double degree) {
    double radian = to_radian(degree);
    double result = 1;
    double term = 1;
	int i;
    for (i = 1; i <= 10; i++) {
        term = -term * radian * radian / ((2 * i - 1) * (2 * i));
        result += term;
    }

    return result;
}

double tangen(double degree) {
    return sinus(degree) / cosinus(degree);
} 
