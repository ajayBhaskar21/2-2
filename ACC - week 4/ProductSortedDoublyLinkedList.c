#include<stdio.h>
#include<stdlib.h>
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
}*head, *tail = NULL;   

struct node* sort(struct node* head){
    int a[1000], z = 0;
    struct node* t = head;
    while (t != NULL){
        a[z++] = t->data;
        t = t->next;
    }
    sort1(a, z);
    t = head;
    z = 0;
    while (t != NULL){
        t->data = a[z++];
        t = t->next;
    }
    return head;

}
void sort1(int a[], int n){

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

}



void product_pair(struct node *head)
{
    

    int p;
    scanf("%d", &p);
    
    head = sort(head);
    struct node* i = head;
    struct node* j = head->next;
    struct node* t1 = head;
    struct node* t2 = head->next;

    while (i->next != NULL){
        while (j != NULL){
            if (i->data * j->data == p){
                printf("( %d , %d )\n", i->data, j->data);
            }
            j = j->next;
        }

        i = i->next;
        j = i->next;

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
    product_pair(head);
    return 0;  
}  