#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 100
#define NAME_SIZE 20

struct package
{
	int func;
	char name[10];
	int age;
	char fav_color[10];
	int fav_num;

};

void * send_msg(void*arg);
void * recv_msg(void * arg);


int main(int argc, char* argv[])
{
	int client;
	struct sockaddr_in serv_addr;
	char msg[50] = {0};
	struct package pack;
	char name[20] = {0};
	pthread_t snd_thread;
	pthread_t rcv_thread;
	if(argc != 4)
	{
		printf("Usage : %s <IP> <port> <name>\n", argv[0]);
		exit(1);
	}

	sprintf(name, "[%s]", argv[3]);

	client = socket(PF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));

	if(connect(client, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
	{
		printf("connect error");
		return -1;
	}

	pthread_create(&snd_thread, NULL, send_msg, (void*)&client);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&client);
	pthread_join(snd_thread, NULL);
	pthread_join(rcv_thread, NULL);

	close(client);
	return 0;

}

void * send_msg(void*arg)
{
	int client = *((int*)arg);
	char name_msg[NAME_SIZE+BUF_SIZE];
	int str_len;
	char msg[50] = {0};
	char name[20] = {0};
	while(1)
	{
		fgets(msg, BUF_SIZE, stdin);
		if(!strcmp(msg, "q\n")||!strcmp(msg, "Q\n"))
		{
			close(client);
			exit(0);
		}
		sprintf(name_msg, "%s %s", name, msg);
		write(client, name_msg, strlen(name_msg));
	}   
	return NULL;

}


void * recv_msg(void * arg)
{
    int client = *((int*)arg);
    char name_msg[NAME_SIZE+BUF_SIZE];
    int str_len;
    while(1)
    {
        str_len = read(client, name_msg, NAME_SIZE+BUF_SIZE-1);
        if(str_len ==-1)
            return (void*)-1;
        name_msg[str_len] =0;
        fputs(name_msg, stdout);
    }
    return NULL;
}

