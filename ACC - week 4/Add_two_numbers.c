#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*p;

int Count(int n){
    int c = 0;
    while(n != 0){
        c++;
        n = n / 10;
    }
    return c;
}



struct node* addnums(int a,int b)
{
    int sum = a + b;
    int n = Count(sum);
    int ans[n], z = 0;

    while(sum > 0){
        ans[z++] = sum % 10;
        sum = sum / 10;

    }

    struct node* head = NULL;
    
    for (int i = z - 1; i >= 0; i--){

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = ans[i];
        newNode->next = NULL;

        if (head == NULL){
            head = newNode;
        }
        else{
            struct node* temp1 = head;

            while (temp1->next != NULL){
                temp1 = temp1->next;
            }

            temp1->next = newNode;

        }




    }


    return head;
    


}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    struct node *h=addnums(a,b);
    while(h)
    {
        printf("%d",h->data);
        h=h->next;
    }
    return 0;
}