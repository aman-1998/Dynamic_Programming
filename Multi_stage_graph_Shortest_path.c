#include<stdio.h>
#include<stdlib.h>
int Shortest_Path_Multi_Stage_Graph(int **cost,int n,int s,int d);
int main()
{
    int n,i,j,s,d;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    int **cost=(int**)malloc((n+1)*sizeof(int*));
    for(i=1;i<=n;i++)
        cost[i]=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("Enter cost[%d][%d] ",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d",&s);
    printf("Enter the destination vertex: ");
    scanf("%d",&d);
    int sp=Shortest_Path_Multi_Stage_Graph(cost,n,s,d);
    printf("\nShortest path from %d to %d = %d\n",s,d,sp);
    return 0;
}
int Shortest_Path_Multi_Stage_Graph(int **cost,int n,int s,int d)
{
    int x,i,j;
    int *S=(int*)malloc((n+1)*sizeof(int));
    for(i=n;i>=1;i--)
    {
        if(i==d)
            S[i]=0;
        else
        {
            S[i]=999;
            for(j=i+1;j<=n;j++)
            {
                x=cost[i][j]+S[j];
                if(S[i]>x)
                    S[i]=x;
            }
        }
    }
    return S[s];
}
