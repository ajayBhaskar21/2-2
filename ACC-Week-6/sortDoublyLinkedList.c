#include<stdio.h>
#include<stdlib.h>
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
}*head, *tail = NULL;     
void sort(struct node *head)
{
    
    struct node* i = head;
    struct node* j = head;
    for (i = head; i != NULL; i = i -> next){
        for (j = i->next; j != NULL; j= j ->next){

            if (i->data > j->data){
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }

    while(head){
        printf("%d ", head->data);
        head = head -> next;

    }

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
    sort(head);
    return 0;  
}  