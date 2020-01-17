/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

/*Link list Node */
struct Node
{
    int data;
    struct Node* next; //next is a variable that stores the address of a node.
};

void append(struct Node** head_ref,int ndata)
{
    
    struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
    new_node->data = ndata;
    struct Node *last = *head_ref;

    new_node->next = NULL;

    if(*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void printlist(struct Node *node)
{
    while(node != NULL)
    {
        printf("-> %d ",node->data);
        node=node->next;
    }
}
void removeduplicates(struct Node *head)
{
    struct Node* current = head;

    while(current->next != NULL)
    {
        if(current->data == current->next->data)
        {
            current->next=current->next->next;
        }
        else
        {
            current=current->next;
        }
    }

}
int main()
{
    char ch;
    int i=0;
    int a;
    struct Node* head=NULL;
    while(scanf("%d%c",&a,&ch)){
       if(ch=='\n')
          break;
          
        append(&head,a);
    }

    printf("\n created Linked list is");
    printlist(head);

    removeduplicates(head);
    printf("\n modified Linked list is ");
    printlist(head);
}