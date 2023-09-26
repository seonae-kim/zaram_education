#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"
// display the list

void printList(struct node *head){
	struct node *p = head;
		printf("===============================================================================================================================================================================================\n");
		printf("%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n","name","age","year","month","day","hour","min","year","month","day","hour","min","year","month","day","hour","min");
		printf("===============================================================================================================================================================================================\n");

	//start from the beginning
	while(p != NULL) {
		printf(" %10s%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d \n",p->data.name,p->data.age,p->data.start.year,p->data.start.mon,p->data.start.mday,p->data.start.hour,p->data.start.min,p->data.end.year,p->data.end.mon,p->data.end.mday,p->data.end.hour,p->data.end.min,p->data.remain.year,p->data.remain.mon,p->data.remain.mday,p->data.remain.hour,p->data.remain.min);
		p=p->next;
		}
}

//insertion at the beginning
struct node *insertatbegin(struct node *head,M data){

	//create a link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;

	// point it to old first node
	lk->next = head;

	//point first to new first node
	head = lk;

	return head;
}
struct node *insertatend(struct node *head,M data){

	//create a link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	struct node *linkedlist = head;

	// point it to old first node
	while(linkedlist->next != NULL)
		linkedlist = linkedlist->next;

	//point first to new first node
	linkedlist->next = lk;
	return head;
}
struct node *insertafternode(struct node *list, M data){
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	lk->next = list->next;
	list->next = lk;
	return lk;
}
struct node *deleteatbegin(struct node *head){
	head = head->next;
	return head;
}
struct node *deleteatend(struct node *head){
	struct node *linkedlist = head;
	while (linkedlist->next->next != NULL)
		linkedlist = linkedlist->next;
	linkedlist->next = NULL;
	return head;
}
struct node *deletenode_name(struct node *head,char *key,int *f_flag){
	struct node *temp = head, *prev;
	if (temp != NULL && strcmp(temp->data.name,key) == 0) {
		head = temp->next;
		*f_flag = 1;
		return head;
	}

	// Find the key to be deleted
	while (temp != NULL && strcmp(temp->data.name,key) != 0) {
		prev = temp;
		temp = temp->next;		
	}

	// If the key is not present
	if (temp == NULL) 
	{
		*f_flag = 0;
		return NULL;
	}

	// Remove the node
	prev->next = temp->next;
	*f_flag = 1;
	return prev;
}


struct node *searchlist_name(struct node *head,char* key){	
	struct node *temp = head;
	while(temp != NULL) {
		if (strcmp(temp->data.name,key)==0){
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}

