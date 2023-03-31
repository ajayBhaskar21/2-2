#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*p,*new;


void even(struct node *head)
{
    struct node *last = head;
    int c = 1;
    while (last->next != head){
        if (last->data % 2 != 0){
            printf("%d ", last->data);
            
        }
        
        
        last = last -> next;
    }
    if (last->data % 2 != 0){
        printf("%d ", last->data);
        
    }

}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        int v;
        scanf("%d",&v);
        if(head==NULL)
        {
            head=(struct node*)malloc(sizeof(struct node));
            p=head;
            head->next=NULL;
            p->data=v;
        }
        else
        {
            new=(struct node*)malloc(sizeof(struct node));
            new->data=v;
            new->next=NULL;
            p->next=new;
            p=new;
        }
    }
     int v;
        scanf("%d",&v);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=v;
    new->next=head;
    p->next=new;
    
    
even(head);
    return 0;
}

