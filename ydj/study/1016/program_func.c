int CountLine(FILE *fp)
{
	char temp = '0';
	int cnt_line = 0;
	fseek(fp, 0, SEEK_SET);
	while (fscanf(fp, "%c", &temp) != EOF)
	{
		if (temp == '\n')
		{
			cnt_line++;
		}
	}
	return cnt_line;
}


int RegistNew(FILE *fp, struct member *new_ptr, int i)
{
	int j = 0, flag = 0;
	int year = 0, month = 0, date = 0, cal_date;
	char date_c[10] = {0};

	fp = fopen("member_info.txt", "a+");
	if (fp == NULL)
	{
		printf("Fail to open file, Try again \n");
	}

	printf("Please enter the NEW member's INFO \n");
	printf("NAME : ");
	scanf("%s", (new_ptr + i)->name);
//	scanf("%s", new[i].name);

	for (j = 0; j < i; j++)
	{
		if (strcmp((new_ptr + i)->name, (new_ptr + j)->name) == 0)
		{
			printf("\n");
			printf("Oops~ The name is same!!\n");
			printf("Back to the start menu\n\n");
			flag++;
		}
	}
	if (flag == 1)
	{
		flag = 0;
		return 1;
	}

	printf("AGE : ");
	scanf("%d", &((new_ptr + i)->age));

	printf("Registration Period : ");
	scanf("%d", &((new_ptr + i)->remain));

	strftime((new_ptr + i)->start, sizeof((new_ptr + i)->start), "%Y%m%d%H%M", localtime(&now));
	strftime(date_c, sizeof(date_c), "%Y%m%d", localtime(&now));
	date = atoi(date_c);

	date = date + (100 * (new_ptr + i)->remain);
	if (date % 10000 > 1300)
	{	
		month = (date % 10000) % 1200;
		year = (date / 10000) + (date % 10000) / 1200;
	}
	else
	{
		month = date % 10000;
		year = date / 10000;
	}

	cal_date = year * 10000 + month;

	(new_ptr + i)->end = cal_date;
				
	fprintf(fp, "%10s\t\t%2d\t\t%12s\t%8d\t%-2d \n", (new_ptr + i)->name, (new_ptr + i)->age, (new_ptr + i)->start, (new_ptr + i)->end, (new_ptr + i)->remain);

	fclose(fp);
	flag = 0;
	return 0;
}


int ExtPeriod(FILE *fp, struct member *new_ptr, int cnt_line)
{
	char find_name[10] = {0};
	char comp_name[10] = {0};

	int i = 0, x = 0;
	int year = 0, month = 0, ext_period = 0;

	printf("Enter the name : ");
	scanf("%s", find_name);
				
	fseek(fp, 39, SEEK_SET);
	for (i = 0; i < cnt_line - 1; i++)
	{
		fscanf(fp, "%s%*d%*s%*d%*d", comp_name);
		if (strcmp(find_name, comp_name) == 0)
		{
			printf("\n");
			x = i;
			break;
		}
	}

	printf("Enter the extension period : ");
	scanf("%d", &ext_period);

	month = 0;
	year = 0;

	(new_ptr + x)->remain = (new_ptr + x)->remain + ext_period;
	(new_ptr + x)->end = (new_ptr + x)->end + (100 * ext_period);

	if ((new_ptr+ x)->end % 10000 > 1300)
	{
		month = ((new_ptr + x)->end % 10000) % 1200;
		year = ((new_ptr + x)->end / 10000) + ((new_ptr + x)->end % 10000) / 1200;
	}
	else
	{
		month = (new_ptr + x)->end % 10000;
		year = (new_ptr + x)->end / 10000;
	}

	(new_ptr + x)->end = year * 10000 + month;
				
	fseek(fp, 42 * x + 68, SEEK_SET);
	fprintf(fp, "%d", (new_ptr + x)->end);
	fseek(fp, 1, SEEK_CUR);
	fprintf(fp, "%d", (new_ptr + x)->remain);

	printf("MEMEBERSHIP period sucessfully changed!! \n");

	fclose(fp);
	cnt_line = 0;
	x = 0;
	return 0;
}


int HandOverPeriod(FILE *fp, struct member *new_ptr, int cnt_line)
{
	char lev_name[20] = {0};
	char add_name[20] = {0};
	char comp_name[10] = {0};
	int i = 0, x = 0, y = 0;
	int year = 0, month = 0;

	printf("Please enter member's name to leave : ");
	scanf("%s", lev_name);

	printf("Please enter member's name to add membership period : ");
	scanf("%s", add_name);

	fseek(fp, 39, SEEK_SET);
	for (i = 0; i < cnt_line - 1; i++)
	{
		fscanf(fp, "%s%*d%*s%*d%*d", comp_name);
		if (strcmp(lev_name, comp_name) == 0)
		{
			printf("\n");
			x = i;
		}
		else if (strcmp(add_name, comp_name) == 0)
		{
			printf("\n");
			y = i;
		}	
	}
			
	(new_ptr + y)->remain = (new_ptr + y)->remain + (new_ptr + x)->remain;
	(new_ptr + y)->end = (new_ptr + y)->end + (100 * (new_ptr + x)->remain);

	if ((new_ptr + y)->end % 10000 > 1300)
	{
		month = ((new_ptr + y)->end % 10000) % 1200;
		year = ((new_ptr + y)->end / 10000) + ((new_ptr + y)->end % 10000) / 1200;
	}
	else
	{
		month = (new_ptr + y)->end % 10000;
		year = (new_ptr + y)->end / 10000;
	}

	(new_ptr + y)->end = year * 10000 + month;

	fseek(fp, 42 * y + 68, SEEK_SET);
	fprintf(fp, "%d", (new_ptr + y)->end);
	fseek(fp, 1, SEEK_CUR);
	fprintf(fp, "%d", (new_ptr + y)->remain);

	fseek(fp, 42 * x + 39, SEEK_SET);
	for (i = x; i < cnt_line - 1; i++)
	{
		fprintf(fp, "%10s\t\t%2d\t\t%12s\t%8d\t%-2d \n", (new_ptr + i + 1)->name, (new_ptr + i + 1)->age, (new_ptr + i + 1)->start, (new_ptr + i + 1)->end, (new_ptr + i + 1)->remain);
	}

	fclose(fp);
	printf("MEMEBERSHIP period sucessfully changed!! \n");

	return 0;
}


int RemvMember(FILE *fp, struct member *new_ptr, int cnt_line)
{
	int i = 0, j = 0, x = 0;	
	char rm_name[20] = {0};
	char comp_name[20] = {0};

	printf("Please enter the name you want to remove : ");
	scanf("%s", rm_name);
	fseek(fp, 39, SEEK_SET);
	for (i = 0; i < cnt_line - 1; i++)
	{
		fscanf(fp, "%s%*d%*s%*d%*d", comp_name);
		if (strcmp(rm_name, comp_name) == 0)
		{
			printf("\n");
			x = i;
			break;
		}
	}

	fseek(fp, 42 * x + 39, SEEK_SET);
	for (i = x; i < cnt_line - 1; i++)
	{
		fprintf(fp, "%10s\t\t%2d\t\t%12s\t%8d\t%-2d \n", (new_ptr + i + 1)->name,(new_ptr + i + 1)->age, (new_ptr + i + 1)->start, (new_ptr + i + 1)->end, (new_ptr + i + 1)->remain);
	}

	fclose(fp);

	printf("\n");
	printf("Successfully removed!!  \n");
	return 0;
}


int FindMember(FILE *fp, struct member *new_ptr, int cnt_line)
{
	int i = 0, x = 0; 
	char search_name[20] = {0};
	char comp_name[20] = {0};

	printf("Please enter the name you want to search : ");
	scanf("%s", search_name);
	fseek(fp, 39, SEEK_SET);
	for (i = 0; i < cnt_line - 1; i++)
	{
		fscanf(fp, "%s%*d%*s%*d%*d", comp_name);
		if (strcmp(search_name, comp_name) == 0)
		{
			printf("\n");
			x = i;
			break;
		}
	}

	printf("  ---->    \tNAME\t\tAGE\t\t   start\t  end\t\tremain \n");
	printf("  ---->  %10s\t\t%2d\t\t%12s\t%8d\t%-2d \n", (new_ptr + x)->name, (new_ptr + x)->age, (new_ptr + x)->start, (new_ptr + x)->end, (new_ptr + x)->remain);

	fclose(fp);

	return 0;
}


int AllMember(FILE *fp, struct member *new_ptr, int cnt_line)
{
	char all_member[50] = {0};
	int x = 0;
	printf("The Entire MEMBER INFO will be appeard !! \n");
	printf("==================================================================================\n");
	printf("  \tNAME\t\tAGE\t\t   start\t  end\t\tremain \n");
	fseek(fp, 39, SEEK_SET);

	for (x = 0; x < cnt_line - 1; x++)
	{
		fgets(all_member, sizeof(all_member), fp);
		puts(all_member);
//		printf("%s", all_member);
//		printf("%10s\t\t%2d\t\t%12s\t%8d\t%-2d \n", new[x].name, new[x].age, new[x].start, new[x].end, new[x].remain);
	}
	return 0;
}


int RenewMember(FILE *fp, struct member *new_ptr, int cnt_line)
{
	int i = 0;
	int ent_period = 0;
	int year = 0, month = 0; 
	char ans = '0';
	
	printf("\n");
	printf("***** Warning *****\n");
	printf("This mode will renew ALL member's membership\n\n");

	printf("Please enter extension period : ");
	scanf("%d", &ent_period);
				
	printf("\nThe extension perid is %d \n", ent_period);
	printf("Do you really want to change it? (Y/N) : ");
	scanf(" %c", &ans);

	if (ans == 'Y' || ans == 'y')
	{
		month = 0;
		year = 0;
	
		for (i = 0; i < cnt_line - 1; i++)
		{
			(new_ptr + i)->remain = (new_ptr + i)->remain + ent_period;
			(new_ptr + i)->end = (new_ptr + i)->end + (100 * ent_period);
			if ((new_ptr + i)->end % 10000 > 1300)
			{
				month = ((new_ptr + i)->end % 10000) % 1200;
				year = ((new_ptr + i)->end / 10000) + ((new_ptr + i)->end % 10000) / 1200;
			}
			else
			{
				month = (new_ptr + i)->end % 10000;
				year = (new_ptr + i)->end / 10000;
			}
			(new_ptr + i)->end = year * 10000 + month;
					
			fseek(fp, 42 * i + 68, SEEK_SET);
			fprintf(fp, "%d", (new_ptr + i)->end);
			fseek(fp, 1, SEEK_CUR);
			fprintf(fp, "%d", (new_ptr + i)->remain);
		}
	}
	printf("\n\nEntire member's period extension is done !\n");
	return 0;
}
