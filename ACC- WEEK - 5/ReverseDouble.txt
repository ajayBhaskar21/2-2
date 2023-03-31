#include<stdio.h>
#include<stdlib.h>
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
}*head, *tail = NULL;       
 


void show(struct node* h, struct node* head){
    struct node *t = h;
    while(t != head){
        printf("%d ", t->data);
        t = t->previous;
    }
    printf("%d", t->data);
}

void reverse(struct node *head)
{
    struct node *last = head;
    while (last->next){
        last = last->next;
    }
    show(last, head);
    

}
int main()  
{  
        int a,n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            struct node *newNode = (struct node*)malloc(sizeof(struct node));  
            newNode->data = a;  
            if(head == NULL) {  
            head = tail = newNode;   
            head->previous = NULL;  
            tail->next = NULL;  
        }  
        else {
            tail->next = newNode;   
            newNode->previous = tail;  
            tail = newNode;  
            tail->next = NULL;  
        }  
    }
    reverse(head);
    return 0;  
}  