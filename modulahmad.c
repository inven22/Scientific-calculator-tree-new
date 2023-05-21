#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "header.h"

//AHMAD 
float taylor(float number)
{
    float hasil_log = 0.0;
    while (number >= 50.0)
    {
        number /= 10.0;
        hasil_log += 1.0;
    }

    while (number < 1.0)
    {
        number *= 50.0;
        hasil_log -= 1.0;
    }

    double y = number - 1.0;
    double y_pow = y;
    double t = y;
    int i = 1;

    while (i < 50)
    {
        y_pow *= y;
        t += ((i % 2 == 0) ? -1.0 : 1.0) * y_pow / (i + 1);
        i++;
    }

    hasil_log += t;

    return (float)hasil_log;
}

double ln(double x, int n) {
    if(x <= 0) {
        printf("Error: x must be positive");
        exit(1);
    }
    double sum = 0;
    double y = (x - 1) / (x + 1);
    int i;
    for(i = 1; i <= n; i++) {
        double term = pow(y, 2 * i - 1) / (2 * i - 1);
        sum += term;
    }
    return 2 * sum;
}

double log_a_to_base_b(double x, double b) {
	int n=1000000;
    if(x <= 0 || b <= 0) {
        printf("Error: x and b must be positive");
        exit(1);
    }
    double ln_x = ln(x, n);
    double ln_b = ln(b, n);
    if(ln_b == 0) {
        printf("Error: log of base 1 is undefined");
        exit(1);
    }
    return ln_x / ln_b;
}

float loga(int a){
	return log10(a);
}

