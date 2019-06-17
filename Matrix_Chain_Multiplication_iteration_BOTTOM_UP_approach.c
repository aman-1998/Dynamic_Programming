#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,q,r,i;
    printf("Enter no. of matrices: ");
    scanf("%d",&n);
    int *p=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        printf("Enter the dimension of %d matrix: ",i);
        scanf("%d %d",&q,&r);
        p[i-1]=q;
        if(i==n)
            p[i]=r;
    }
    int min_mul=matrix_chain(p,n);
    printf("\nMinimum no. of multiplications required = %d\n",min_mul);
    return 0;
}
int matrix_chain(int p[],int n)
{
    int i,x,k,j,l;
    int **m=(int**)malloc((n+1)*sizeof(int*));
    int **s=(int**)malloc((n+1)*sizeof(int*));
    for(i=1;i<=n;i++)
    {
        m[i]=(int*)malloc((n+1)*sizeof(int));
        s[i]=(int*)malloc((n+1)*sizeof(int));
    }
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=999;
            for(k=i;k<=j-1;k++) //different splits
            {
                x=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(x<m[i][j])
                {
                    m[i][j]=x;
                    s[i][j]=k;
                }
            }
        }
    }
    return m[1][n];
}
