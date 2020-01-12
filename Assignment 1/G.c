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
    // allocating a node
    struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
    new_node->data = ndata;
    struct Node *last = *head_ref;

    new_node->next = NULL;

    if(*head_ref == NULL) //If the list is empty, jus creates a new node
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
    int n=10;
    int i=0;
    int a;
    struct Node* head=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        append(&head,a);
    }

    printf("\n created Linked list is");
    printlist(head);

    removeduplicates(head);
    printf("\n modified Linked list is ");
    printlist(head);
}
