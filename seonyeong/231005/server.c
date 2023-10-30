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
#define NAME_SIZE 40
#define BODY_SIZE 1000

#define HEAD_ERR   3
#define BODY_ERR   2
#define CORRECT    1
#define HEAD_ERR_CODE	256
#define NOMSG_ERR_CODE   258
#define NO_RCV_MSG_ERR_CODE   257

enum FUNC{ SEND_MSG= 1, REQUEST_LAST_MSG, REQUEST_ALL_MSG, 
		DELETE_LAST_MSG, DELETE_ALL_MSG, EXIT };

void *handle_clnt(void * arg);
void send_msg(char * msg, int len);
void error_handling(char * msg);
void* msg_char(char *msg);
int msg_cut(char *msg);
char * msg_buffer(unsigned char* head, char* name, int func_code, int error_code, char* body);
void error_log(int *name, int func_code, int error_code);

int count = 0, i = 0;
int error_code = 0;
int line = 0;
int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
char buffer[BUF_SIZE + NAME_SIZE] = {0};
char msg[BUF_SIZE + NAME_SIZE] = {0};
char temp[BUF_SIZE] = {0};
char return_msg[BUF_SIZE + NAME_SIZE] = {0};
FILE *fm, *fl, *fp;
pthread_mutex_t mutx;

struct messages
{
	unsigned char head[4];
	char name[NAME_SIZE];
	unsigned int func_code;
	int body_len;
	char body[BODY_SIZE];
};

unsigned char head[] = {0x00,0x0B,0x6F,0xFF};

int main(int argc, char* argv[])
{
	int server = 0;
	struct sockaddr_in serv_addr, clnt_addr;
	int client = 0;
	int clnt_addr_size;
	pthread_t pthread;

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
	struct messages m;
	int clnt_sock=*((int*)arg);
	int str_len=0 ;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int name[NAME_SIZE*2];
	char num[NAME_SIZE*2];
	
	while((str_len=read(clnt_sock, msg, sizeof(msg)))!=0)
	{  
		memset(m.name,'\0',sizeof(m.name));
		memset (num, 0, sizeof(num)); 
		memset(temp, 0, sizeof(temp));
		strncpy(temp, msg + 8 ,NAME_SIZE);
		sprintf(m.name , "%s", temp);
		m.name[39] = '\0';
		//printf("#0m.name: %s\n",m.name);
		for(i = 0; i < NAME_SIZE/2 ; i++)
		{
			strncpy(num , temp + i*2, 2);  
			name[i] = strtol(num, 0, 16);
		}
		printf("name: %ls\n", name);

		memset(temp, 0, sizeof(temp));
		strncpy(temp, msg+65, 8);
		m.body_len = atoi(temp);

		strncpy(temp, msg+72, m.body_len * 2);
		sprintf(m.body, "%s", temp);		

		//printf("#2m.name: %s\n",m.name);
		memset(temp, 0, sizeof(temp));
		strncpy(temp, msg+48, 8);
		m.func_code = strtol(temp, 0, 16);
		if( m.func_code == EXIT )
		{
			printf("exit\n");
			close(clnt_sock);
			exit(0);
		}
		else if(m.func_code == SEND_MSG) 
		{
			printf("func_num: 1\n");
			
			int msg_return = msg_cut(msg);
			if(msg_return == HEAD_ERR)
			{
				printf("head incorrect\n");
				error_code = HEAD_ERR_CODE ; 
				
				error_log(name, m.func_code, error_code);
				
				msg_buffer(head, m.name, m.func_code, error_code, m.body);
				write(clnt_sock, buffer, strlen(buffer));
			}

			else if(msg_return == BODY_ERR)
			{	
				printf("no message\n");
				error_code = NO_RCV_MSG_ERR_CODE;

				error_log(name, m.func_code, error_code);
				
				msg_buffer(head, m.name, m.func_code, error_code, m.body);
				write(clnt_sock, buffer, strlen(buffer));
			}

			else if(msg_return == CORRECT)
			{
				msg_char(msg);
				error_code = CORRECT;

				printf("message save\n" );
				error_log(name, m.func_code, error_code);
				
				msg_buffer(head, m.name, m.func_code, error_code, m.body);
				write(clnt_sock, buffer, strlen(buffer));
			}
			else
			{
				printf("error\n");
			}

		}
		else if(m.func_code == REQUEST_LAST_MSG )
		{
			printf("func_num : 2\n");
			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
				exit(0);
			}
			char *ptr= fgets(buffer, BUF_SIZE, fm);
			if(ptr == NULL)
			{
				printf("no message\n");
				error_code = NOMSG_ERR_CODE;
				error_log(name, m.func_code, error_code);
				msg_buffer(head, m.name, m.func_code, error_code, m.body);
				write(clnt_sock, buffer, strlen(buffer));
			}
			else
			{
				error_code = 1;
				rewind(fm);
				while(1)
				{
					if(fgets(buffer, BUF_SIZE, fm) == NULL)
						break;			
				}
				write(clnt_sock, buffer, strlen(buffer));
				printf("last message: %s", buffer);

				printf("transfer last message\n");
				error_log(name, m.func_code, error_code);
				sprintf(return_msg,"func_code: %d error_code: %08X\n", m.func_code, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));

			}
			fclose(fm);
		}

		else if(m.func_code == REQUEST_ALL_MSG)
		{
			printf("func_num : 3\n");

			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
				exit(0);
			}
			char *ptr= fgets(buffer, BUF_SIZE, fm);
			if(ptr == NULL)
			{
				printf("no message\n");
				error_code = NOMSG_ERR_CODE;
				error_log(name, m.func_code, error_code);
				msg_buffer(head, m.name, m.func_code, error_code, m.body);
				write(clnt_sock, buffer, strlen(buffer));
			}
			else
			{
				rewind(fm);
				while( fgets(buffer, BUF_SIZE, fm)!= NULL)
				{
					write(clnt_sock, buffer, strlen(buffer));
				}
				error_code = CORRECT;
				error_log(name, m.func_code, error_code);

				sprintf(return_msg,"func_code: %d error_code : %08X\n", m.func_code, error_code);
				write(clnt_sock, return_msg, strlen(return_msg));

				printf("transfer all messages\n");
			}

			fclose(fm);
		}

		else if(m.func_code == DELETE_LAST_MSG)
		{

			printf("func_num : 4\n");

			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
				exit(0);
			}
			if((fp = fopen("temp.txt", "w")) == NULL)
			{
				printf("fail3\n");
				exit(0);
			}

			char *ptr= fgets(buffer,BUF_SIZE, fm);
			if(ptr == NULL)
			{
				printf("no message\n");
				error_code = NOMSG_ERR_CODE;
				error_log(name, m.func_code, error_code);
				msg_buffer(head, m.name, m.func_code, error_code, m.body);
				write(clnt_sock, buffer, strlen(buffer));
			}
			else
			{
				rewind(fm);
				line = 0;
				count = 0;

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

				error_code = CORRECT;
				error_log(name, m.func_code, error_code);
				msg_buffer(head, m.name, m.func_code, error_code, m.body);
				write(clnt_sock, buffer, strlen(buffer));
			}
		}
		else if(m.func_code == DELETE_ALL_MSG)
		{
			printf("func_num : 5\n");

			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
				exit(0);
			}

			remove("message.txt");

			fm = fopen("message.txt", "w");
			fclose(fm);

			error_code = CORRECT;
			error_log(name, m.func_code, error_code);
			printf("completely deleting all messages\n");
			msg_buffer(head, m.name, m.func_code, error_code, m.body);
			write(clnt_sock, buffer, strlen(buffer));
		}

		else  
		{
			printf("func_code error %d\n", m.func_code);
			sprintf(return_msg, "func_code error\n");
			write(clnt_sock, return_msg, strlen(return_msg));
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
	struct messages m;
	strncpy(m.head, msg, 8);
	if(strstr(m.head, "000B6FFF") == NULL)
	{
		count = HEAD_ERR;
	}
	else
	{
		strncpy(temp, msg+65, 8);
		m.body_len = atoi(temp);
		strncpy(temp, msg+72, m.body_len*2);
		sprintf(m.body, "%s", temp);
		if(strlen(m.body) == 0)
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

void* msg_char(char *msg)
{
	struct messages m;
	int message[BUF_SIZE] = {0};
	char num[NAME_SIZE] = {0};
	int name[NAME_SIZE] = {0};
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	memset(temp, 0, sizeof(temp));
	memset(m.body, 0, sizeof(m.body));
	memset(message, 0, sizeof(message));

	strncpy(temp, msg+8 ,NAME_SIZE);
	sprintf(m.name , "%s", temp);
	for(i = 0; i < NAME_SIZE/2 ; i++)
	{
		strncpy(num , temp + i*2, 2);  
		name[i] = strtol(num, 0, 16);
	}

	memset(temp, 0, sizeof(temp));
	strncpy(temp, msg+65, 8);
	m.body_len = atof(temp);
	memset(temp, 0, sizeof(temp));
	strncpy(temp, msg+72, m.body_len * 2);
	sprintf(m.body, "%s", temp);
	for(i = 0; i < m.body_len; i++)
	{
		strncpy(num , m.body + i*2, 2);  
		message[i] = strtol(num, 0, 16);
	}

	printf("message: %ls\n",message);

	if((fm = fopen("message.txt", "a")) == NULL)
	{
		printf("fail1\n");
		exit(0);
	}

	fprintf(fm, "[%ls] %ls %d-%d-%d %d:%d\n", name, message
			,tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
	fclose(fm);
}

char * msg_buffer(unsigned char* head, char* name, int func_code, int error_code, char* body)
{
	int body_len = strlen(body)/2;
	int head_num[10] = {0};
	int n = 0;

	memset(msg, 0, sizeof(msg));
	memset(buffer, 0, sizeof(buffer));

	for(i = 0; i < 4; i++)
	{   
		head_num[n] = head[i];
		n += 2;
	}   
	n = 0;
	sprintf(buffer,"%02X%02X%02X%02X%40s%08X%08X%08X%s\n", 
			head_num[0],head_num[2],head_num[4],head_num[6],
			name, func_code, error_code, body_len, body);
	//printf(">%s >b> %s\n", name, buffer);
	return buffer;
}


void error_log(int *name, int func_code, int error_code )
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if((fl = fopen("error_code_log.txt", "a")) == NULL)
	{
		printf("fail2\n");
		exit(0);
	}
	fprintf(fl, "[%ls] func_code: %d error: %08x time: %d-%d-%d %d:%d\n", 
			name, func_code, error_code,
			tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min );
	fclose(fl);
}
