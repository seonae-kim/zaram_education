#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	char word[200] = {0,};
	char word2[200] = {0,};
	char word3[200] = {0,};
	int new[200] = {0,};
	int i = 0;
	int k = 0;
	int a = 0;
	int num[200] = {0,};
	int num2[200] = {0,};
	int index_2 = 0;
	int index_3 = 0;

	printf("input the sentence: ");
	
	fgets(word, sizeof(word), stdin);

	for(i =0 ; i < strlen(word) -1 ; i++)			
	{
		if(word[i] >= 'a' && word[i] <= 'z')	// alphabet
		{ 
			word2[index_2] = ' ';
			index_2++;
		}
		else if(word[i] >= '0' && word[i] <= '9')	//number
		{
			word2[index_2] = word[i];
			index_2++;
		}
		else if (word[i] == ' ')
		{
			word2[index_2] = ' ';
			index_2++;
		}
	}

	for(i= 0; i < strlen(word2) ; i++)
	{
		if(word2[i] >= '0' && word2[i] <= '9')		//  number
		{
			a = word2[i] - '0';
			num[index_3] = a;
			index_3++;
		}
		else
		{
			num[index_3]= 50000;
			index_3++;
		}
	}
	
	int *ptr = num;

	while (*ptr != '\0')
	{
		ptr++;
	}
	ptr = num;    

	int *ptr2 = new;

	while (*ptr != '\0')
	{
		if(*ptr >=0 && *ptr <= 9)                                     
		{
			if(ptr == num)
			{
				*ptr2 = *ptr;
				ptr2++;
			}
			else if(*(ptr - 1) >= 0 && *(ptr - 1) <= 9)  
			{
				ptr2--;
				*ptr2 = 10 *  *ptr2 + *ptr;                   
				ptr2++; 
			}
			else       
			{
				*ptr2 = *ptr;
				ptr2++;
			} 	
		}
		ptr++;
	}
	
	ptr2 = new; //reset
	
	while(*ptr2 != '\0')
	{
		ptr2++;
	}

	int min = new[0];
	int mingroup[200];
	int minindex;
	int j;

	for(i = 0; i <sizeof(new) / sizeof(int) ; i++)
	{
		if(new[i] == 0)
		{
			new[i] = 99999;
		}
	}

	for(i = 0; i <sizeof(new) / sizeof(int) ; i++)
	{
		for(j = 0; j < sizeof(new) / sizeof(int); j++)
		{
			if(new[j] < min)
			{
				min = new[j];
				minindex = j;
			}
		}
		mingroup[i] =min;
		new[minindex] = 99999;
		min =100000;
	}


	for( i = 0; i < sizeof(mingroup)/ sizeof(int) ; i++)
	{	
		for(j = i+1; j < sizeof(mingroup) / sizeof(int); j++)
		{
			if(mingroup[i] == mingroup[j])
			{
				mingroup[j] = 99999;
			}
		}
	}

	int finalgroup[100];
	int newsize =0;
	for (i = 0; i < sizeof(mingroup) / sizeof(int); i ++)
	{
		if(mingroup[i] != 99999)
		{
			finalgroup[newsize] = mingroup[i];
			newsize++;
		}
	}

	for( i = 0; i < newsize ; i++)
	{
		printf("%d ", finalgroup[i]);
	}

}





                                                           






