#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m=0;// 
    int n=0;
    scanf("%d,%d",&m,&n);
    if(m>0&&n>0)
    {
        for(int a=1;a<=n;a++)
        {
            for(int i=1;i<=m;i++)
            { 
                printf("@");
            }
            printf("\n");
        }    
    }
    system("pause");
}
