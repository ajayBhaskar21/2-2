#include<stdio.h>
#include<stdlib.h>
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
}*head, *tail = NULL;       
   


void triplet(struct node *head)
{
    int x;
    scanf("%d", &x);


    struct node *t1;
    struct node *t2;
    struct node *t3;

    int count = 0;

    for (t1 = head; t1 != NULL; t1 = t1 ->next){
        for (t2 = t1->next; t2 != NULL; t2 = t2 -> next){
            for (t3 = t2 -> next; t3!=NULL; t3=t3->next){
                if (t1->data * t2->data * t3->data == x)
                    count++;
            }
        }
    }


    printf("Count of triplets: %d", count);


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
    triplet(head);
    return 0;  
}  