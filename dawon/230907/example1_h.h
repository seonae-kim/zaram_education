#include <stdio.h>
#include <stdlib.h>

float add(float a,char op, float b);
float sub(float a,char op, float b);
float mul(float a,char op, float b);
float divs(float a,char op, float b);
int isInt(float out);
int isNum(float a)

float add(float a,char op, float b)
{

    float c=0;
    c=a+b;


    return c;
}
float sub(float a,char op, float b)
{
    float c=0;
    c=a-b;
    
    return c;
}
float mul(float a,char op, float b)
{
    float c=0;
    c=a*b;

    return c;
}
float divs(float a,char op, float b)
{
    float c=0;
    c=a/b;

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

int isNum(float a)
{
    char c[20];
    int k=0;

    sprintf(c,"%f",a);
    for(int k = 0; k < 20; k++)
    {
        if( c[k] != '0' || c[k] != '1' || c[k] != '2' || c[k] != '3' | |c[k] != '4' | |c[k] != '5' || c[k] != '6' || c[k] != '7' || c[k] != '8' || c[k] != '9')                          
	    return 0;
    }

    return 1;
}

