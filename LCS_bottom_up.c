#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int LCS_bottom_up(char str1[],char str2[]);
int main()
{
    char *str1=(char*)malloc(50*sizeof(char));
    char *str2=(char*)malloc(50*sizeof(char));
    printf("Enter first string: ");
    scanf("%[^\n]",str1);
    printf("Enter second string: ");
    scanf("%*c%[^\n]",str2);
    int len=LCS_bottom_up(str1,str2);
    printf("\nLength of longest common subsequence = %d\n",len);
    return 0;
}
int LCS_bottom_up(char str1[],char str2[])
{
    int i,j;
    int m=strlen(str1);
    int n=strlen(str2);
    int **LCS=(int**)malloc(m*sizeof(int*));
    for(i=0;i<=m-1;i++)
        LCS[i]=(int*)malloc(n*sizeof(int));
    for(i=0;i<=m-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            if(str1[i]==str2[j])
            {
                if(i-1==-1 || j-1==-1)
                    LCS[i][j]=1;
                else
                    LCS[i][j]=1+LCS[i-1][j-1];
            }
            else
            {
                if(i-1==-1 && j-1==-1)
                   LCS[i][j]=0;
                else if(i-1==-1)
                    LCS[i][j]=LCS[i][j-1];
                else if(j-1==-1)
                    LCS[i][j]=LCS[i-1][j];
                else
                    LCS[i][j]=(LCS[i][j-1]>=LCS[i-1][j])?LCS[i][j-1]:LCS[i-1][j];
            }
        }
    }
    i=m-1;
    j=n-1;
    int k=m<n?m:n;
    char *x=(char*)malloc(k*sizeof(char));
    k=0;
    while(i>-1 && j>-1)
    {
        if(str1[i]==str2[j])
        {
            x[k]=str1[i];
            k++;
            i--;
            j--;
        }
        else
        {
            if(i-1==-1 && j-1==-1)
            {
                i--;
                j--;
            }
            else if(i-1==-1)
                j--;
            else if(j-1==-1)
                i--;
            else
            {
                if(LCS[i][j-1]>=LCS[i-1][j])
                    j--;
                else
                    i--;
            }
        }
    }
    x[k]=0;
    strrev(x);
    printf("\nLongest Common Subsequence : %s\n",x);
    return LCS[m-1][n-1];
}
