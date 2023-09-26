//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(char arr1[][50], char arr2[][50], int s1, int s2);

int main() 
{
    char players[50][50] = { 0 };
    char callings[50][50] = { 0 };
    int size1, size2;
    int i;

    printf("input players size:\n");
    scanf("%d", &size1);

    while (getchar() != '\n');

    printf("input players:\n");
    for (i = 0; i < size1; i++) 
	{
        fgets(players[i], sizeof(players[i]), stdin);
        size_t len = strlen(players[i]) - 1;
        players[i][len] = '\0';
    }

    printf("input callings size:\n");
    scanf("%d", &size2);

    while (getchar() != '\n');

    printf("input callings:\n");
    for (i = 0; i < size2; i++) 
	{
        fgets(callings[i], sizeof(callings[i]), stdin);
        size_t len2 = strlen(callings[i]) - 1;
        callings[i][len2] = '\0';
    }

    solution(players, callings, size1, size2);

    for (i = 0; i < size1; i++) 
	{
        printf("%s ", players[i]);
    }

    return 0;
}

void solution(char arr1[][50], char arr2[][50], int s1, int s2)
{
    int i, j, index;
    char temp[50]; 

    for (i = 0; i < s2; i++) 
	{
        for (j = 0; j < s1; j++) 
		{		
            if (strcmp(arr2[i], arr1[j]) == 0) 
			{
                index = j;
                break; 
            }
        }
		if(index ==0)
		{
			continue;
		}
        strcpy(temp, arr1[index - 1]);
        strcpy(arr1[index - 1], arr1[index]);
        strcpy(arr1[index], temp);
    }
}
