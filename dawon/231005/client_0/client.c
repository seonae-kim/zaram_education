#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/socket.h>

#define MSG_SIZE 100
#define BODY_SIZE 10
void *recv_msg(void * arg);
void *send_msg(void * arg);

typedef struct arg
{
	int str_sock;
	char str_msg[MSG_SIZE];
}A;

typedef struct program
{
	char head[8];
	char name[40];
	char fcode[8];
	char ecode[8];
	char blen[8];
	char bmsg[1000];
}P;

int main(int argc, char *argv[])
{
	char msg[MSG_SIZE] = {'\0', };
	char name[40] = {'\0', };
	char name_s[2] = {'\0', };
	char head[30] = {'\0', };
	struct sockaddr_in serv_addr;
	int sock;
	pthread_t snd_thread, rcv_thread;
	void *thread_return;
	int i = 0, j = 0, index = 0, len_b = 0;
	char num_i;
	char num[8] = {'\0', };
	char body[BODY_SIZE] = {'\0', };
	char body_len[10] = {'\0', };
	char body_char[BODY_SIZE * 2] = {'\0', };
	char body_str[BODY_SIZE * 2][3] = {'\0', };
	char length[BODY_SIZE] = {'\0', };
	A a;
	P p;
	
	a.str_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(a.str_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		printf("connect() error\n");
	sprintf(name_s,"%x",argv[3][0]);
	printf("name: ");
	printf("%x",name_s[0]);
	printf("\n");

	strcpy(head,"000B6FFF");
	for(i = 0; i < 40 - strlen(name_s); i++)
	{
		name[i] = '0';
	}

	strcat(name, name_s);
	strcat(msg,head);
	strcat(msg,name);
	printf("Func code: ");
	scanf("%c",&num_i);
	getchar();
//	getchar();
	for(i = 0; i < 7; i++)
	{
		num[i] = '0';
	}
	num[7] = num_i;
	strcat(msg,num);
	strcat(msg,"00000001");    //error code

	printf("Body msg: ");

	scanf("%s",body);
	getchar();
	len_b = strlen(body);

	for(i = 0; i < len_b; i++)
	{
		sprintf(body_str[index],"%x",body[i]);
		index++;
	}

	
	sprintf(length,"%x",len_b * 2);
	for(i = 0; i < 8 - strlen(body_len); i++)
	{
		body_len[i] = '0';
	}
	strcat(body_len,length);


	strcat(msg,body_len);

	for(i = 0; i < index; i++)
	{
		if(body_str[i][0] == '\0')
			break;
		strcat(msg,body_str[i]);
	}

	strcpy(a.str_msg,msg);

	printf("MSG: %s\n",msg);

	pthread_create(&snd_thread, NULL, send_msg, (void*)&a);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&a);
	pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);
	close(a.str_sock);

	return 0;

}

void *send_msg(void* arg)
{	
	A *a = (A*)arg;
	int index = 0, i = 0;
	int sock = a -> str_sock;
	char msg[MSG_SIZE] = {'\0', };
	P p;

	for(i = 56; i < 64; i++)
	{
		p.ecode[index++] = msg[i];
	}
	index = 0;
	strcpy(msg,a -> str_msg);
/*	for(i = 72; i < BODY_SIZE; i++)
	{
		if(msg[i] == '\0')
			break;
		msg[index++] = msg[i];
	}		

*/		
	if(atoi(p.ecode) == 100)
	{
		printf("Head fail\n");
	}
	else
	{
		printf("1\n");
		write(sock, msg, strlen(msg));
	}
	return NULL;
}

void *recv_msg(void* arg)
{
	int sock = *((int*)arg);
	char msg[MSG_SIZE] = {'\0', };
	int str_len = 0;
	int body_strlen = 0;
	int strlen_msg = 0;
	int mode = 0;
	int i = 0, index = 0;
	P p;
	
	while((str_len=read(sock, msg, sizeof(msg)))!=0)
	{
		printf("2\n");
	
		for(i = 0; i < 8; i++)
		{
			p.head[i] = msg[i];
		}

		for(i = 48; i < 56; i++)
		{
			p.fcode[index++] = msg[i];
		}	
		index = 0;

		mode = atoi(p.fcode);
		
		for(i = 56; i < 64; i++)
		{
			p.ecode[index++] = msg[i];
		}
		index = 0;

		for(i = 64; i < 72; i++)
		{
			p.blen[index++] = msg[i];
		}
		index = 0;

		body_strlen = atoi(p.blen);
		for(i = 72; i < 72 + body_strlen; i++)
		{
			p.bmsg[index++] = msg[i];
		}
		index = 0;

		if(mode == 1)
		{
			if(strcmp(p.ecode, "00000102") == 0)
			{
				printf("Error code: %s\n Got no message to save\n",p.ecode);
				break;
			}
			fputs("SUCCESS",stdout);

		}

		else if(mode == 2)
		{
			if(strcmp(p.ecode, "00000102") == 0)
			{
				printf("Error code: %s\n No message to read\n",p.ecode);
				break;			
			}
			
			if(str_len == -1)
				return (void*)-1;

			fputs(p.bmsg,stdout);
			fputs("\nSUCCESS\n",stdout);
		}

		else if(mode == 3)
		{
			if(strcmp(p.ecode, "00000101") == 0)
			{
				printf("Error code: %s\n No message to read\n",p.ecode);
				break;			
			}

			if(str_len == -1)
				return (void*)-1;

			fputs(p.bmsg,stdout);
			fputs("SUCCESS",stdout);
		}

		else if(mode == 4)
		{

			if(strcmp(p.ecode, "00000102") == 0)
			{
				printf("Error code: %s\n No message to delete\n",p.ecode);
				break;			
			}

			fputs("SUCCESS",stdout);

		}

		else if(mode == 5)
		{
			fputs("SUCCESS",stdout);
		}
	}

	return NULL;

}



	


	



	


	
	
