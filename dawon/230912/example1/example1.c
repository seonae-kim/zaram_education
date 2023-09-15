#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char array[5][20] = { 0, };
   char array2[5][20] = { 0, };
   char string[20] = { 0., };
   int n = 100;
   int index;
	
   printf("input: ");
   for (int i = 0; i < 5; i++)
   {
      scanf("%s", array[i]);
   }


   for (int j = 0; j < 5; j++)
   {
      for (int i = 0; i < 5; i++)
      {
         if (strlen(array[i]) < n)
         {
            n = strlen(array[i]);
            index = i;
         }
         if (strlen(array[i]) == n)
         {
            index = i;
         }

      }

      strcpy(array2[j], array[index]);
      memset(array[index], '1', sizeof(char) * 19);
      n = 100;

   }
   printf("\n");
   n = 1;
   int k = 0;
   int i = 0;

   for (i; i < 5; i=i+k)
   {
      if (strlen(array2[i]) == strlen(array2[i + 1]))
      {
		  k=0;
         while (strlen(array2[i]) == strlen(array2[i + n]))
         {
            k++;
            n++;
         }
         for (int j = i; j < i+k; j++)
         {
            for (int m = j+1; m <= i+k; m++)
            {
               if (strcmp(array2[m], array2[j]) < 0)
               {
                  strcpy(string, array2[j]);
                  strcpy(array2[j], array2[m]);
                  strcpy(array2[m], string);
               }
            }
         }
		 k=k+1;
      }
	  else 
		  k=1;
   }
   printf("output: ");
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         printf("%c", array2[i][j]);
      }
      printf(" ");
   }

	printf("\n");
   return 0;
}

