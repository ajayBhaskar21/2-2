#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*p,*new;

int notPrime(int data){
    if(data == 1){
        return 1;
    }
    int count = 0;
    
    for (int i = 1; i <= data; i++){
        if (data % i == 0){
            count++;
        }

        if (count > 2){
            return 1;
        }

    }

    return 0;


}

void delete_prime(struct node *head)
{
    
    struct node *t = head;

    while(t-> next != head){
        if(notPrime(t->data)){
            printf("%d ", t->data);

        }
        t = t->next;
    }
    if(notPrime(t->data)){
        printf("%d ", t->data);

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
    
    
delete_prime(head);
    return 0;
}

