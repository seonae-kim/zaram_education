#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float add(float a, float b)
{

    float c=0;
    c=a+b;


    return c;
}

float sub(float a, float b)
{
    float c=0;
    c=a-b;
    
    return c;
}

float mul(float a, float b)
{
    float c=0;
    c=a*b;

    return c;
}

float divs(float a, float b)
{
    float c=0;
    c=a/b;

    return c;
}

int addHexDec(int a, int b)
{
    int c=0;
    c=a+b;

    return c;
}
int subHexDec(int a, int b)
{
    int c=0;
    c=a-b;
    
    return c;    
}

int mulHexDec(int a, int b)
{
    int c=0;
    c=a*b;

    return c;
}

int divsHexDec(int a, int b)
{
    int c=0;
    c=a/b;

    return c;
}

int shftLeft(int a, int b)
{
    int c=0;
    c=a<<b;

    return c;
}

int shftRight(int a, int b)
{
    int c=0;
    c=a>>b;

    return c;
}

int isInt(float out)
{
    int x=0, l=0, k=0, index=0;
    char n[20];

    sprintf(n,"%f",out);

    l=strlen(n)-1;
    for(k = 0; k < 20; k++)
    {
        if(n[k] == '.')
        {
            index=k;
            break;
        }
     }
    for(k = l; k > index; k--)
    {
        if(n[k] != '0')
	{
            x=1;
            break;
        }
    }
    return x;
}

int isIntDec(int a)
{
    char c[20];
    int k=0;

    sprintf(c,"%d",a);
    for(int k = 0; k < 20; k++)
    {
	if( c[k] != '0' || c[k] != '1' || c[k] != '2' || c[k] != '3' || c[k] != '4' || c[k] != '5' || c[k] != '6' || c[k] != '7' || c[k] != '8' || c[k] != '9')                          
	return 0;
    }

    return 0;
}

int isIntHex(int a)
{
    char c[20];
    int k=0;

    sprintf(c,"%d",a);
    for(int k = 0; k < 20; k++)
    {
        if( c[k] != '0' || c[k] != '1' || c[k] != '2' || c[k] != '3' || c[k] != '4' || c[k] != '5' || c[k] != '6' || c[k] != '7' || c[k] != '8' || c[k] != '9' || c[k] != 'A' || c[k] != 'B' || c[k] != 'C' || c[k] != 'D' || c[k] != 'E' || c[k] != 'F')                          
        return 0;
    }

    return 0;
}


int isNum(float a)
{
    char c[20];
    int k=0;

    sprintf(c,"%f",a);
    for(int k = 0; k < 20; k++)
    {
        if( c[k] != '0' || c[k] != '1' || c[k] != '2' || c[k] != '3' || c[k] != '4' || c[k] != '5' || c[k] != '6' || c[k] != '7' || c[k] != '8' || c[k] != '9')                          
	    return 0;
    }

    return 1;
}

