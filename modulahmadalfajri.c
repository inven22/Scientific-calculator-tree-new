
#include <stdio.h>
#include <stdlib.h>
float loga(float number)
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

float log_a_to_base_b(float a, float b)
{
    float count = 0;
    while (a >= b)
    {
        a /= b;
        count++;
    }
    return count;
}

void tampil()
{
    float hasil, a, b;
    a = 4;
    b = 2;
    hasil = log_a_to_base_b(a, b);
    printf("%.2f,", hasil); // menggunakan koma sebagai separator desimal dan dua digit desimal setelah koma
}

