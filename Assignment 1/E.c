#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    char sen[1000];
    gets(sen);

    int space=0;
    char senr[1000]="";
    // char word[1000000];


    // For counting the no of words
    for(int i=0;sen[i] != '\0';i++)
    {
        if(sen[i] == ' ')
            space++;
    }
    int nw=space+1;

    int k=0;
    int i;
    char re = ' ';
    char el = '\0';

    for(i=0;sen[i] != '\0' ;i++)
    {
        if(sen[i] == ' ')
        {

            for(int j=i-1;sen[j]!=' '&&j>=0;j--)
            {
               strncat(senr,&sen[j],1);
            }
            strncat(senr,&re,1);

        }
        else
        {
        }
    }
    for(int j=i-1;sen[j]!=' '&&j>=0;j--)
    {
        strncat(senr,&sen[j],1);
    }
    strncat(senr,&el,1);
    puts(senr);


    int p=0;
    for(i=0; ;i++)
    {

            if(sen[i]==' '||sen[i]=='\0'){
                if(p==0){
                    for(int j=i-1;sen[j]!=' '&&j>=0;j--)
                    {
                        printf("%c",sen[j]);
                    }
                    printf("%c",'\n');
                }
                p=0;
            }else{
                if(sen[i]!=senr[i]){
                    p=1;
                }
            }

            if(sen[i]=='\0'){
                break;
            }
    }


}
