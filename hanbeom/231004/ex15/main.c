#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"

int main()
{
    char str[100];
    int count = 0;
    int i = 0;
    double result = 0;
    char operator = 'a';

    while (1)
    {
        fgets(str, sizeof(str), stdin);

        size_t len = strlen(str);

        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }

        if (strcmp(str, "q") == 0)
            break;

        len = strlen(str);

        for (i = 0; i < len; i++)
        {
            if (str[i] == ' ' && str[i + 2] == ' ')
            {
                break;
            }
        }

        double num1 = atof(str);
        double num2 = atof(str + i + 2);

        int check = 0;

        for (i = 0; i < len; i++)
        {
            if (str[i] == ' ' && str[i + 2] == ' ')
            {
                switch (str[i + 1])
                {
                case '+':
                    operator = '+';
                    check = 1;
                    break;

                case '-':
                    operator = '-';
                    check = 1;
                    break;

                case '*':
                    operator = '*';
                    check = 1;
                    break;

                case '/':
                    operator = '/';
                    check = 1;
                    break;
                }
            }
            if (check == 1)
            {
                break;
            }
        }

        switch (operator)
        {
        case '+':
            result = sum(num1, num2);
            break;
        case '-':
            result = minus(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        }

        if (result == (int)result)
        {
            printf("%d", (int)result);
        }
        else
        {
            printf("%.3f", result);
        }
        printf("\n");
    }
    return 0;
}
