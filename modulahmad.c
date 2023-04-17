#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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


int log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
}

int loga(int a){
	return log10(a);
}

