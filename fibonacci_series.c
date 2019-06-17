#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,a,b,i;
    printf("Enter term no. in the fibonacci series: ");
    scanf("%d",&n);
    int *table=(int*)malloc((n+1)*sizeof(int));
    printf("Enter first two terms: ");
    scanf("%d %d",&a,&b);
    for(i=1;i<=n;i++)
        table[i]=111;
    int x=fibonacci(a,b,n,table);
    printf("%dth term is %d",n,x);
    return 0;
}
int fibonacci(int a,int b,int n,int table[])
{
    int x,y;
    if(n==1)
        return a;
    else if(n==2)
        return b;
    else
    {
        if(table[n-1]==111)
        {
            x=fibonacci(a,b,n-1,table);
            table[n-1]=x;
        }
        else
            x=table[n-1];
        if(table[n-2]==111)
        {
            y=fibonacci(a,b,n-2,table);
            table[n-2]=y;
        }
        else
            y=table[n-2];
        return x+y;
    }
}
