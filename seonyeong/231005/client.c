#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 1000
#define NAME_SIZE 20
#define BODY_SIZE 1000

enum FUNC{ SAVE_MSG= 1, SEND_LAST_MSG, SEND_ALL_MSG,
		DELETE_LAST_MSG, DELETE_ALL_MSG, EXIT };

void *send_msg(void * arg);
void *recv_msg(void * arg);
char * msg_buffer(unsigned char *head, char *name, int func_code, int error_code, char* body );

char buffer[BUF_SIZE + NAME_SIZE] = {0};
char msg[BUF_SIZE + NAME_SIZE] = {0};
char temp[BUF_SIZE] = {0};

char name[NAME_SIZE];
unsigned int func_code;
int error_code = 0;
int body_len;
char body[BODY_SIZE];
unsigned char head[] = {0x00,0x0B,0x6F,0xFF};
pthread_mutex_t mutx;

int main(int argc, char *argv[])
{
	int client = 0;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void * thread_return;

	if(argc!=4) 
	{
		printf("Usage : %s <IP> <port> <name>\n", argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mutx, NULL);
	sprintf(name, "%s", argv[3]);
	client = socket(PF_INET, SOCK_STREAM, 0 );

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));

	printf("%s %s %s\n", argv[1], argv[2], argv[3]);
	if(connect(client, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		printf("connect error\n");
		exit(1);
	}

	pthread_create(&snd_thread, NULL, send_msg, (void*)&client);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&client);
	pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);

	close(client);
	return 0;
}


char * msg_buffer(unsigned char* head, char* name, int func_code, int error_code, char* body )
{
	int body_len = strlen(body);
	int i = 0;
	int head_num[10] = {0};
	char name_num[NAME_SIZE * 2] = {0};
	char body_num[BODY_SIZE * 2] = {0};
	int n = 0;
	memset(msg, 0, sizeof(msg));
	memset(buffer, 0, sizeof(buffer));

	for(i = 0; i < 4; i++)
	{
		head_num[n] = head[i];
		n += 2;
	}

	n = 0;

	for(i = 0; i < NAME_SIZE; i++) 
	{
		sprintf(&name_num[n], "%02X", name[i]);
		n += 2;
	}

	n = 0;

	for(i = 0; i < body_len ; i++)
	{
		sprintf(&body_num[n],"%02X", body[i]);
		n += 2;
	}

	sprintf(buffer,"%02X%02X%02X%02X%s%04X%04X%04X%s", 
			head_num[0],head_num[2],head_num[4],head_num[6],
			name_num, func_code, error_code, body_len, body_num);
	return buffer;
}

void * send_msg(void * arg)
{
	int sock = *((int*)arg);
	printf("\n<func_code> <body> ");
	while(1)
	{
		func_code = 0;
		memset(body, 0 , sizeof(body));

		memset(temp , 0 , sizeof(temp));

		fgets(temp, sizeof(temp), stdin);

		char *p = strtok( temp, " " );

		func_code = atoi(p);
		p = strtok( NULL, " ");

		if (p != NULL)
		{
			sprintf(body, "%s", p);
			body[strlen(body) - 1] = '\0';
		}

		if( SAVE_MSG <= func_code && func_code <= DELETE_ALL_MSG)
		{
			msg_buffer(head, name, func_code, error_code, body);
			write(sock, buffer, strlen(buffer));
		}
		else if(func_code == EXIT )
		{
			msg_buffer(head, name, func_code, error_code, body);
			write(sock, buffer, strlen(buffer));
			printf("\nexit\n");
			close(sock);
			exit(0);
		}
		else 
		{
			msg_buffer(head, name, func_code, error_code, body);
			write(sock, buffer, strlen(buffer));
		}
	}
	return NULL;
}

void * recv_msg(void * arg)
{
	int sock = *((int*)arg);
	int str_len = 0;
	char return_msg[BUF_SIZE];

	while(1)
	{
		str_len = read(sock, buffer, NAME_SIZE+BUF_SIZE-1);
		if(str_len ==-1)
			return (void*)-1;
		buffer[str_len] =0;

		if(buffer[0] == 48)
		{
			memset(temp, 0, sizeof(temp));
			strncpy(temp, buffer+49, 3);
			func_code = strtol(temp, 0, 16);

			memset(temp, 0, sizeof(temp));
			strncpy(temp, buffer+52, 4);
			error_code = strtol(temp, 0, 16);
			sprintf(return_msg,"func_code: %d error_code : %04X\n",func_code,error_code);
			fputs(return_msg, stdout);

		}
		else
		{
			fputs(buffer,stdout);
		}
	}
	return NULL;
}

