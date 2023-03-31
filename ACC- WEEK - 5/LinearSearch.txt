#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct StackNode {
    struct Node* node;
    struct StackNode* next;
};
struct StackNode* create_stack_node(struct Node* node) {
    //complete the code
}
void push(struct StackNode** top, struct Node* node){
    //complete the function
}
struct Node* pop(struct StackNode** top) {
    //complete the code
}

void firstans(struct Node *head, int x){
    struct Node* t = head;
    while (t){
        if (t->data == x)
        {
            printf("Element found\n");
            return 1;
        }
        t = t -> next;
    }
    printf("Element not found\n");


}

int linear_search(struct Node* head,int x) {
    //perform linear search here

    //printf("Element not found");

    while(head){
        //printf("%d ",head->data);
        if (x == head->data){
            printf("Element found");
            return 1;
        }
            
        head = head->prev;
    }
    printf("Element not found");
    return 0;
}
int main() {
    struct Node* head = NULL;
    
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int x;
    scanf("%d",&x);
    for (int i = 0; i < size; i++) {
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->data = arr[i];
        node->prev = head;
        node->next = NULL;
        if (head != NULL) {
            head->next = node;
        }
        head = node;
    }
    linear_search(head,x);
   
    return 0;
}