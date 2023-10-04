#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    FILE* file;
    char line[100]; 

    file = fopen("current_time.txt", "r");

    if (file == NULL)
    {
        printf("can't open file\n");
        return 1;
    }

    printf("file is:\n");
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}
