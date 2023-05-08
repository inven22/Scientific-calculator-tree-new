#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// operasi penjumlahan
double penjumlahan(double a, double b) {
    return a + b;
}

// operasi pengurangan
double pengurangan(double a, double b) {
    return a - b;
}

// membulatkan desimal
int pembulatan(double num) {
    int result = 0;
    if (num >= 0.5) {
        result = (int)(num + 0.5);
    } else {
        result = 0;
    }
    return result;
}

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

// menghitung nilai tangen
double tangen(double degree) {
    return sinus(degree) / cosinus(degree);
} 
