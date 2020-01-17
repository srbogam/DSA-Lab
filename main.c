/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    
    int data;
    struct Node* next;
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

struct Node *add(struct Node *node1,struct Node *node2){
    
    int f=0,cr=0;
    
    
    struct Node *curr1= node1;
    struct Node *curr2= node2;
    
    while(curr1!=NULL || curr2!=NULL){
        
        if(curr1!=NULL && curr2==NULL){
            
            
            
            if(cr==0){
                break;
            }
            else{
                if(curr1->data==0){
                        curr1->data=1;
                        cr=0;
                }
                else if(curr1->data==1){
                    curr1->data=0;
                    cr=1;
                }
            }
            
            curr1=curr1->next;
            
        }
        else if(curr1==NULL && curr2!=NULL){
             f=1;
            
            if(cr==0){
                break;
            }
            else{
                if(curr2->data==0){
                        curr2->data=1;
                        cr=0;
                }
                else{
                    curr2->data=0;
                    cr=1;
                }
            }
            
             curr2=curr2->next;

        }
        else if(curr1!=NULL && curr2!=NULL){
            
            if(cr==0){
            if(curr1->data == 0 && curr2->data == 1 || curr1->data == 1 && curr2->data ==0){
                curr1->data=1;
                curr2->data=1;
            }
            else if(curr1->data ==1 && curr2->data ==1){
                cr=1;
                curr1->data=0;
                curr2->data=0;
                
            }
            }
            else{
                 if(curr1->data ==0 && curr2->data ==1 || curr1->data ==1 && curr2->data ==0){
                curr1->data=0;
                curr2->data=0;
                cr=1;
            }
            else if(curr1->data ==0 && curr2->data ==0){
                cr=0;
                curr1->data=1;
                curr2->data=1;
                
            }
            }
                
            curr2=curr2->next;
            curr1=curr1->next;
           
           
            }
        }
        
        printlist(node1);
        printf("\n");
        printlist(node2);
        
        printf("\n");
       
        if(cr==1){
            if(f==0){
                append(&node1,1);
                return node1;
            }
            else{
               append(&node2,1);
               return node2;
                
            }
        }
        else{
            if(f==0){
                
                return node1;
            }
            else{
        
               return node2;
                
            }
        }
        
        
}

void reverse(struct Node **head) 
    { 
        
        struct Node* current = *head; 
        struct Node* prev = NULL; 
        struct Node* next = NULL;
        while (current != NULL) { 
           
            next = current->next; 
  
            
            current->next = prev; 
  
    
            prev = current; 
            current = next; 
        } 
        *head = prev; 
        
        
    } 

int main(){
    
    char str1[100000];
    char str2[100000];
    struct Node *head1 =NULL;
    struct Node *head2 =NULL;

    
    scanf("%s",str1);
    scanf("%s",str2);
    
    int a=strlen(str1);
    int c=strlen(str2);

    int b;
    
    
    
    for(int i=a-1;i>=0;i--){
        b=(int)(str1[i]);
        b=b-48;
        
        append(&head1,b);
    }
    
     for(int i=c-1;i>=0;i--){
        b=(int)(str2[i]);
        b=b-48;
        
        append(&head2,b);
    }
    
 
   struct Node *head= add(head1,head2);
    
    reverse(&head);
    printlist(head);
    
    return 0;
    
    
}