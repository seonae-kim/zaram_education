/*member_program*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
 	char name[20];
 	int age;
 	int period;  
	struct tm reg_t; 
    struct tm end_t; 
    struct tm diff_t;
}MEMBER;

enum {
	REGISTER = 1,
	PROLONG,
	HAND_OVER,
	DELETE_MEMBER,
	SEARCH_MEMBER,
	SEARCH_ALL_MEMBER,
	RENEW_ALL_MEMBER,
	END,
};

struct tm* get_time(); //현재 시각 
int compare(MEMBER *m, int *seq, char *spec_mem);
void register_member(MEMBER *m, int *seq); //신규회원 등록 
void expansion_period(MEMBER *m, int *seq, int expansion, int spec_num); //기존 회원 기간 연장 
void delete_member(MEMBER *m, int *total_member, int spec_num,int *seq);//회원 삭제 
void hand_over(MEMBER *m, int spec_num, int receive_num, int *seq,int *total_member); // 회원권 양도 
int print_specific_member(MEMBER *m, int spec_num);//특정 회원정보 조회 
int print_all_member(MEMBER *m, int *seq); //전체 정보 조회 
void update_period(MEMBER *m, int *seq); //전체회원 남은 기간 갱신 
void load_data(MEMBER *m, int *seq);           
void save_data(MEMBER *m, int seq);
int memo_print_member(MEMBER *m, int *seq); 
int main() {
	
	FILE *fp = fopen("Member_list.txt", "r");
		if (fp == NULL) {
		printf(" \n");
		return -1;
	}
	struct tm* t;
	char spec_mem[20]; //양도자 
	char receive_mem[20]; //양수자 
	int total_member = 50; //총 회원 수 
	int mode = 0;
	int seq = 0; // 현재 회원 수 
	int expansion = 0; //연장 기간 
	int spec_num = 0; // 특정 회원번호 
	int receive_num = 0; //양도 받을 회원번호 
	int exit = 0;
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);
	MEMBER *m = (MEMBER*)malloc(sizeof(MEMBER) *total_member);
	
	load_data(m, &seq);	
	while(!exit)
	{
		printf("\n1.신규 회원 등록\n");
		printf("2.기존 회원 기간 연장\n");
		printf("3.회원권 양도\n");
		printf("4.회원 삭제\n");
		printf("5.특정 회원 정보 조회 (이름 입력)\n");
		printf("6.전체 정보 조회\n");
		printf("7.전체 회원 남은 기간 갱신\n");
		printf("8. 종료 \n\n"); 
		printf("모드:");	
		scanf("%d", &mode);
		if(mode < 0 || mode > 7)
		{	
			printf("1~7을 선택해주세요"); 
		}
		
		switch(mode)
		{
			case REGISTER:
				{
					printf("1.회원등록\n\n");
					register_member(m,&seq);
					memo_print_member(m,&seq);
					save_data(m,seq);				
					break;
				}
			case PROLONG:
				{
					printf("2번:기간연장\n\n");
					printf("대상자:"); 
					scanf("%s", spec_mem);
					spec_num = compare(m,&seq,spec_mem);
					printf("기간:"); 
					scanf("%d", &expansion);
					expansion_period(m,&seq,expansion,spec_num);
					memo_print_member(m,&seq);
					save_data(m,seq);
					break;
				}
			case HAND_OVER:
				{
					printf("3번:회원양도\n\n");
					printf("양도자:"); 
					scanf("%s", spec_mem);
					spec_num = compare(m,&seq,spec_mem);
					printf("수신자:");
					scanf("%s", receive_mem); 
					receive_num = compare(m,&seq,receive_mem);
					hand_over(m,spec_num,receive_num,&seq,&total_member);
					memo_print_member(m,&seq);
					save_data(m,seq);				
					break;
				}
			case DELETE_MEMBER:
				{
					printf("4번: 회원삭제\n\n");
					printf("대상자:"); 
					scanf("%s", spec_mem);
					spec_num = compare(m,&seq,spec_mem);
					delete_member(m,&total_member,spec_num,&seq);
					memo_print_member(m,&seq);
					save_data(m,seq);				
					break;
				}
			case SEARCH_MEMBER:
				{
					printf("5번:특정 회원 정보 조회\n\n");
					printf("대상자:"); 
					scanf("%s", spec_mem);
					spec_num = compare(m,&seq,spec_mem); 
					if(spec_num < 0)
					{
						break;
					}
					else
					{
						print_specific_member(m,spec_num);
						break;
					}	
				}
			case SEARCH_ALL_MEMBER:
				{
					printf("6번:전체 정보 조회\n\n");
					print_all_member(m,&seq);
					break;
				}
			case RENEW_ALL_MEMBER:
				{
					printf("7번: 전체 회원 남은 기간 갱신\n\n");
					update_period(m,&seq);				
					memo_print_member(m,&seq);
					save_data(m,seq);
					break;
				}
			case END:
				{
					exit = 1;
					memo_print_member(m,&seq);
					save_data(m,seq);
					break;
				}
		}
	}
	
	free(m);
	return 0;
}
struct tm* get_time() //현재 시각
{
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);
    return t;
}
int compare(MEMBER *m, int *seq, char *spec_mem)
{
	int i = 0;
	for( i = 0; i < *seq; i++)
	{
		if(strcmp(m[i].name,spec_mem) == 0)
		{
			return i;
		}
	}
	printf("잘못 입력하셨습니다.\n"); 
	return -1;
}
void register_member(MEMBER *m, int *seq) {
    int i = 0;
   	time_t cha = 0;
    struct tm *now_time = get_time();

    printf("이름:");
    scanf("%s", m[*seq].name);
    for (i = 0; i < *seq; i++) {
        if (strcmp(m[*seq].name, m[i].name) == 0) {
            printf("같은 이름이 있습니다\n");
            scanf("%s", m[*seq].name);
            i = -1; // 중복 검사를 다시 하기 위해 i를 -1로 설정
			  }
    }
    printf("나이:");
    scanf("%d", &m[*seq].age);
    printf("설정한 기간(달):");
    scanf("%d", &m[*seq].period);
    while (m[*seq].period <= 0) {
        printf("잘못 입력하셨습니다\n");
        scanf("%d", &m[*seq].period);
    }
    
	m[*seq].reg_t = *now_time;
    m[*seq].end_t = m[*seq].reg_t;
    m[*seq].end_t.tm_mon += m[*seq].period;
    if (m[*seq].end_t.tm_mon > 12) 
	{
        m[*seq].end_t.tm_year += (m[*seq].end_t.tm_mon / 12);
        m[*seq].end_t.tm_mon = (m[*seq].end_t.tm_mon % 12);
    }
	cha = difftime(mktime(&m[*seq].end_t), mktime(&m[*seq].reg_t));
	
	m[*seq].diff_t.tm_sec = cha ; // 초 
	
    m[*seq].diff_t.tm_mday = m[*seq].diff_t.tm_sec / (60 * 60 * 24); // 일
    m[*seq].diff_t.tm_sec -= (m[*seq].diff_t.tm_mday * 60 * 60 * 24);
    
    m[*seq].diff_t.tm_hour = m[*seq].diff_t.tm_sec / (60 * 60 ); // 시 
    m[*seq].diff_t.tm_sec -= (m[*seq].diff_t.tm_hour * 60 * 60 );
    
    m[*seq].diff_t.tm_min = m[*seq].diff_t.tm_sec / (60); // 분 
    m[*seq].diff_t.tm_sec -= (m[*seq].diff_t.tm_min * 60);
    
	(*seq)++;
}
void expansion_period(MEMBER *m, int *seq, int expansion, int spec_num) //기존 회원 기간 연장 
{
	time_t cha = 0;
	m[spec_num].period += expansion;
	m[spec_num].end_t.tm_mon += expansion; 
	if( m[spec_num].end_t.tm_mon > 12)
	{
		m[spec_num].end_t.tm_year += (m[spec_num].end_t.tm_mon/ 12);
		m[spec_num].end_t.tm_mon = (m[spec_num].end_t.tm_mon % 12);
	}
	cha = difftime(mktime(&m[spec_num].end_t), mktime(&m[spec_num].reg_t));
	
	m[spec_num].diff_t.tm_sec = cha ; // 초 
	
    m[spec_num].diff_t.tm_mday = m[spec_num].diff_t.tm_sec / (60 * 60 * 24); // 일
    m[spec_num].diff_t.tm_sec -= (m[spec_num].diff_t.tm_mday * 60 * 60 * 24);
    
    m[spec_num].diff_t.tm_hour = m[spec_num].diff_t.tm_sec / (60 * 60 ); // 시 
    m[spec_num].diff_t.tm_sec -= (m[spec_num].diff_t.tm_hour * 60 * 60 );
    
    m[spec_num].diff_t.tm_min = m[spec_num].diff_t.tm_sec / (60); // 분 
    m[spec_num].diff_t.tm_sec -= (m[spec_num].diff_t.tm_min * 60);
    
}
void delete_member(MEMBER *m, int *total_member, int spec_num,int *seq)//회원 삭제 
{
	int i = 0;
	for ( i = spec_num; i < *total_member; i++)
	{
		m[i] = m[i+1];
	}
	(*total_member)--; 
	(*seq)--; 
}
void hand_over(MEMBER *m, int spec_num, int receive_num, int *seq, int *total_member) // 회원권 양도 
{
	int period = 0; 
	period = m[spec_num].period;
	expansion_period(m,seq,period,receive_num);
	delete_member(m,total_member,spec_num,seq);                      
}
int print_specific_member(MEMBER *m, int spec_num)//특정 회원정보 조회 
{
	FILE *fp = fopen("Member_list.txt", "r"); 
	if (fp == NULL) 
	{
		printf("출력 오류! \n");
		return -1;
	}
		printf("회원번호 %d번:\n", spec_num + 1);
	    printf("이름: %s\n", m[spec_num].name);
	    printf("나이: %d\n", m[spec_num].age);
	    printf("기간(달): %d\n", m[spec_num].period);
	    printf("등록날: %d-%02d-%02d %02d:%02d:%02d\n", m[spec_num].reg_t.tm_year+1900, m[spec_num].reg_t.tm_mon+1, m[spec_num].reg_t.tm_mday, m[spec_num].reg_t.tm_hour, m[spec_num].reg_t.tm_min, m[spec_num].reg_t.tm_sec);
	    printf("끝나는 날: %d-%02d-%02d %02d:%02d:%02d\n", m[spec_num].end_t.tm_year+1900, m[spec_num].end_t.tm_mon+1, m[spec_num].end_t.tm_mday, m[spec_num].end_t.tm_hour, m[spec_num].end_t.tm_min, m[spec_num].end_t.tm_sec);
	    printf("%d일 %d시간 %d분 남았습니다\n",m[spec_num].diff_t.tm_mday, m[spec_num].diff_t.tm_hour, m[spec_num].diff_t.tm_min);
	    printf("\n");
    
    fclose(fp);
   return 0; 
}
int print_all_member(MEMBER *m, int *seq) //전체 정보 조회 
{
	FILE *fp = fopen("Member_list.txt", "r"); 
	int i;
	if (fp == NULL) 
	{
		printf("출력 오류! \n");
		return -1;
	}
	for ( i = 0; i < *seq; i++) 
	{
	    printf("회원번호 %d번:\n", i + 1);
	    printf("이름: %s\n", m[i].name);
	    printf("나이: %d\n", m[i].age);
	    printf("기간(달): %d\n", m[i].period);
		printf("등록날: %d-%02d-%02d %02d:%02d:%02d\n", m[i].reg_t.tm_year+1900, m[i].reg_t.tm_mon+1, m[i].reg_t.tm_mday, m[i].reg_t.tm_hour, m[i].reg_t.tm_min, m[i].reg_t.tm_sec);
   		printf("끝나는 날: %d-%02d-%02d %02d:%02d:%02d\n", m[i].end_t.tm_year+1900, m[i].end_t.tm_mon+1, m[i].end_t.tm_mday, m[i].end_t.tm_hour, m[i].end_t.tm_min, m[i].end_t.tm_sec);
    	printf("%d일 %d시간 %d분 남았습니다\n", m[i].diff_t.tm_mday, m[i].diff_t.tm_hour, m[i].diff_t.tm_min);
	    printf("\n");
    }
    
	fclose(fp); 
	
	return 0;
}

void update_period(MEMBER *m, int *seq) //전체회원 남은 기간 갱신 
{
	
   	time_t cha = 0;
    struct tm *now_time = get_time();
	int i;
	
	for (i = 0; i < *seq; i++)
	{
		cha = difftime(mktime(&m[i].end_t), mktime(now_time));
		
		m[i].diff_t.tm_sec = cha ; // 초 
		m[i].diff_t.tm_mday = m[i].diff_t.tm_sec / (60 * 60 * 24); // 일
		m[i].diff_t.tm_sec -= (m[i].diff_t.tm_mday * 60 * 60 * 24);
		
		m[i].diff_t.tm_hour = m[i].diff_t.tm_sec / (60 * 60 ); // 시 
	    m[i].diff_t.tm_sec -= (m[i].diff_t.tm_hour * 60 * 60 );
	    
	    m[i].diff_t.tm_min = m[i].diff_t.tm_sec / (60); // 분 
	    m[i].diff_t.tm_sec -= (m[i].diff_t.tm_min * 60);
	}
}


void load_data(MEMBER* m, int* seq) {
    FILE* fp = fopen("Member_list.txt", "rb");

    if (fp == NULL) 
	{
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    while (fread(&m[*seq], sizeof(MEMBER), 1, fp) == 1) 
	{
        (*seq)++;
	}
    fclose(fp);
}


void save_data(MEMBER* m, int seq)  
{
    FILE* fp = fopen("Member_list.txt", "r+");
    int i;
    if (fp == NULL) 
	{
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    for (i = 0; i < seq; i++) 
	{
        fwrite(&m[i], sizeof(MEMBER), 1, fp);
    }

    fclose(fp);
}

int memo_print_member(MEMBER *m, int *seq) 
{
    FILE *fp = fopen("Member_list_kor.txt", "w");

    if (fp == NULL) {
        printf("출력 오류!\n");
        return -1;
    }
    int i;
	
	for (i = 0; i < *seq; i++) 
	{
        fprintf(fp, "회원번호 %d번:\n", i + 1);
        fprintf(fp, "이름: %s\n", m[i].name);
        fprintf(fp, "나이: %d\n", m[i].age);
        fprintf(fp, "기간(달): %d\n", m[i].period);
        fprintf(fp, "등록날: %d-%02d-%02d %02d:%02d:%02d\n", m[i].reg_t.tm_year + 1900, m[i].reg_t.tm_mon + 1, m[i].reg_t.tm_mday, m[i].reg_t.tm_hour, m[i].reg_t.tm_min, m[i].reg_t.tm_sec);
        fprintf(fp, "끝나는 날: %d-%02d-%02d %02d:%02d:%02d\n", m[i].end_t.tm_year + 1900, m[i].end_t.tm_mon + 1, m[i].end_t.tm_mday, m[i].end_t.tm_hour, m[i].end_t.tm_min, m[i].end_t.tm_sec);
        fprintf(fp, "%d일 %d시간 %d분 남았습니다\n", m[i].diff_t.tm_mday, m[i].diff_t.tm_hour, m[i].diff_t.tm_min);
        fprintf(fp, "\n");
    }
	fclose(fp); 
	
	return 0;
}
