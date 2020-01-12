#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int count[10]={0},flag;
    //Find primes between M & N

    //traverse each number in the interval
    // with the help of for loop
    for(int i=m;i<=n;i++)
    {
        if(i==1 || i == 0)
            continue;

        flag =1;

        for(int j=2;j<=i/2;++j)
        {
            if(i%j==0)
            {
                flag = 0 ; //Stating its not a prime.
                break;
            }
        }
        if(flag ==1 ) //We have confirmed that i is a prime between m & n
        {
        int k = 1;
        int l=i;
        while(l>0)
        {
             k=l%10;
             l=l/10;
             count[k]=count[k]+1;
        }
        // printf("%d ,",i);
        }
    }

    printf("\n done");

    int max = count[0];
    int max_el=0;
    for(int i=0;i<10;i++)
    {
        if(count[i]>max)
        {
            max=count[i];
            max_el=i;
        }
    }
    printf("\n %d %d ",max_el,max);

    return 0;
}
