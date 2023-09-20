#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member
{
    char name[20];
    int age;
    char start_date[50];
    char end_date[50];
    int remain_period;

};

struct node{
    struct member data;
    struct node *next;
};

struct node *head = NULL;

void printList(){ 
      struct node *p = head;
      printf("\n[");

      while(p != NULL)
      {
          printf(" %s %d %s %s %d \n", 
                  p -> data.name, p -> data.age ,p -> data.start_date ,
                  p -> data.end_date ,p -> data.remain_period);
          
          p = p->next;
      }
      printf("]");
  }

int mode6()
{
	printList();	
	return 0;
}
