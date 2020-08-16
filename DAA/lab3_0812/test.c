#include<stdio.h>
#include<stdlib.h>

struct node 
{
 int data; 
 struct node *next;
};

int InsertAtEnd(struct node *start,struct node *last,int i)
 {
   struct node *temp=malloc(sizeof(struct node));
   temp->data=i; 
   temp->next=NULL;

  if(start==NULL)
  {
    printf("Inserting head\n");
    start=temp;
    last=temp;
    return 0;
  }
  printf("Inserting\n");
  last->next=temp;
  last=last->next;
  return 0;
}

void traverse(struct node *list) {
  printf("Traversing.\n");
  struct node* t;

  t = list;

  if (t == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  while (t->next != NULL) {
    printf("%d\n", t->data);
    t = t->next;
  }
  printf("%d\n", t->data);
}

int main(){
 struct node *HEAD=NULL;
 struct node *LAST=NULL;
 int i=1;
 for(i=1;i<11;i++)
     InsertAtEnd(HEAD,LAST,i);
  traverse(HEAD);
 }



