#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 100

int main() {
    char filename[] = "current_time.txt";
    char tempFilename[] = "temp_data.txt";
    char inputDate[11]; 
    char line[MAX_LINE_LENGTH]; 

    printf("input date (yyyy-mm-dd): ");
    scanf("%s", inputDate);		

    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("can't open  file\n");
        return 1;
    }

    FILE* tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) 
    {
        printf("can't open temp file\n");
        fclose(file);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) 	
    {
        char lineDate[11];  
        strncpy(lineDate, line+14, 10);		
        lineDate[10] = '\0';

        int cmpResult = strcmp(lineDate, inputDate);           

        if (cmpResult > 0)               
        {
            fputs(line, tempFile);
        }
        else if (cmpResult < 0)
        {
            fputs("", tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename(tempFilename, filename);
    printf("delete before data.\n");
    return 0;
}

