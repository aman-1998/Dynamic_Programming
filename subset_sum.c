#include<stdio.h>
#include<stdlib.h>
int subset_sum(int A[],int n,int S);
int main()
{
    int n,S,i;
    printf("Enter no. of elements in the set: ");
    scanf("%d",&n);
    int *A=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        printf("Enter A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    printf("Enter the sum: ");
    scanf("%d",&S);
    int ch=subset_sum(A,n,S);
    if(ch==1)
        printf("\nThere exist a subset whose sum is %d\n",S);
    else
        printf("\nThere does not exist a subset whose sum is %d\n",S);
    return 0;
}
int subset_sum(int A[],int n,int S)
{
    int i,j;
    int **ss=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
        ss[i]=(int*)malloc((S+1)*sizeof(int));
    for(i=0;i<=n;i++)
        ss[i][0]=1;
    for(i=1;i<=S;i++)
        ss[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=S;j++)
        {
            if(A[i]>j)
                ss[i][j]=ss[i-1][j];
            else
                ss[i][j]=ss[i-1][j-A[i]] || ss[i-1][j];
        }
    }
    return ss[n][S];
}
