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

void *send_msg(void * arg);
void *recv_msg(void * arg);
char * msg_buffer(unsigned char *head, char *name, int func_code, int error_code, char* body );

char buffer[BUF_SIZE + NAME_SIZE] = {0};
char msg[BUF_SIZE + NAME_SIZE] = {0};

unsigned char head[] = {0x00,0x0B,0x6F,0xFF};
char name[NAME_SIZE] = {0} ;
int func_code ;
int error_code = 0;
int body_len ;
char body[1000];

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
	char name_num[50] = {0};
	char body_num[2000] = {0};
	int n = 0;

	for(i = 0; i < 4; i++)
	{
		sprintf(&head_num[n], "%02X", head[i]);
		n = n + 2;
	}

	n = 0;

	for(i = 0; i < 20; i++)
	{
		sprintf(&name_num[n], "%02X", name[i]);
		n = n + 2;
	}

	n = 0;

	for(i = 0; i < body_len ; i++)
	{
		sprintf(&body_num[n],"%02X", body[i]);
		n = n + 2;
	}

	sprintf(buffer,"%s %s %04X %04X %04X %s", 
			head_num, name_num, func_code, error_code, body_len, body_num);
	strcpy(msg, buffer);
	printf("%s\n", buffer);
	return msg;
}

void * send_msg(void * arg)
{
    int sock = *((int*)arg);
    while(1)
    {
		printf("\n<func_code> <body> ");
	//	scanf("%d", &func_code);
	//	for(int i = 0; i < 200; i++)
	//	{
	//		unsigned char p ;
	//		sprintf(&body[i],"%c", p++);
	//	}
		scanf("%d %s", &func_code, body);
        if( func_code == 6 )
        {
			msg_buffer(head, name, func_code, error_code, body);
			write(sock, msg, strlen(msg));
			printf("\nexit\n");
            close(sock);
            exit(0);
        }
			msg_buffer(head, name, func_code, error_code, body);
			write(sock, msg, strlen(msg));

    }   
    return NULL;
}

void * recv_msg(void * arg)
{
    int sock = *((int*)arg);
    int str_len;
    while(1)
    {
        str_len = read(sock, msg, NAME_SIZE+BUF_SIZE-1);
        if(str_len ==-1)
            return (void*)-1;
        msg[str_len] =0;
        fputs(msg, stdout);
		printf("%s", msg);
    }
    return NULL;
}

