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

void *send_msg(void * arg);
void *recv_msg(void * arg);
char * msg_buffer(unsigned char *head, char *name, int func_code, int error_code, char* body );

char buffer[BUF_SIZE + NAME_SIZE] = {0};
char msg[BUF_SIZE + NAME_SIZE] = {0};

unsigned char head[] = {0x00,0x0B,0x6F,0xFF};
char name[NAME_SIZE] = {0} ;
unsigned int func_code ;
int error_code = 0;
int body_len ;
char body[BODY_SIZE];
pthread_mutex_t mutx;

int main(int argc, char *argv[])
{
	int client;
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
	char head_num[10] = {0};
	char name_num[NAME_SIZE * 2] = {0};
	char body_num[BODY_SIZE * 2] = {0};
	int n = 0;
	memset(msg, 0, sizeof(msg));
	memset(buffer, 0, sizeof(buffer));

	for(i = 0; i < 4; i++)
	{
		sprintf(&head_num[n], "%02X", head[i]);
		n += 2;
	}

	n = 0;

	for(i = 0; i < 20; i++) //define
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

	sprintf(buffer,"%s%s%04X%04X%04X%s", 
			head_num, name_num, func_code, error_code, body_len, body_num);
	printf("%s\n", buffer);
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
		
		char temp[1000];

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

		if( func_code == 6 )
		{
			msg_buffer(head, name, func_code, error_code, body);
			write(sock, buffer, strlen(buffer));
			printf("\nexit\n");
			close(sock);
			exit(0);
		}
		else if( 0 < func_code && func_code < 6)
		{
			msg_buffer(head, name, func_code, error_code, body);
			write(sock, buffer, strlen(buffer));
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
    int str_len;
    while(1)
    {
        str_len = read(sock, buffer, NAME_SIZE+BUF_SIZE-1);
        if(str_len ==-1)
            return (void*)-1;
        buffer[str_len] =0;
		fputs(buffer, stdout);
    }
	return NULL;
}

