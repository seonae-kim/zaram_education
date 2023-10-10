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

int main(int argc, char *argv[])
{
	char msg[MSG_SIZE] = {'\0', };
	char name[40] = {'\0', };
	char head[30] = {'\0', };
	struct sockaddr_in serv_addr;
	int sock;
	pthread_t snd_thread, rcv_thread;
	void *thread_return;
	int i = 0, j = 0, index = 20, len_b = 0;
	char num_i;
	char num[8] = {'\0', };
	char body[BODY_SIZE] = {'\0', };
	char body_len[10] = {'\0', };
	char body_char[BODY_SIZE * 2] = {'\0', };
	char body_str[BODY_SIZE][2] = {'\0', };
	char length[BODY_SIZE] = {'\0', };
	A a;
	
	a.str_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(a.str_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		printf("connect() error\n");
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
	scanf("%c",&num_i);
	getchar();
	printf("num_i : %c\n",num_i);
	getchar();
	for(i = 0; i < 7; i++)
	{
		num[i] = '0';
	}
	num[7] = num_i;
	for(i = 0; i < 8; i++)
	{
		printf("%c",num[i]);
	}

	strcat(msg,num);
	strcat(msg,"00000001");

	printf("body msg: ");

	scanf("%s",body);
	getchar();
	len_b = strlen(body);
	printf("len_b: %d\n",len_b);

	for(i = 0; i < len_b; i++)
	{
		sprintf(body_str[index++],"%x",body[i]);
	}
//	sprintf(body_char,"%x",body);

	printf("body_char: ");
	fputs(body,stdout);
	printf("\n");	
	
	sprintf(length,"%x",len_b * 2);
	for(i = 0; i < 8 - strlen(body_len); i++)
	{
		body_len[i] = '0';
	}
	strcat(body_len,length);

	printf("body_len: ");
	fputs(body_len,stdout);
	printf("\n");

	strcat(msg,body_len);
//	strcat(msg,body_char);

	for(i = 0; i < index; i++)
	{
		strcat(msg,body_str[i]);
	}

	strcpy(a.str_msg,msg);

	printf("%s\n",msg);

//	pthread_create(&snd_thread, NULL, send_msg, (void*)&a);
//	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&a);
//	pthread_join(snd_thread, &thread_return);
//	pthread_join(snd_thread, &thread_return);
	close(a.str_sock);

	return 0;

}
/*
void *program(void* a)
{
	A *a = (A*)a;
	int sock = a -> str_sock;
	char msg[MSG_SIZE] = {'\0', };
	char msg_body[BODY_SIZE] = {'\0', };
	int mode = 0, i = 0, index = 0;
	strcpy(msg, a -> str_msg);

	atoi(msg[29]) = mode;

	while(1)
	{
		if(mode == 1)
		{
			for(i = 31; i < MSG_SIZE; i++)
			{
				if((msg[i] >= 'a' && msg[i] <= 'z') || 
				   (msg[i] >= 'A' && msg[i] <= 'Z'))
				{
					for(i ; i < MSG_SIZE; i++)
					{
						msg_body[index++] = msg[i];
					}
					break;
				}
			}

			send_msg(sock,msg_body);
		}

		if(mode == 2)
		{
			recv_msg(sock);
		}

		if(mode == 3)
		{
			recv_msg(sock);
		}
	}

	return NULL;

}
*/

/*
void *send_msg(void* a)
{	A *a = (A*)a;
	int index = 0;
	int sock = a -> str_sock;
	char msg_body[20] = {'\0', };
	char error_code[4] = {'\0', };

	strcpy(msg_body, a -> str_msg);	
	atoi(msg[29]) = mode;
	for(i = 50; i < 55; i++)
	{
		error_code[index++] = msg[i];
	}

	while(1)
	{	
		if(atoi(error_code) == 100)
		{
			printf("failure\n");
			write(sock,error_code,strlen(error_code);
			continue;
		}

		write(sock, msg_body, strlen(msg_body));

	}
		retrun NULL;
}

void *recv_msg(void* arg)
{
	int sock = *((int*)arg);
	char msg_body[BODY_SIZE] ={'\0', };
	char msg[MSG_SIZE] = {'\0', };
	char error_code[4] = {'\0', };
	int strlen_msg = 0;
	int mode = 0;
	int i = 0, index = 0;
	
	for(i = 50; i < 55; i++)
	{
		error_code[index++] = msg[i];
	}

	while(1)
	{	
		strlen_msg = read(sock, msg, BODY_SIZE);
		if(strlen_msg == -1)
			return (void*)-1;

		for(i = 50; i < 55; i++)
		{
			error_code[index++] = msg[i];
		}

		if(atoi(error_code) != 1)
		{
			if(atoi(error_code) == 101)
			{
				printf("no send msg\n");
				continue;
			}
			else if(atoi(error_code) == 102)
			{
				printf("no saved msg\n");
				continue;
			}

		}		

//		atoi(msg[49]) = mode;

		if(mode == 1)
		{	
			fputs("success",stdout);

		}

		if(mode == 2)
		{
			
			if(msg_body == -1)
				return (void*)-1;

			fputs(msg_body,stdout);
		}

		if(mode == 3)
		{
			if(msg_body == -1)
				return (void*)-1;

			fputs(msg_body,stdout);
		}

		if(mode == 4)
		{


		fputs("success",stdout);


	}

	return NULL;

}
*/


	


	



	


	
	
