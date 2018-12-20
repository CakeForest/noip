#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x;
    do{
    scanf("%d",&x);
    }while(x>=47&&printf("请输入48以下的数字\n")||x<1&&printf("请输入大于0的数字\n"));
    printf("f1=0 f2=1 ");
    long a=0,b=1;
    long sum=a+b;
    for(int i=3;i<=x;i++)
    {

        if(i%2==0)
        {
            a=sum;
            sum=a+b;
        }
        else
        {
            b=sum;
            sum=a+b;
        }
        printf("f%d=%d ",i,sum);
        if(i%4==0)
            printf("\n");
    }
    system("pause");
    return(0);
}

