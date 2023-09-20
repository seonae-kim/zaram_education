#include <stdio.h>

int main()
{
	int hp;	
	printf("input hp:\n");
	scanf("%d", &hp);	
	int fix_hp = hp;
	int force5 = 0;
	int after5;
	int after3;
	int force3 =0;
	int force1 = 0;
	int count =0;

	while(hp >= 5)
	{
		hp = hp / 5;
	}
	
	force5 = fix_hp /5;							
	printf("number of force 5 is %d\n", force5);	

	after5= fix_hp - 5 * force5;		
	int fix_after5 = after5;			

	while(after5 >=3)					
	{
		after5 = after5/ 3;			
	}
	
	force3= fix_after5 / 3;				
	printf("number of force 3 is %d\n", force3);				

	after3 = fix_after5 - 3 * force3;	
	
	force1= after3;
	printf("number of force 1 is %d\n", force1);				

	count = force5 + force3 + force1;		
	printf("%d", count);

}
