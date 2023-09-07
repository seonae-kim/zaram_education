#include <stdio.h>

int main()
{

	char c;
	int a,b=0;


	while(1)
	{
		
		printf("계산식 입력: ");

		scanf("%d",&a);
		scanf("%c",&c);
		scanf("%d",&b);

		if(c=='+')
		{
			printf("%d + %d = %d\n",a,b,a+b);


		}
		else if(c=='-')
		{
			printf("%d - %d = %d\n",a,b,a-b);
		}
		else if(c=='*')
		{
			printf("%d * %d = %d\n",a,b,a*b);
		}
		else if(c=='/')
		{
			printf("%d / %d = %d\n",a,b,a/b);
		}
		else if(c=='%')
		{
			printf("%d %% %d = %d\n",a,b,a%b);
		}
		else
		{
			printf("다시 입력하세요.\n");
		}
	}
	return 0;
}

