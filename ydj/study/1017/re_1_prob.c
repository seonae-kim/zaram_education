#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"program_func.h"
//#include"struct_mem_new.h"

enum menu
{
	regist = 1,
	extension = 2,
	handover = 3,
	remov = 4,
	find = 5,
	allfind = 6,
	renew = 7
} prog_mode;

struct member 
{
	char name[20];
	int age;
	char start[20];
	int end;
	int remain;
};


int main()
{
	char datetime[20];
	
	printf("\n");
	printf("\n");
	
	FILE *fp;
	int num = 0;
	char mode = 0;
	int i = 0, j = 0, x = 0, flag = 0;
	int period = 0, month = 0, year = 0, date = 0, cal_date = 0;
	char date_c[10] = {0};
	struct member new[100];
	struct member *mem_pt = new;
	int remain = 0;

	char temp = '0';
	int cnt_line = 0;
	char comp_name[10] = {0};
	char origin[1000] = {0};
	
	// 3. hand over membership period
	int y = 0;

	// 4. remove member
//	char rm_name[20] = {0};

	// 5. search member
//	char search_name[20] = {0};

	// 6. print all member
//	char all_member[50] = {0};

	// 7. Renew ALL member's period
	int ent_period = 0;
	char ans = 0;

	
	int mode_i = 0;


	printf("\t\t __________________________________________ \n");
	printf("\t\t| MEMBERSHIP PROGRAM                       |\n");
	printf("\t\t| 1. Register a new member                 |\n");		   
	printf("\t\t| 2. Extension of membership period        |\n");
	printf("\t\t| 3. NOT SUPPORTED                         |\n");
	printf("\t\t| 4. Remove member INFO                    |\n");
	printf("\t\t| 5. Find member's INFO                    |\n");
	printf("\t\t| 6. All member's INFO                     |\n");
	printf("\t\t| 7. Renew All member's period             |\n");
	printf("\t\t|__________________________________________|\n");
	printf("\n\n");
	
	fp = fopen("member_info.txt", "a");
	fprintf(fp, "  \tNAME\t\tAGE\t\t   start\t\t  end\t\tremain \n");
	fclose(fp);

	printf("If you want to exit this prgram, Press q \n");
	while(1)
	{	
		printf("Choose the mode : ");
		scanf("%d", &mode_i);
		scanf("%c", &mode);	
		prog_mode = mode_i;

		if (mode == 'q')
		{
			printf("\nBye !~!\n\n");
			break;
		}
		
		switch(prog_mode)
		{
			case regist :
				
				FileOpen_a(fp);
				flag = RegistNew(fp, mem_pt, i);
				if (flag == 1)
				{
					flag = 0;
					break;
				}
				i++;

				break;

			case extension :

				FileOpen(fp);
				cnt_line = CountLine(fp);
				ExtPeriod(fp, mem_pt, cnt_line);

				break;

			case handover :

				FileOpen(fp);
				cnt_line = CountLine(fp);
				HandOverPeriod(fp, mem_pt, cnt_line);

				break;

			case remov :

				FileOpen(fp);
				cnt_line = CountLine(fp);
				RemvMember(fp, mem_pt, cnt_line);

				break;

			case find :
				
				FileOpen(fp);
				cnt_line = CountLine(fp);
				FindMember(fp, mem_pt, cnt_line);

				break;

			case allfind :

				FileOpen(fp);
				cnt_line = CountLine(fp);
				AllMember(fp, mem_pt, cnt_line);

				break;

			case renew :

				FileOpen(fp);
				cnt_line = CountLine(fp);
				RenewMember(fp, mem_pt, cnt_line);

				break;
		}
	printf("\n");
	}
	return 0;
}

