#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <time.h>

#define MAX_CLNT 256
#define BUF_SIZE 1000
#define NAME_SIZE 20
#define BODY_SIZE 1000

#define HEAD_ERR   3
#define BODY_ERR   2
#define CORRECT    1

void *handle_clnt(void * arg);
void send_msg(char * msg, int len);
void error_handling(char * msg);
void msg_char(char *msg);
int msg_cut(char *msg);

int count = 0;
int error_code = 0;
int line = 0;
int clnt_cnt = 0;

int clnt_socks[MAX_CLNT];
char buffer[BUF_SIZE + NAME_SIZE] = {0};
char msg[BUF_SIZE + NAME_SIZE] = {0};
char return_msg[BUF_SIZE + NAME_SIZE] = {0};
FILE *fm, *fl, *fp;
pthread_mutex_t mutx;

struct messages
{
	unsigned char head[4];
	char name[NAME_SIZE] ;
	int func_code ;
	int body_len ;
	char body[BODY_SIZE];
};

int main(int argc, char* argv[])
{
	int server = 0;
	struct sockaddr_in serv_addr, clnt_addr;
	int client = 0;
	int clnt_addr_size;
	pthread_t pthread;

	unsigned char head[] = {0x00,0x0B,0x6F,0xFF};

	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		return 0;
	}

	pthread_mutex_init(&mutx, NULL);
	server = socket(PF_INET, SOCK_STREAM, 0 );
	memset(&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family=AF_INET; 
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(atoi(argv[1]));

	if(bind(server, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
	{
		printf("bind error\n");
		return -1;
	}
	if(listen(server, 5)==-1)
	{
		printf("listen error\n");
		return -1;
	}

	while(1)
	{
		clnt_addr_size = sizeof(clnt_addr);
		client = accept(server, (struct sockaddr*)&clnt_addr,&clnt_addr_size);

		pthread_mutex_lock(&mutx);
		clnt_socks[clnt_cnt++]=client;
		pthread_mutex_unlock(&mutx);

		pthread_create(&pthread, NULL, handle_clnt, (void*)&client);
		pthread_detach(pthread);
		printf("Connected client IP: %s \n", inet_ntoa(clnt_addr.sin_addr));

	}
	close(server);
	return 0;
}

void * handle_clnt(void * arg)
{
	struct messages m[50];
	int clnt_sock=*((int*)arg);
	int str_len=0, i = 0, idx = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	while((str_len=read(clnt_sock, msg, sizeof(msg)))!=0)
	{   
		idx++;

		if(msg[53] == 54)//6
		{
			printf("%d", msg[53]);
			printf("exit\n");
			close(clnt_sock);
			exit(0);
		}

		else if(msg[53] == 49)
		{
			printf("func_num: 1\n");

			if((fl = fopen("error_code_log.txt", "a")) == NULL)
			{
				printf("fail2\n");
			}

			int msg_return = msg_cut(msg);
			if(msg_return == HEAD_ERR)
			{
				printf("head incorrect\n");
				error_code = 256;

				fprintf(fl, " %s %04x %d-%d-%d %d:%d\n", msg, error_code,
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min );
				
				sprintf( return_msg, "func_num: %d  error_code: %04x  <func_code> <body>", msg[53] - 48, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));
			}

			else if(msg_return == BODY_ERR)
			{	
				printf("no message\n");
			}

			else if(msg_return == CORRECT)
			{
				error_code = 1;

				msg_char(msg);

				fprintf(fl, "%s %04x %d-%d-%d %d:%d\n", msg,error_code,
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min );
				printf("message save\n" );
				sprintf(return_msg, "func_num: %d  error_code: %04x  <func_code> <body>", msg[53] - 48, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));

			}
			else
			{
				printf("error\n");
			}

			fclose(fl);
		}
		else if(msg[53] == 50)
		{
			printf(" func_num : 2\n");
			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
			}
			if((fl = fopen("error_code_log.txt", "a")) == NULL)
			{
				printf("fail2\n");
			}
			char *ptr= fgets(buffer, BUF_SIZE, fm);
			if(ptr == NULL)
			{
				printf("no message\n");
				error_code = 258;
				fprintf(fl, "%s %04x %d-%d-%d %d:%d\n",msg, error_code,
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min );
				sprintf(return_msg, "func_num: %d  error_code: %04x <func_code> <body> ", msg[53] - 48, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));
			}
			else
			{
				rewind(fm);
				while(1)
				{
					if(fgets(buffer, BUF_SIZE, fm) == NULL)
						break;			
				}
				printf("last message: %s", buffer);
				printf("transfer last message\n");
				
				sprintf(return_msg, "func_num: %d <func_code> <body> ", msg[53] - 48);
				write(clnt_sock, buffer, strlen(buffer));
				write(clnt_sock, return_msg, strlen(return_msg));
			}
			fclose(fl);
			fclose(fm);
		}

		else if(msg[53] == 51)
		{
			printf("func_num : 3\n");

			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
			}
			if((fl = fopen("error_code_log.txt", "a")) == NULL)
			{
				printf("fail2\n");
			}
			char *ptr= fgets(buffer, BUF_SIZE, fm);
			if(ptr == NULL)
			{
				printf("no message\n");
				error_code = 258;
				fprintf(fl, "%s %04x %d-%d-%d %d:%d\n",msg, error_code,
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min );
				sprintf(return_msg, "func_num: %d  error_code: %04x <func_code> <body> ", msg[53] - 48, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));
			}
			else
			{
				rewind(fm);
				while( fgets(buffer, BUF_SIZE, fm)!= NULL)
				{
					write(clnt_sock, buffer, strlen(buffer));
				}
				error_code = 1;
				sprintf(return_msg, "func_num: %d  error_code: %04x <func_code> <body> ", msg[53] - 48, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));
				printf("transfer all messages\n");
			}

			fclose(fm);
			fclose(fl);
		}

		else if(msg[53] == 52)
		{

			printf("func_num : 4\n");

			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
			}
			if((fp = fopen("temp.txt", "w")) == NULL)
			{
				printf("fail3\n");
			}
			
			char *ptr= fgets(buffer,BUF_SIZE, fm);
			if(ptr == NULL)
			{
				printf("no message\n");
				error_code = 258;
				fprintf(fl, "%s %04x %d-%d-%d %d:%d\n", msg, error_code,
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min );
				sprintf(return_msg, "func_num: %d  error_code: %04x <func_code> <body> ", msg[53] - 48, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));
			}
			else
			{
				rewind(fm);

				while(fgets(buffer, BUF_SIZE, fm) != NULL)
				{
					line++;
				}
				rewind(fm);

				while(1)
				{
					if(fgets(buffer, BUF_SIZE, fm) == NULL)
					{
						break;
					}

					count++;

					if(count != line)
					{
						fputs(buffer, fp);
					}
					else if(count == line)
					{
						break;
					}
				}
			
				fclose(fp);
				fclose(fm);
				remove("message.txt");
				rename("temp.txt","message.txt");
				printf("delete last message\n");
			
				error_code = 1;
				sprintf(return_msg, "func_num: %d  error_code: %04x <func_code> <body>", msg[53] - 48, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));
			}
		}
		else if(msg[53] == 53)
		{
			printf("func_num : 5\n");

			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
			}

			remove("message.txt");

			fm = fopen("message.txt", "w");
			fclose(fm);

			error_code = 1;
			printf("completely deleting all messages\n");
			sprintf(return_msg, "func_num: %d  error_code: %04x <func_code> <body>", msg[53] - 48, error_code);
			write(clnt_sock, return_msg, strlen(return_msg));
		}
		else 
		{
			sprintf(return_msg, "func_num: %d func_code error", msg[53] - 48);
			write(clnt_sock, return_msg, strlen(return_msg));
			printf("func_code error\n");
			char msg[BUF_SIZE + NAME_SIZE] = {0};
		}
	}

	pthread_mutex_lock(&mutx);
	for(i=0; i<clnt_cnt; i++) 
	{
		if(clnt_sock==clnt_socks[i])
		{
			while(i++<clnt_cnt-1)
				clnt_socks[i]=clnt_socks[i+1];
			break;
		}
	}
	clnt_cnt--;
	pthread_mutex_unlock(&mutx);
	close(clnt_sock);
	return NULL;
}

int msg_cut(char *msg)
{
	struct messages m[50];
	int idx = 0;
	char temp[500] = {0};	

	strncpy(m[idx].head, msg, 8);
	if(strstr(m[idx].head, "000B6FFF") == NULL)
	{
		count == HEAD_ERR;
	}
	else
	{
		strncpy(temp, msg+62, 2);
		m[idx].body_len = atof(temp);
		strncpy(temp, msg+65, m[idx].body_len);
		sprintf(m[idx].body, "%s", temp);

		if(strstr(m[idx].body, "32") != 0)
		{
			count = BODY_ERR;
		}
		else
		{
			count = CORRECT;
		}
	}
	return count;
}

void msg_char(char *msg)
{
	struct messages m[50];
	int idx = 0;
	char temp[BUF_SIZE] = {0};
	int message[BUF_SIZE] = {0};
	char num[NAME_SIZE] = {0};
	int i = 0;

	strncpy(temp, msg+62, 2);
	m[idx].body_len = atof(temp);
	strncpy(temp, msg+65, m[idx].body_len * 2);
	sprintf(m[idx].body, "%s", temp);

	for(i = 0; i < m[idx].body_len; i++)
	{
		strncpy(num , m[idx].body + i*2, 2);  
		message[i] = strtol(num, 0, 16);
	}

	printf("message: %ls\n",message);

	if((fm = fopen("message.txt", "a")) == NULL)
	{
		printf("fail1\n");
	}

	fprintf(fm, "%ls\n", message);

	fclose(fm);
}
