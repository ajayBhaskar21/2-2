#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*p,*new;
void remove_dup(struct node *head)
{
    
    struct node *i = head;
    struct node *j;

    
    for (i = head; i != NULL; i = i -> next){
        for (j = i->next; j != NULL; j= j ->next){

            if (i->data < j->data){
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }


    for(i = head; i != NULL; i = i -> next){
        for(j = i->next; j != NULL; j = j -> next){
            if(i->data == j->data){
                j->data = -10;
            }
        }
    }
    while(head){
        if (head->data == -10){
            head = head -> next;
            continue;
        }
            
        printf("%d ", head->data);
        head = head -> next;
    }

}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
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
    
    remove_dup(head);
        return 0;
}