#include<stdio.h>
#include<stdlib.h>
struct node
{
    int ob;
    int w,p;
};
int ZO_knapsack(struct node *A,int n,int W);
int main()
{
    int n,W,i;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d",&W);
    printf("Enter no. of objects: ");
    scanf("%d",&n);
    struct node *A=(struct node*)malloc((n+1)*sizeof(struct node));
    for(i=1;i<=n;i++)
    {
        printf("Enter weight and profit associated with ob%d: ",i);
        scanf("%d %d",&A[i].w,&A[i].p);
        A[i].ob=i;
    }
    int max_profit=ZO_knapsack(A,n,W);
    printf("\nMaximum profit = %d\n",max_profit);
    return 0;
}
int ZO_knapsack(struct node *A,int n,int W)
{
    int i,j,x,y;
    int **k=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
        k[i]=(int*)malloc((W+1)*sizeof(int));
    for(i=0;i<=W;i++)
        k[0][i]=0;
    for(i=0;i<=n;i++)
        k[i][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(j<A[i].w)
                k[i][j]=k[i-1][j];
            else
            {
                x=A[i].p+k[i-1][j-A[i].w];
                y=k[i-1][j];
                k[i][j]=x>y?x:y;
            }
        }
    }
    return k[n][W];
}
