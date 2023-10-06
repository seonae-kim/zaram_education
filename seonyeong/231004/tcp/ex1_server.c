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

struct package
{
	int func;
	char name[10];
	int age;
	char fav_color[10];
	int fav_num;

};

void send_msg(char *msg, int len);
void *handle_clnt(void *arg);

int main(int argc, char* argv[])
{
	int server = 0;
	int client = 0;
	int clnt_addr_size = 0;
	struct sockaddr_in serv_addr, clnt_addr;
	char msg[50] = {0};
	struct package pack;
	pthread_t thread;
	if(argc != 2 )
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	printf("<func> <name> <age> <fav_color> <fav_num>\n");

	scanf("%d %s %d %s %d", &pack.func, pack.name, &pack.age, pack.fav_color, &pack.fav_num );

	//	sprintf( msg, "%d %s %d %s %d", func, name, age, fav_color, fav_num ) ;

	serv_addr.sin_family=AF_INET; 
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(atoi(argv[1]));


	server = socket(PF_INET, SOCK_STREAM, 0);
	if(server < 0)
	{
		printf("socket create error\n");
		return -1;
	}

	if(bind(server, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
	{
		printf("bind error\n");
		return -1;
	}

	if(listen( server, 5) == -1)
	{
		printf("listen error\n");
		return -1;
	}

	while(1)
	{
		clnt_addr_size = sizeof(clnt_addr);
		client = accept(server, (struct sockaddr*) &clnt_addr , &clnt_addr_size);
	
		write( client, msg, sizeof(msg));
		pthread_create(&thread,NULL, handle_clnt, (void*)&client);
		
		if(strstr(msg,"q") != 0)
		{
			pthread_detach(thread);
			close(client);
			exit(0);
		}

		printf("Connected client IP: %s \n", inet_ntoa(clnt_addr.sin_addr));
	}
	close(server);
	return 0;
	}


void *handle_clnt(void *arg)
{
	int client = *((int*)arg);
	int str_len=0, i;
	char msg[BUF_SIZE];

	while((str_len=read(client, msg, sizeof(msg)))!=0)
		send_msg(msg, str_len);

	close(client);
	return NULL;
}

void send_msg(char *msg, int len)
{
	int client;
	write(client, msg, len);
}

