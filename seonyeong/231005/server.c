#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <time.h>

#define MAX_CLNT 256
#define BUF_SIZE 100
#define NAME_SIZE 20

void * handle_clnt(void * arg);
void send_msg(char * msg, int len);
void error_handling(char * msg);

int msg_cut(char *msg);
int count = 0;
int error_code = 0;

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
char buffer[BUF_SIZE + NAME_SIZE] = {0};
char msg[BUF_SIZE + NAME_SIZE] = {0};
char return_msg[BUF_SIZE + NAME_SIZE] = {0};
pthread_mutex_t mutx;

FILE *fm, *fl;

int main(int argc, char* argv[])
{
    int server = 0;
    struct sockaddr_in serv_addr, clnt_addr;
	int client = 0;
	int clnt_addr_size;
    pthread_t pthread;

	unsigned char head[] = {0x00,0x0B,0x6F,0xFF};
    char name[NAME_SIZE] = {0} ;
    int func_code = 0;
    int body_len = 0;
    char body[1000];

	if(argc!=2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

	pthread_mutex_init(&mutx, NULL);
    server = socket(PF_INET, SOCK_STREAM, 0 );
    memset(&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family=AF_INET; 
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(atoi(argv[1]));

	if(bind(server, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
	{
		printf("bind error\n");
		return -1;
	}
	if(listen(server, 5)==-1)
	{
		printf("listen error\n");
		return -1;
	}

	while(1)
	{
		clnt_addr_size = sizeof(clnt_addr_size);
		client = accept(server, (struct sockaddr*)&clnt_addr,&clnt_addr_size);
		
		pthread_mutex_lock(&mutx);
        clnt_socks[clnt_cnt++]=client;
        pthread_mutex_unlock(&mutx);

		pthread_create(&pthread, NULL, handle_clnt, (void*)&client);
        pthread_detach(pthread);
        printf("Connected client IP: %s \n", inet_ntoa(clnt_addr.sin_addr));

	}
	close(server);
	return 0;
}

void * handle_clnt(void * arg)
{
    int clnt_sock=*((int*)arg);
    int str_len=0, i;

    while((str_len=read(clnt_sock, msg, sizeof(msg)))!=0)
	{    
		//send_msg(msg, str_len);
		if(msg[53] == 54)
		{
			printf("exit\n");
			close(clnt_sock);
			exit(0);
		}
		
		else if(msg[53] == 49)
		{
			printf(" func_num : 1\n");
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			
			if((fm = fopen("message.txt", "a")) == NULL)
			{
				printf("fail1\n");
			}
			
			if((fl = fopen("error_code_log.txt", "a")) == NULL)
			{
				printf("fail2\n");
			}
			
			int msg_return = msg_cut(msg);

			if(msg_return == 3)
			{
				printf("msg : %s\n", msg);
				printf("head incorrect\n");
				error_code = 0100;
				sprintf( return_msg, "%d %04x", msg[53], error_code);
				write(clnt_sock, return_msg, strlen(return_msg));
			}

			else if(msg_return == 2)
			{	
				printf("msg : %s\n", msg);
				printf("no message\n");
			}

			else if(msg_return == 1)
			{
				error_code = 0001;
				printf("msg : %s\n", msg);
				


				fprintf(fm, "%s\n", msg);
				fprintf(fl, "%04x %d-%d-%d %d:%d\n", error_code,
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min );
				printf(" message save\n" );
				sprintf( return_msg, "%d %x", msg[53], error_code);
				write(clnt_sock, return_msg, strlen(return_msg));
				
			}
			else
			{
				printf("msg : %s\n", msg);
				printf("error\n");
			}

			fclose(fm);
			fclose(fl);
		}
		else if(msg[53] == 50)
		{
			printf("msg : %s\n", msg);
			printf(" func_num : 2\n");
		}

		else if(msg[53] == 51)
		{
			printf("msg : %s\n", msg);
			printf(" func_num : 3\n");
		}
		else if(msg[53] == 52)
		{
			printf("msg : %s\n", msg);
			printf(" func_num : 4\n");


		}
		else if(msg[53] == 53)
		{
			printf("msg : %s\n", msg);
			printf(" func_num : 5\n");

			if((fm = fopen("message.txt", "r")) == NULL)
			{
				printf("fail1\n");
			}
			
			remove("message.txt");

			fm = fopen("message.txt", "w");
			fclose(fm);
			printf("completely deleting all messages\n");

		}
		else 
		{
			printf("func_code error\n");
			close(clnt_sock);
			exit(0);

		}
	}

    pthread_mutex_lock(&mutx);
    for(i=0; i<clnt_cnt; i++) 
    {
        if(clnt_sock==clnt_socks[i])
        {
            while(i++<clnt_cnt-1)
                clnt_socks[i]=clnt_socks[i+1];
            break;
        }
    }
    clnt_cnt--;
    pthread_mutex_unlock(&mutx);
    close(clnt_sock);
    return NULL;
}

int msg_cut(char *msg)
{
	char head_cut[50] = {0};
	char body_cut[1000] = {0};
	int body_len_cut = 0;
	char temp[500] = {0};	

	strncpy(head_cut, msg, 8);
	if(strstr(head_cut, "000B6FFF") == NULL)
	{
		count == 3;
	}
	else
	{
		strncpy(temp, msg+62, 2);
		body_len_cut = atof(temp);
		strncpy(temp, msg+65, body_len_cut);
		sprintf(body_cut, "%s", temp);
		printf("%s\n", body_cut);

		if(strstr(body_cut, "32") != 0)
		{
			count = 2;
		}
		else
		{
			count = 1;
		}
	}

	return count;

}

