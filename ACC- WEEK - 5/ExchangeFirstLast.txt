#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*p,*new;

void show(struct node *t){
    struct node *p = t;
    while (p->next != t){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d", p->data);
}

void delete_prime(struct node *head)
{
    //show(head);
    struct node *last = head;




    while (last->next != head){
        last = last -> next;
    }

    int t = last->data;
    last->data = head->data;
    head->data = t;

    show(head);

    
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
    
    
delete_prime(head);
    return 0;
}
