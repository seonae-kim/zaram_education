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


int main(int argc, char* argv[])
{
	int server = 0;
	struct sockaddr_in serv_addr, clnt_addr;
	char msg[50] = {0};

	if(argc != 7 )
	{
		printf("Usage : %s <port> <func> <name> <age> <fav_color> <fav_num>\n", argv[0]);
		exit(1);
	}

	sprintf( msg, "%d %s %d %s %d", func, name, age, fav_color, fav_num ) ;

	serv_adr.sin_family=AF_INET; 
    serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_adr.sin_port=htons(atoi(argv[1]));


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

	client = accept(server, (struct sockaddr*) &clnt_addr,sizeof(clnt_addr));

	write( client, msg, sizeof(msg));

	close(server);
	return 0;
}


