#include <stdio.h>
#include <stdlib.h>
int A[100000];
int size=0;
struct node{
    int val;
    struct node* next;
};
void Insert(struct node **head, int value)
{
    if(A[value]==0){
        struct node * new_node = NULL;
        new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL)
        {
            printf("Failed to insert element.Out of memory");
            return;
        } 
        new_node->val = value; 
        new_node->next = *head;
        *head = new_node; 
        A[value]=1;
    }
}
void Display(struct node *head)
{
    struct node *temp;
    temp=head;
    printf("\033[0;32m");
    printf("H");
    while(temp)
    {
        printf("->%d", temp->val);
        temp = temp->next;
    }
    printf("\n\n");
    printf("\033[0m");
}
void Asc(struct node *head){
    int max;
    struct node *temp2=head,*temp3=head,*temp4=head,*temp5=head;
    for(int i=0;temp2->next!=NULL;temp2=temp2->next){
        if(max<=temp2->val) max=temp2->val;
        size=size+1;
    }
    int M[max+1];
    for(int i=0;i<=max;i++) M[i]=0;
    while (temp3!=NULL)
    {
        M[temp3->val]=1;
        temp3=temp3->next;
    }
    for(int i=0;i<=max;i++){
        if(M[i]==1){
            temp4->val=i;
            temp4=temp4->next;
        }
    }
    size=size/2;
}
void deleteFirstNode(struct node *head)
{
    struct node *ptr;  
        if(head == NULL)  
        {  
            printf("\nList is empty");  
        }  
        else   
        {  
            ptr = head;  
            head = ptr->next;  
            free(ptr);  
            printf("\n Node deleted from the begining ...");  
        }  
}
void delete(struct node *head)  
{   
    while (size!=0)  
    {  
    deleteFirstNode(head);
    size=size-1;
    }  
}
void main(){
    int val;
    struct node * head = NULL;
    int n=1;
    while (n!=0)
    {
        printf("\n0.To exit\n 1.To Insert Element\n 2.Remove Bottom Half(S)\n");
        scanf("%d",&n);
        switch (n)
        {
        case 0:
            n=0;
            break;
        case 1:
            printf("Enter the value to insert\n");
            scanf("%d",&val);
            Insert(&head,val);
            printf("\nAfter Operation\n");
            Display(head);
            break;
        case 2:
            Asc(head);
            Display(head);
            delete(head);
            printf("\nAfter Operation\n");
            Display(head);
            break;
        default:
            printf("Enter valid option");
            break;
        }
    }
}