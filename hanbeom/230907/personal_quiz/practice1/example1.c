#include <stdio.h>


int main() {

    char input[100];  //define numbers of chrater

    scanf("%s", input);


    int i;
    
//    printf("%s\n", input);       //check

//    printf("%s\n", &input[0]);   //check
//    printf("%s\n", &input[1]);   //check
//    printf("%s\n", &input[2]);   //check
//    printf("%s\n", &input[3]);   //check
  
      
     
    if (input[0]== 'y' && input[1] == 'e' && input[2] == 's' && input[3] == '\0' )
    {
	printf("pass");
    }

    else
    {
	printf("fail");
    }
    
}

