#include<stdio.h>
#include<stdlib.h>
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
}*head, *tail = NULL,*head1;       
 


int Count(struct node* h){

    struct node* t = h;
    int c= 0;
    while(t != NULL){
        c++;
        t = t -> next;
    }
    return c;

}

void setArr(int a[], struct node* head){
    int z = 0;
    struct node* t = head;
    while(head != NULL){
        a[z++] = head->data;
        head = head->next;
    }

}


void sort(int a[], int n){

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

void common_nodes(struct node *head,struct node *head1)
{
    int n1 = Count(head);
    int n2 = Count(head1);

    int a1[n1];
    int a2[n2];
    setArr(a1,head);
    setArr(a2, head1);

    
    sort(a1, n1);
    sort(a2, n2);
    

    n1--;
    n2--;
    int c = 0;
    int t1 = n2;
    while (n1 != -1){
        while (n2 != -1){
            if (a1[n1] == a2[n2]){
                c++;
                
            }
            n2--;
        }
        n1--;
        n2=t1;
    }

    printf("Number of common nodes: %d",c);





}
int main()  
{  
        int a,n,i,m;
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
    scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&a);
            struct node *newNode = (struct node*)malloc(sizeof(struct node));  
            newNode->data = a;  
            if(head1 == NULL) {  
            head1 = tail = newNode;   
            head1->previous = NULL;  
            tail->next = NULL;  
        }  
        else {
            tail->next = newNode;   
            newNode->previous = tail;  
            tail = newNode;  
            tail->next = NULL;  
        }  
    }
    common_nodes(head,head1);
    return 0;  
}  