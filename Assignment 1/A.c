/*Question A  */
#include<stdio.h>

#include<stdlib.h>

int main()
{
  int rp,cp,rq,cq;
  int i,j;
  scanf("%d %d ",&rp, &cp );
  int p[rp][cp];
  for(i=0;i<rp;i++)
  {
    for(j=0;j<cp;j++)
    {
      scanf("%d",&p[i][j] );
    }
  }

  scanf("%d %d \n",&rq, &cq );
  int q[rq][cq];
  for(i=0;i<rq;i++)
  {
    for(j=0;j<cq;j++)
    {
      scanf("%d",&q[i][j] );
    }
  }
  /* Matrixes are stored in p and q */
//  printf("Matrix P is \n");
//  for(i=0;i<rp;i++)
//  {
//    for(j=0;j<cp;j++)
//    {
//      printf("%d",p[i][j]);
//    }
//    printf("\n");
//  }
//  printf("Matrix B is \n");
//  for(i=0;i<rq;i++)
//  {
//    for(j=0;j<cq;j++)
//    {
//      printf("%d",q[i][j]);
//    }
//    printf("\n");
//  }
  /*-----------------------*/
    int si,sj;
    int flag =0;
    int nel = rq*cq;


        for(i=0;i<rp-rq;i++)
        {
            for(j=0;j<cp-cq;j++)
            {
                /*-------------------*/
                if(p[i][j] == q[0][0]) // Found the starting element.
                {
                    si=i;
                    sj=j;
                    flag=0;

                    for(int m=0;m<rq;m++)
                    {
                        for(int n=0;n<cq;n++)
                        {
                            if(p[si+m][sj+n] == q[m][n])
                            {
                                flag++;
                            }
                        }
                    }
                }
                /*-------------------*/

            }
        }

    if (flag < nel)
    {
        printf("NO");
    }
    else if(flag == nel)
    {
        printf("yesh \n");
        printf("%d %d",si,sj);
    }
    return 0;
}
