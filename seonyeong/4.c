#include <stdio.h>

int main() {
    int num1, num2,result;
    char op;

    printf("num1: ");
    scanf("%d", &num1);

    printf("num2: ");
    scanf("%d", &num2);

    printf("op(+, -, *, /, %, <<, >>): ");
    scanf(" %c", &op);

    if (op == '+') {
        result = num1 + num2;
    }
    else if (op == '-') {
        result = num1 - num2; 
    }
    else if (op == '*') {
        result = num1 * num2;
    }
    else if (op == '/') {
         result = num1 / num2; 
  
    }
    else if (op == '%') {
        if (num2 != 0) {
            result = num1 % num2; 
        }
        
    }
    else if (op == '<<') {
        result = num1 << num2; 
    }
    else if (op == '>>') {
        result = num1 >> num2; 
    }
    else {
        printf("error");
     }

    printf("result: %d \n", result);

    return 0;
}

