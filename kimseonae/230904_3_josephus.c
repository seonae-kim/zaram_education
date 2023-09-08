#include <stdio.h>

int main(){
	
	int round, remove = 0;
	int i = 0;
	int is_remove = 0;
	int remove_count = 0;
	int remove_num = 0;
	int match = 0;

	printf("input round, remove\n");
	scanf("%d %d", &round, &remove);

	int arr[round];
	int remove_arr[round];
	
	for(i=0; i<round; i++){
	   	arr[i] = i+1;
		remove_arr[i] = 0;
	}

	while(1){
		for(match = 0; match < round; match++)
		{
			if(remove_arr[match] == arr[remove_num]) 
			{
				break;
			}
		}
		if(match >= round)
		{
			is_remove++;
			if(is_remove%remove == 0)
			{
				printf("%d ",arr[remove_num]);
				remove_arr[remove_count] = arr[remove_num];
				remove_count++;
				is_remove = 0;
			}
		}
		remove_num++;
		if(remove_num >= round) remove_num = 0;
		if(remove_count == round) break;
	}

	return 0;
}
