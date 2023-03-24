#include<stdio.h>
#include<stdlib.h>
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
}*head, *tail = NULL;       
  

int Count(struct node* h){

    struct node* t = h;
    int c= 0;
    while(t != NULL){
        c++;
        t = t -> next;
    }
    return c;

}

int isPrime(int data){
    int factors = 0;
    for (int i = 1; i <= data; i++){
        if (data % i == 0){
            factors++;
        }
    }
    if (factors == 2)
        return 1;
    else
        return 0;
}

void prime_product(struct node *head)
{
    int n = Count(head);
    
    int product = 1;
    while (head != NULL){
        if (isPrime(head->data)){// 1 or 0
            product *= head->data;
        }
        head = head->next;
    }

    printf("Product of Prime Nodes: %d", product);



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
    prime_product(head);
    return 0;  
}  