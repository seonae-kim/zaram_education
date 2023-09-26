#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct date
{
	int year;
	int mon;
	int mday;
	int hour;
	int min;
}D;
typedef struct member
{
	char name[30];
	int age;
	D start;
	D end;
	D remain;
}M;
struct node {
	M data;
	struct node *next;
};

struct node *insertatbegin(struct node *head, M data);
struct node *insertatend(struct node *head, M data);
void printList(struct node *head);
struct node *insertafternode(struct node *list, M data);
struct node *deleteatbegin(struct node *head);
struct node *deleteatend(struct node *head);
struct node *deletenode_name(struct node *head,char *key,int *f_flag);
struct node *searchlist_name(struct node *head,char *key);




