#include <stdio.h>
#include <math.h>
#include "header.h"
#define phi 3.14


float persen(float bil)
{
	return bil/100;
}

float mutlak(float bil)
{
	if(bil < 0)
	{
		return -bil;
	}
	else if(bil >= 0)
	{
		return bil;
	}
}

float faktorial(float bil)
{
	int result = 1, i = 0;
	
	if(bil == 0)
	{
		return 1;
	}
	else
	{
		while(i < bil)
		{
			result = result*(bil-i);
			i++;
		}
		return result;	
	}
}

float asinus(float bil)
{
	//kamus data lokal
    float jumlah = bil;
    float term = bil;
    int n = 1;

	//program
    while(mutlak(term) > 0.000001) //menggunakan deret taylor
	{
    	term = term*bil*bil*(2*n-1)*(2*n-1)/(2*n*(2*n+1));
		jumlah = jumlah + term;
        n++;
    }
    return jumlah*180.0/phi;
}

float acosinus(float bil)
{
	//kamus data lokal
	float jumlah = bil;
    float term = bil;
    int n = 1;
    
    //program
    while(mutlak(term) > 0.000001) //menggunakan deret taylor
	{
    	term = term*bil*bil*(2*n-1)*(2*n-1)/(2*n*(2*n+1));
		jumlah = jumlah + term;
        n++;
    }
    return ((phi/2)-jumlah)*180.0/phi;
}

float squareroot(float x) 
{
	//kamus data lokal
    float tebakan = 1.0;
    float prev_tebakan;
    float selisih;
    
    //program
    do 
	{
		prev_tebakan = tebakan;
		tebakan = 0.5 * (tebakan + x / tebakan);
		selisih = tebakan - prev_tebakan;
    }while(selisih > 0.000001 || selisih < -0.000001);
    return tebakan;
}

float atangen(float bil)
{
	//kamus data lokal
	float jumlah, akar, bagi;
	
	//program
	akar = squareroot(1+bil*bil);
	bagi = 1/akar;
	jumlah = acosinus(bagi);
	return jumlah;
}
