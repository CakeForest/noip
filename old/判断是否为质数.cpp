#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x;
    bool a=0;
    printf("请输入数字：");
    scanf("%ld",&x);
    if(x==1)
    {
        printf("既不是质数也不是合数\n");
        //goto end;
    }
    int i=2;
    for(;i<=x/2;i++)
    {
        if(x%i==0)
        {
            a=1;
        }
    }
    printf("%s\n",a?"不是质数,它的因数是:%d",i:"是质数");
    system("pause");

}

