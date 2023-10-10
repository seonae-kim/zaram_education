#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 100
#define MAX_CLNT 256
#define BODY_SIZE 1000

void *handle_clnt(void *arg);
void send_msg(char * msg, int len);
void error_handling(char * msg);

int clnt_cnt=0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;


int main(int argc, char *argv[])
{
	char msg[MSG_SIZE] = {'\0', };
	char name[40] = {'\0', };
	char head[30] = {'\0', };
	char num[1];
	char body;
	char body_len[10] = {'\0', };
	char body_char[BODY_SIZE * 2] = {'\0', };
	int serv_sock, clint_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	pthread_t t_id;

	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
  
	pthread_mutex_init(&mutx, NULL);
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET; 
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));
	
	if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");

	while(1)
	{
		
		clnt_adr_sz=sizeof(clnt_adr);
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr,&clnt_adr_sz);
		
		pthread_mutex_lock(&mutx);
		clnt_socks[clnt_cnt++]=clnt_sock;
		pthread_mutex_unlock(&mutx);
	
		pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock);
		pthread_detach(t_id);
		printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
	}
	close(serv_sock);
	return 0;
}

void * handle_clnt(void * arg)
{
	int clnt_sock=*((int*)arg);
	int str_len=0, i = 0, mode = 0, body_strlen = 0, line = 0, index = 0;
	char ecode[8] = {'\0', };

	char msg[BUF_SIZE], m;
	char smsg[BUF_SIZE] = {'\0', };
	char body_msg[BODY_SIZE] = {'\0', };
	char body_char[BODY_SIZE] = {'\0', };
	char body_len[2] = {'\0', };

	FILE *f_msg;
	FILE *f_log;
	FILE *f_out;
	time_t t = time(NULL);
	struct tm tm = *(localtime(&t));
	char *file;
	
	while((str_len=read(clnt_sock, msg, sizeof(msg)))!=0)
	{
		
//		send_msg(msg, str_len);
		
		m = msg[55];
		mode = atoi(m);
		for(i = 64; i < 72; i++)
		{
			body_len[index++] = msg[i];
			index++;
		}
		index = 0;
		body_strlen = atoi(body_len);
		for(i = 72; i < 72 + body_strlen; i++)
		{
			body_msg[index++] = msg[i];
		}
		index = 0;

		if(mode == 1)
		{
			if(msg[72] == '\0')
			{
				f_log = fopen("log.txt","a");
				strcpy(ecode,"00000102");
				for(i = 56; i < 64; i++)
				{
					msg[i] = ecode[index++];
				}
				
				fprintf(f_log, "Error Code : 0x%s, No Saved message %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
				send_msg(msg,str_len);
				fclose(f_log);
				break;
			}


			f_msg = fopen("msg.txt","a");			
			fprintf(f_msg,"%s",body_msg);
			strcpy(ecode,"00000001");
/*			for(i = 56; i < 64; i++)
			{
				msg[i] = ecode[index++];
			}
*/
			fprintf(f_log, "Error Code : 0x%s, Success %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
			send_msg(msg,str_len);

			fclose(f_msg);
			fclose(f_log);

		}

		else if(mode == 2)
		{
			index = 0;
			f_log = fopen("log.txt","a");

			if(msg[72] == '\0')
			{
				strcpy(ecode,"00000101");
				for(i = 56; i < 64; i++)
				{
					msg[i] = ecode[index++];
				}

				printf("Error Code: 0x%s\n",ecode);
				printf("No sended message\n");
				
				fprintf(f_log, "Error Code : 0x%s, No Sended message %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

				fclose(f_log);
				break;
			}
			strcpy(ecode,"00000001");
			send_msg(msg,str_len);
			fprintf(f_log, "Error Code : 0x%s, Success %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
			fclose(f_log);

		}

		else if(mode == 3)
		{
			f_msg = fopen("msg.txt","r");
			f_log = fopen("log.txt","a");

			if(fgets(body_char,MSG_SIZE,f_msg) == NULL)
			{
				strcpy(ecode,"00000101");
				for(i = 56; i < 64; i++)
				{
					msg[i] = ecode[index++];
				}

				printf("Error Code: 0x%s\n",ecode);
				printf("No sended message\n");
				
				fprintf(f_log, "Error Code : 0x%s, No Sended message %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

				fclose(f_log);
				break;
			}
			else
				fseek(f_msg,0,SEEK_SET);

			while(f_msg != NULL)
			{
				fgets(body_char,MSG_SIZE,f_msg);
				send_msg(body_char,MSG_SIZE);
			}
			strcpy(ecode,"00000001");
			fprintf(f_log, "Error Code : 0x%s, Success %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

			fclose(f_log);
			fclose(f_msg);
		}

		else if(mode == 4)
		{
			f_msg = fopen("msg.txt","a");
			f_log = fopen("log.txt","a");
			
			if(fgets(body_char,MSG_SIZE,f_msg) == NULL)
			{
				strcpy(ecode,"00000102");
				for(i = 56; i < 64; i++)
				{
					msg[i] = ecode[index++];
				}

				printf("Error Code: 0x%s\n",ecode);
				printf("No saved message\n");
				f_log = fopen("log.txt","a");
				fprintf(f_log, "Error Code : 0x%s, No Saved message %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

				fclose(f_log);
				break;
			}
			else
				fseek(f_msg,0,SEEK_SET);


			while(f_msg != NULL)
			{
				fgets(body_char, MSG_SIZE,f_msg);
				line++;
			}
			

			f_out = fopen("output.txt","w");
			
			while(f_msg != NULL)
			{
				fgets(body_char, MSG_SIZE, f_msg);
				a++;
				if(a == line)
					break;
				fprintf(body_char,MSG_SIZE,f_out);
			}

			remove("msg.txt");
			rename("output.txt","msg.txt");
			strcpy(ecode,"00000001");
/*			for(i = 56; i < 64; i++)
			{
				msg[i] = ecode[index++];
			}
*/
			printf("Error Code: 0x%s\n",ecode);
			printf("No saved message\n");
				
			fprintf(f_log, "Error Code : 0x%s, Success %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

			fclose(f_log);
			fclose(f_out);
//			fclose(f_msg);
		}

		else if(mode == 5)
		{
			f_msg = fopen("msg.txt","w");
			fclose(f_msg);
			f_log = fopen("log.txt","a");
			strcpy(ecode,"00000001");
			fprintf(f_log, "Error Code : 0x%s, Success %d/ %d/ %d/ %d/ %d",ecode, tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
			fclose(f_log);
		}
	}

		pthread_mutex_lock(&mutx);
		for(i = 0; i < clnt_cnt; i++)
		{
			if(clnt_sock == clnt_socks[i])
			{
				while(i++ < clnt_cnt - 1)
					clnt_socks[i] = clnt_socks[i+1];
				break;
			}
		}
		clnt_cnt--;
		pthread_mutex_unlock(&mutx);
		close(clnt_sock);
		return NULL;
}
voie error_handling(char* msg)
{
	fputs(msg,stderr);
	fputc('\n',stderr);
	exit(1);
}
	

		

	

			

					
			



















	}
	
	pthread_mutex_lock(&mutx);
	for(i=0; i<clnt_cnt; i++)   // remove disconnected client
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
void send_msg(char * msg, int len)   // send to all
{
	int i;
	pthread_mutex_lock(&mutx);
	for(i=0; i<clnt_cnt; i++)
		write(clnt_socks[i], msg, len);
	pthread_mutex_unlock(&mutx);
}
void error_handling(char * msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
