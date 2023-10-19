#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Client
{
	char name[100];
	int age;
	int months;
	int start_year;
	int start_month;
	int start_day;
	int start_hour;
	int start_min;
	int end_year;
	int end_month;
	int end_day;
	int end_min;
	int remainingDays;
	int delete;
};
//linked list's node
struct Node		
{
	struct Client data;		//data
	struct Node* next;		//pointer
};
//linked list
struct LinkedList		// header struct(point first node
{
	struct Node* head;
};

//create a new node. 
struct Node* creatNode(struct Client client)		//function name = createNode
{	
	//allocate newNode
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode != NULL)					
	{
		newNode->data = client;			// client data to newNode
		newNode->next = NULL;
	}
	return newNode;		//newNode type = struct Node*
}

//Add a node to the end of the linked list
void addNode(struct LinkedList* list, struct Client client)
{
	//use createNode function
	struct Node* newNode = createNode(client);
	
	//handle memory allocation error
	if (newNode == NULL)
	{
		return;
	}

	if (list->head == NULL)
	{
		list->head = newNode;
	}

	else
	{
		struct Node* current = list->head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}




