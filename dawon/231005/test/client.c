#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>


#define MSG_SIZE 100
#define BODY_SIZE 10
//void *program(void* a);
void *send_msg(void * arg);
void *recv_msg(void * arg);
void error_handling(char *msg);

typedef struct arg
{
	int str_sock;
	char str_msg[MSG_SIZE];
}A;

int main(int argc, char *argv[])
{
	char msg[MSG_SIZE] = {'\0', };
	char name[40] = {'\0', };
	char head[30] = {'\0', };
	struct sockaddr_in serv_addr;
	int sock;
	pthread_t snd_thread, rcv_thread;
	void *thread_return;
	int i = 0, j = 0, index = 20;
	char num[1];
	char body;
	char body_len[10] = {'\0', };
	char body_char[BODY_SIZE * 2] = {'\0', };
	A a;


	
	a.str_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(a.str_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
	printf("name: %s\n",argv[3]);
	sprintf(name,"%x",argv[3][0]);
	printf("name: ");
	fputs(name,stdout);
	printf("\n");

	strcpy(head,"000B6FFF");
	for(i = 0; i < 40; i++)
	{
		if(name[i] == '\0')
		{
			name[i] = '0';
		}
	}
	strcat(msg,head);
	strcat(msg,name);
	printf("func code: ");
	scanf("%s",num);
	getchar();
	strcat(msg,num);

	strcat(msg,"0001");

	printf("body msg: ");
	scanf("%c",&body);

	printf("body_char: ");
	sprintf(body_char,"%x",body);
	fputs(body_char,stdout);
	printf("\n");

	sprintf(body_len,"%d",strlen(body_char));	
	printf("body_len: ");
	fputs(body_len,stdout);
	printf("\n");
	strcat(msg,body_len);
	strcat(msg,body_char);
	strcpy(a.str_msg,msg);

	printf("%s\n",msg);

	pthread_create(&snd_thread, NULL, send_msg, (void*)&a);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&a);
	pthread_join(snd_thread, &thread_return);
	pthread_join(snd_thread, &thread_return);
	close(a.str_sock);

	return 0;

}
void * send_msg(void *arg)
{
	A *a = (A*)arg;
	int sock = a -> str_sock;
	char msg[MSG_SIZE];
	while(1)
	{
		fgets(msg, MSG_SIZE, stdin);
		if(!strcmp(msg,"q\n") || !strcmp(msg, "Q\n"))
		{
			close(sock);
			exit(0);
		}
		sprintf(msg, "%s", a -> str_msg);
		write(sock, msg, strlen(msg));
	}
	return NULL;
}
void * recv_msg(void * arg)
{
	A *a = (A*)arg;
	int sock = a -> str_sock;
	char msg[MSG_SIZE];
	int str_len;
	while(1)
	{
		str_len = read(sock, msg, MSG_SIZE - 1);
		if(str_len ==-1)
			return (void*)-1;
		msg[str_len] = 0;
		fputs(msg, stdout);
	}
	return NULL;
}

void error_handling(char *msg)
{
	fputs(msg,stderr);
	fputc('\n',stderr);
	exit(1);
}
