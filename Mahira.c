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
    float sum = bil;
    float term = bil;
    int n = 1;
//    mutlak(term) > 0.000000000001
    while(mutlak(term) > 0.000001) 
	{
    	term = term*bil*bil*(2*n-1)*(2*n-1)/(2*n*(2*n+1));
		sum = sum + term;
        n++;
    }
    return sum*180.0/phi;
}

float acosinus(float bil)
{
	float sum = bil;
    float term = bil;
    int n = 1;
//    mutlak(term) > 0.000000000001
    while(mutlak(term) > 0.000001) 
	{
    	term = term*bil*bil*(2*n-1)*(2*n-1)/(2*n*(2*n+1));
		sum = sum + term;
        n++;
    }
    return ((phi/2)-sum)*180.0/phi;
}

//float atangen(float bil)
//{
//	float sum = 0.0;
//    float term = bil;
//    int n = 1;
////    mutlak(term) > 0.00000000000001
//    while(term != 0.0) 
//	{
//		sum = sum + term;		
//        term = term*-bil*bil/(2*n+2);
//        n++;
//    }
//    return sum*180.0/phi;
//}

float squareroot(float x) 
{
    float tebakan = 1.0;
    float prev_tebakan;
    float selisih;
    
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
	float sum, akar, bagi;
	akar = squareroot(1+bil*bil);
	bagi = 1/akar;
	sum = acosinus(bagi);
	return sum;
}
