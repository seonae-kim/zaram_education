#include <stdio.h>
#include <stdlib.h>

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
	int i=0, j=0, h=0;
	int index=0;
	int p=0;
	int d=0;
	while(1)
	{	
		printf("formula: ");
		scanf("%s",c);

		for(int k=0;k<20;k++)
		{
		    printf("%c",c[k]);
		    if(c[k] == '\0')
			break;
		}
		
		if((int)c[1] == 0 && (int)c[0] == 113)
		{
			printf("program exit\n");
			break;
		}
		else if((int)c[1] == 0 && (int)c[0] != 113)
		{
			printf("try again1\n");
			continue;
		}
		
		for(int k = 0; k < 20; k++)
		{
		    d++;
		    if(c[k] == '\0')
			break;
		}



		for(i = 0; i < 20; i++)
		{
			if(c[i] == ' ' && index == 0)
			{	
				index++;
				a=atof(c);
				op = c[i+1];

			}    
		    	else if(c[i] == ' ' && index == 1)
			{
			    for(h = i + 1; h <= d ; h++)
			    {
                                s[p] = c[h];
                                p++;
			    }

			    b=atof(s);
			    p=0;
			    s[0]='\0';
			    index=0;
			    break;
			}
				        
		}

		printf("a: %f\n",a);
		printf("b: %f\n",b);
		printf("op: %c\n",op);
		
		printf("output: ");

		if(op == '+')//conflict
			add(a,op,b);//conflict
		else if(op == '-')
			sub(a,op,b);
		else if(op == '*')
			mul(a,op,b);
		else if(op == '/')
			divs(a,op,b);
		else 
		        printf("try again2\n");
		
		c[0]='\0';


	}

	return 0;
}

float add(float a,char op, float b)
{	

    printf("%.3f\n",a+b);

}

float sub(float a,char op, float b)
{

    printf("%.3f\n",a-b);

}

float mul(float a,char op, float b)
{

    printf("%.3f\n",a*b);

}

float divs(float a,char op, float b)
{

    printf("%.3f\n",a/b);

}













