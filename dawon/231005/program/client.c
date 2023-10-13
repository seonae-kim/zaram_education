#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/socket.h>

#define MSG_SIZE 1080
#define BODY_SIZE 1000
void *recv_msg(void * arg);
void *send_msg(void * arg);

typedef struct arg
{
	int str_sock;
	char name[40];
}A;

typedef struct program
{
	char head[8];
	char name[40];
	char fcode[8];
	char ecode[8];
	char blen[8];
	char bmsg[BODY_SIZE];
}P;

int main(int argc, char *argv[])
{
	char msg[MSG_SIZE] = {'\0', };
	char name[40] = {'\0', };
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

	sprintf(a.name,"%x",argv[3][0]);
	
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
	int sock = a -> str_sock;
	P p;

	strcpy(p.name,a->name);
	while(1)
	{
		char msg[MSG_SIZE] = {'\0', };
		char name[40] = {'\0', };
		char head[30] = {'\0', };
		int i = 0, j = 0, index = 0, len_b = 0;
		char num_i[2];
		char num[8] = {'\0', };
		char body[BODY_SIZE] = {'\0', };
		char body_len[10] = {'\0', };
		char body_char[BODY_SIZE * 2] = {'\0', };
		char body_str[BODY_SIZE * 2][3] = {'\0', };
		char length[BODY_SIZE] = {'\0', };


		strcpy(head,"000B6FFF");
		for(i = 0; i < 40 - strlen(p.name); i++)
		{
			name[i] = '0';
		}

		strcat(name, p.name);
		strcat(msg,head);
		strcat(msg,name);
		printf("Func code: ");
		fgets(num_i,sizeof(num_i),stdin);
		while(getchar()!= '\n');
		for(i = 0; i < 7; i++)
		{
			num[i] = '0';
		}
		strcat(num,num_i);
		num[8] = '\0';
		if(num[7] == '6')
		{
			printf("Program Exit\n");
			exit(0);
		}
		if(!(num[7] >= '1' && num[7] <= '6'))
		{
			printf("\nMode Error\n");
			continue;
		}
				
		strcat(msg,num);
		strcat(msg,"00000001");    //error code

		printf("Body msg: ");

		fgets(body,sizeof(body),stdin);
		len_b = strlen(body) - 1;
		body[len_b] = '\0';

		for(i = 0; i < len_b; i++)
		{
			sprintf(body_str[index],"%x",body[i]);
			index++;
		}

		
		sprintf(length,"%x",len_b  * 2);
		for(i = 0; i < 8 - strlen(length); i++)
		{
			body_len[i] = '0';
		}
		strcat(body_len,length);
		body_len[9] = '\0';

		strcat(msg,body_len);

		for(i = 0; i < index; i++)
		{
			if(body_str[i][0] == '\0')
				break;
			strcat(msg,body_str[i]);
		}
		msg[72+ len_b * 2] = '\n';


		printf("MSG: %s\n",msg);

		index = 0;
		for(i = 56; i < 64; i++)
		{
			p.ecode[index++] = msg[i];
		}
		index = 0;
	
		if(atoi(p.ecode) == 100)
		{
			printf("Head fail\n");
		}
		else
		{
			write(sock, msg, strlen(msg));
		}

	}
	return NULL;
}

void *recv_msg(void* arg)
{
	A *a = (A*) arg;
	int sock = a -> str_sock;
	char msg[MSG_SIZE] = {'\0', };
	char rmsg[3] = {'\0', };
	int imsg = 0;
	char cmsg[3] = {'\0', };
	char pmsg[BODY_SIZE] = {'\0', };
	int str_len = 0;
	int body_strlen = 0;
	int strlen_msg = 0;
	int mode = 0;
	int i = 0, index = 0, count = 0;
	P p;
	
	while(1)
	{

		str_len=read(sock, msg, MSG_SIZE);
		printf("\nMSG from Server >> \n%s\n",msg);
	
		for(i = 0; i < 8; i++)
		{
			p.head[i] = msg[i];
		}
		p.head[8] = '\0';
		
		index = 0;
		for(i = 48; i < 56; i++)
		{
			p.fcode[index++] = msg[i];
		}	
		p.fcode[index] = '\0';
		index = 0;

		mode = atoi(p.fcode);
		
		for(i = 56; i < 64; i++)
		{
			p.ecode[index++] = msg[i];
		}
		p.ecode[index] = '\0';
		index = 0;

		for(i = 64; i < 72; i++)
		{
			p.blen[index++] = msg[i];

		}
		p.blen[index] = '\0';
		index = 0;

		body_strlen = strtol(p.blen,NULL,16);
		for(i = 72; i < 72 + body_strlen; i++)
		{
			p.bmsg[index++] = msg[i];
		}
		p.bmsg[index] = '\0';
		index = 0;

		if(mode == 1)
		{
			p.ecode[8] = '\0';
			if(strcmp(p.ecode, "00000102") == 0)
			{
				printf("\nError code: %s\n Got no message to save\n",p.ecode);
				continue;
			}
			printf("\nMode 1 SUCCESS\n");
		}

		else if(mode == 2)
		{
			p.ecode[8] = '\0';
			if(strcmp(p.ecode, "00000102") == 0)
			{
				printf("\nError code: %s\n No message to read\n",p.ecode);
				continue;			
			}
			
			if(str_len == -1)
				return (void*)-1;
			if(strcmp(p.bmsg,"done") == 0)
			{
				fputs("\nMode 2 SUCCESS\n",stdout);
				continue;
			}


			printf("Reading File >> \n%s",p.bmsg);
			

		}

		else if(mode == 3)
		{
			p.ecode[8] = '\0';
			if(strcmp(p.ecode, "00000101") == 0)
			{
				printf("\nError code: %s\n No message to read\n",p.ecode);
				continue;			
			}

			if(str_len == -1)
				return (void*)-1;

			printf("Reading File >> \n%s",p.bmsg);
			if(strcmp(p.bmsg,"done") == 0)
			{
				fputs("\nMode 3 SUCCESS\n",stdout);
				continue;
			}
		}

		else if(mode == 4)
		{
			p.ecode[8] = '\0';
			if(strcmp(p.ecode, "00000102") == 0)
			{
				printf("\nError code: %s\n No message to delete\n",p.ecode);
				continue;			
			}

			fputs("\nMode 4 SUCCESS\n",stdout);

		}

		else if(mode == 5)
		{
			printf("\nMode 5 SUCCESS\n");
		}
	}

	return NULL;

}



	


	



	


	
	
