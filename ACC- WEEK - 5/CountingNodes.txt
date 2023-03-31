#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*p,*new;
void count(struct node *head)
{
    int c = 0;
    struct node *t=head;
    while(t->next != head){
        printf("%d ", t->data);
        t = t->next;
        c++;
    }
    printf("%d\n", t->data);
    printf("%d",c+1);
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
    
    
count(head);
    return 0;
}
