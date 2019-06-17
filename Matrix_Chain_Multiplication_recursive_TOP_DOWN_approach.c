#include<stdio.h>
#include<stdlib.h>
int memoization_matrix_chain(int p[],int n);
int look(int **m,int p[],int i,int j);
int main()
{
    int n,i,q,r;
    printf("Enter no. of matrices: ");
    scanf("%d",&n);
    int *p=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        printf("Enter dimension of %d matrix: ",i);
        scanf("%d %d",&q,&r);
        p[i-1]=q;
        p[i]=r;
    }
    int min_mul=memoization_matrix_chain(p,n);
    printf("\nMinimum no. of multiplications required = %d\n",min_mul);
    return 0;
}
int memoization_matrix_chain(int p[],int n)
{
    int i,j;
    int **m=(int**)malloc((n+1)*sizeof(int*));
    for(i=1;i<=n;i++)
        m[i]=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            m[i][j]=999;
    }
    return look(m,p,1,n);
}
int look(int **m,int p[],int i,int j)
{
    int x,k;
    if(m[i][j]<999)
        return m[i][j];
    if(i==j)
        m[i][j]=0;
    for(k=i;k<=j-1;k++)
    {
        x=look(m,p,i,k)+look(m,p,k+1,j)+p[i-1]*p[k]*p[j];
        if(x<m[i][j])
            m[i][j]=x;
    }
    return m[i][j];
}
