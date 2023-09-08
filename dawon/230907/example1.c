#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float add(float a,char op, float b);
float sub(float a,char op, float b);
float mul(float a,char op, float b);
float divs(float a,char op, float b);

int main()
{
	char c[20];
	char s[20];
	float a=0, b=0;
	char op;
	int i=0, j=0, h=0, k=0, m=0, l=0, x=0;
	char n[20];
	int index1=0, index2=0;
	int p=0;
	int d=0;
	float out=0;

	while(1)
	{	
		printf("formula: ");
		fgets(c,sizeof(c),stdin);
		m=0;		
		n[0]='\0';
		l=0;
		x=0;

		if(c[1] == '\n' && c[0] == 'q')
		{
			printf("program exit\n");
			break;
		}
		else if(c[1] == '\n' && c[0] != 'q')
		{
			printf("try again1\n");
			continue;
		}
	
		for(i = 0; i < 20; i++)
		{
			if(c[i] == ' ' && index1 == 0)
			{	
				index1++;

				a=atof(c);
				op = c[i+1];

				if(c[i+2] != ' ')
				{		
				    printf("try again2\n");
				    m=1;
				}
			
			}    
		    	else if(c[i] == ' ' && index1 == 1)
			{
			    for(h = i + 1; h <= 20; h++)
		      	    {
		    		if(c[h] == '\0')
				    break;

                                s[p] = c[h];
                                p++;
			    }

			    b=atof(s);

			    p=0;
			    s[0]='\0';
			    index1=0;
			    break;
			}
		      
		}

		if(m==1)
		{
		    printf("op error\n");
		    continue;
		}


		if(((a < -100000) || (a > 100000)) && ((b < -100000) || (b > 100000)))
      		{
		    printf("try again 4\n\n");
		    continue;
	        }

		printf("output: ");
		if(op == '+')
		{	
			out=add(a,op,b);
			sprintf(n,"%.3f",out);
			    
			l= strlen(n)-1;
			for(k = 0; k < 20; k++)
			{
			    if(n[k] == '.')
			    {
				index2=k;
				break;
			    }
			}
				
			for(k = l; k > index2; k--)
			{
			    if(n[k] != '0')
			    {
				x=1;
				break;
			    }
			}
			 
			if(x != 1)
			{
			    printf("%.0f\n\n",out);
			    continue;		
	       	        }

			printf("%.3f\n",out);
		}
		else if(op == '-')
		{
			out=sub(a,op,b);
			sprintf(n,"%f",out);

			l=strlen(n)-1;
			for(k = 0; k < 20; k++)
                        {
                            if(n[k] == '.')
                            {
                                index2=k;
                                break;
                            }
                        }

                        for(k = l; k > index2; k--)
                        {
                            if(n[k] != '0')
                            {
                                x=1;
                                break;
                            }
                        }

                        if(x != 1)
                        {
                            printf("%.0f\n\n",out);
                            continue;
                        }             

			printf("%.3f\n",out);
                }
		else if(op == '*')
		{
                        out=mul(a,op,b);
			sprintf(n,"%f",out);
			
			l=strlen(n)-1;

			for(k = 0; k < 20; k++)
                        {
                            if(n[k] == '.')
                            {
                                index2=k;
                                break;
                            }
                        }                       
			    
                        for(k = l; k > index2; k--)
                        {
                            if(n[k] != '0')
                            {
                                x=1;
                                break;
                            }
                        }

                        if(x != 1)
                        {
                            printf("%.0f\n\n",out);
                            continue;
                        }
	

                        printf("%.3f\n",out);
		}
		else if(op == '/')
		{
                        out=divs(a,op,b);
			sprintf(n,"%f",out);

			l=strlen(n)-1;
			for(k = 0; k < 20; k++)
                        {
                            if(n[k] == '.')
                            {
                                index2=k;
                                break;
                            }
                        }

                        for(k = l; k > index2; k--)
                        {
                            if(n[k] != '0')
                            {
                                x=1;
                                break;
                            }
                        }

                        if(x != 1)
                        {
                            printf("%.0f\n\n",out);
                            continue;
                        }
                        printf("%.3f\n",out);
                }
		else 
		        printf("try again3\n");
		
		c[0]='\0';
		printf("\n");
	}

	return 0;
}

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













