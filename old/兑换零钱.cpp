#include<stdio.h>
#include<stdlib.h>

int main()
{
    long money=100;
    int a=0;
    int i=0;
    bool b=1,c=1;
    int z;
    printf("兑换零钱\n");
    printf("你有几张100元钱？\n");
    scanf("%d",&z);
    money*=z;
    for(long fifty=0;b;fifty++)
    {
        a=money-fifty*50;
        if(a>=0)
        {
            for(long twenty=0;c;twenty++)
            {
                a=a-twenty*20;
                if(a>=0&&a%10==0)
                {
                    i++;
                    printf("50元%ld张 20元%ld张 10元%ld张\n",fifty,twenty,a/10);
                }
                else
                c=0;
            }
            c=1;
        }
        else
        b=0;
    }
    printf("有%d种方案\n",i);
    system("pause");
}
