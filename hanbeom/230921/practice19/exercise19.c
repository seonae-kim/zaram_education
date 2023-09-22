#include <stdio.h>
#include <string.h>

int main() {
    char word[50][50] = {0};
    char str[50] = {0};
    int k = 0;
    int i;
    int j = 0;

    fgets(str, sizeof(str), stdin); // abxaxabx

    size_t len = strlen(str) - 1;

    for (i = 0; i < len + 1; i++) 
	{
        if (str[i] != 'x' && str[i] != '\n') 
		{
            word[k][j] = str[i];
            j++;	
        } 
		else if (str[i] == 'x') 
		{
            k++;
            j = 0;
        } 
		else if (str[i] == '\n' && str[i - 1] != 'x') 
		{
            k++;
            j = 0;
		}
    }
    
    for (i = 0; i < k - 1; i++) 
	{
        int min_index = i;
        for (j = i + 1; j < k; j++) 
		{
            if (strcmp(word[j], word[min_index]) < 0) //strcmp	// word[j] < word[min_index]
			{
                min_index = j;
            }
        }
        char temp[50];		//temp = {a,abc,ab}
		strcpy(temp, word[i]);			//strcpy
        strcpy(word[i], word[min_index]);
        strcpy(word[min_index], temp);
    }

    for (i = 0; i < k; i++) 
	{
        printf("%s ", word[i]);
    }
}




