#include <stdio.h>
#include <stdlib.h>
struct ds
{
    struct ds *next;
    int data;
    struct ds *last;
    struct ds *start;
};

void insert(int n, struct ds *S)
{
    struct ds *temp = (struct ds *)malloc(sizeof(struct ds));
    if (!S->data)
    {
        S->data = n;
    }
    else
    {
        temp->data = n;
        temp->start = S;
        temp->last = temp;
        S->last->next = temp;
        S->last = temp;
    }
    printf("Inserted %d\n", S->last->data);
}

void REMOVE_BOTTOM_HALF(struct ds *S){
    int sum = 0,count=0,avg=0;
    struct ds *temp = S;
    while(temp){
        sum+=temp->data;
        temp=temp->next;
        count++;
    }
    avg = sum/count;
    temp = S;
    while(temp){
        if(temp->data <= avg){
            if(temp == S){
                S->data = S->next->data;
                S->next = S->next->next;
            }
        }
    }
}

void traverse(struct ds *S)
{
    struct ds *temp;
    temp = S;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    printf("Enter size of data structure plOx\n");
    int n;
    scanf("%d", &n);
    struct ds *s = (struct ds *)malloc(sizeof(struct ds));
    s->start = s;
    s->last = s;
    for (int i = 0; i < n; ++i)
    {
        printf("Enter number\n");
        int num;
        scanf("%d", &num);
        insert(num, s);
    }
    printf("Traversing\n");
    traverse(s);
}
