#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

// display the list
void printList(struct node *head){
	struct node *p = head;
	printf("\n[");

	//start from the beginning
	while(p != NULL) {
		printf(" %d ",p->data);
		p = p->next;
	}
	printf("]");
}

//insertion at the beginning
void insertatbegin(int data){

	//create a link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;

	// point it to old first node
	lk->next = head;

	//point first to new first node
	head = lk;
}
void insertatend(int data){

	//create a link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	struct node *linkedlist = head;

	// point it to old first node
	while(linkedlist->next != NULL)
		linkedlist = linkedlist->next;

	//point first to new first node
	linkedlist->next = lk;
}
void insertafternode(struct node *list, int data){
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	lk->next = list->next;
	list->next = lk;
}
void deleteatbegin(){
	head = head->next;
}
void deleteatend(){
	struct node *linkedlist = head;
	while (linkedlist->next->next != NULL)
		linkedlist = linkedlist->next;
	linkedlist->next = NULL;
}
void deletenode(int key){
	struct node *temp = head, *prev;
	if (temp != NULL && temp->data == key) {
		head = temp->next;
		return;
	}

	// Find the key to be deleted
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	// If the key is not present
	if (temp == NULL) return;

	// Remove the node
	prev->next = temp->next;
	free(temp);
}

void deletenode(char *key){
	struct node *temp = head, *prev;
	if (temp != NULL && strcmp(temp->data.name,key) == 0) {
		head = temp->next;
		return;
	}

	// Find the key to be deleted
	while (temp != NULL && strcmp(temp->data.name,key) == 0) {
		prev = temp;
		temp = temp->next;
	}

	// If the key is not present
	if (temp == NULL) return;

	// Remove the node
	prev->next = temp->next;
}

int deletenode(char *key){
	struct node *temp = head, *prev;
	int p=0;
	if (temp != NULL && strcmp(temp->data.name,key) == 0) {
		head = temp->next;
		p++;
		return p;
	}

	// Find the key to be deleted
	while (temp != NULL && strcmp(temp->data.name,key) == 0) {
		prev = temp;
		temp = temp->next;
		p++;
	}

	// If the key is not present
	if (temp == NULL) return p;

	// Remove the node
	prev->next = temp->next;
}

int searchlist(int key){
	struct node *temp = head;
	while(temp != NULL) {
		if (temp->data == key) {
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

struct node *searchlist_name(char* key){	
	struct node *temp = head;
	while(temp != NULL) {
		if (strcmp(temp->data.name,key)==0){
			return 1;
		}
		temp=temp->next;
	}
	return temp;
}

void main(){
	int k=0;
	insertatbegin(12);
	insertatbegin(22);
	insertatend(30);
	insertatend(44);
	insertatbegin(50);
	insertafternode(head->next->next, 33);
	printf("Linked List: ");

	// print list
	printList();
	deleteatbegin();
	deleteatend();
	deletenode(12);
	printf("\nLinked List after deletion: ");

	// print list
	printList();
	insertatbegin(4);
	insertatbegin(16);
	printf("\nUpdated Linked List: ");
	printList();
	k = searchlist(16);
	if (k == 1)
		printf("\nElement is found");
	else
		printf("\nElement is not present in the list");
}
