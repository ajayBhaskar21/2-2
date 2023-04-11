#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*p,*new;



void rev(struct node* rhead, int data){
    struct node* newNode = (struct node*)malloc (sizeof (struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (rhead == NULL){
        rhead = newNode;
    }
    else{
        struct node* t = rhead;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = newNode;

    }


}

void reve(struct node* h, struct node* rhead){
    if (h != NULL){
        reve(h->next, rhead);
    }
    if (h == NULL)
        return ;
    rev(rhead, h->data);

    //printf("%d ", h->data);

}

void rever(struct node* h){
   
}
void palindrome(struct node *head)
{
    int a[1000];
    int z = 0;
    while(head){
        a[z++] = head->data;
        head = head -> next;
    }
    int i = 0;
    z--;
    while(i < z){
        if(a[i] != a[z]){
            printf("not a palindrome");
            return;
        }
        i++;
        z--;
    }
    printf("a palindrome");
}

int main()
{
    int n,i;
    scanf("%d",&n);
    while(n)
    {
        int v=n%10;
        
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
        n=n/10;
    }
    
palindrome(head);
    return 0;
}
