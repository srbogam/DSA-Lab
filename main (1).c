/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define NO_OF_CHARS 256 

int main()
{
   char str[100000];
   
   scanf("%s",str);
   
   
   
    int n = strlen(str); 
    int cur_len = 1; 
    int max_len = 1;  
    int prev_index; 
    int i,end; 
    int* visited = (int*)malloc(sizeof(int) * NO_OF_CHARS); 
  
    
    for (i = 0; i < NO_OF_CHARS; i++) 
        visited[i] = -1; 
  
   
    visited[str[0]] = 0; 
  
    for (i = 1; i < n; i++) { 
        prev_index = visited[str[i]]; 
  
       
        if (prev_index == -1 || i - cur_len > prev_index) 
            {cur_len++; 
  
            }
        else {    
            if (cur_len > max_len) {
                max_len = cur_len; 
                end=i;
                
            }  
            cur_len = i - prev_index; 
        }
  
        
        visited[str[i]] = i; 
    } 
  
    
    if (cur_len > max_len){ 
        max_len = cur_len; 
        end=i;    
        
    } 
    free(visited); 
    
    
    printf("%d",max_len);
    printf("\n");
    for(int j=end-max_len;j<end;j++){
        printf("%c",str[j]);
    }
    return 0;
}
