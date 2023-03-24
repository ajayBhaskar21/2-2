#include<stdio.h>
#include<stdlib.h>
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
}*head, *tail = NULL;       
   


void rotate(struct node *head)
{
    int k;
    scanf("%d", &k);

    while (k--){
        
        struct node* tra = head;

        while (tra->next != NULL){
            tra = tra->next;
        }
        tra->previous->next = NULL;
        tra->previous = NULL;
        head->previous = tra;
        tra->next = head;
        head = tra;


    }    
    
    struct node* p = head;
    while(p != NULL){
        printf("%d ", p->data);
        p = p -> next;
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
    rotate(head);
    return 0;  
}  