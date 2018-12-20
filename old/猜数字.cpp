#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
    int n,x,cishu;
    bool a;
    char b;
    srand(time(NULL));
    printf("请输入竞猜范围:(a-b)(|a-b|≥10)\n");
    int aa,bb;
    a1a1:scanf("%d %d",&aa,&bb);
    if(abs(aa-bb)>=10)
        n=100+rand()%(abs(aa-bb));
    else
        {
        printf("输入有误，请重新输入\n");
        goto a1a1;
        }
    do
    {
        cishu=0;
        do
        {
            printf("请输入竞猜数字：");
            scanf("%d",&x);
            if(x==468521)
            {
            printf("正确答案是：%d\n\n",n);
            goto again;
            }
            if(x>n)
            printf("\n猜大了\n");
            if(x<n)
            printf("\n猜小了\n");
            if(x==n)
            printf("\n猜对了\n");
            cishu++;
            if(cishu==10)
            printf("输入468521可查看正确答案\n");
        }while(x!=n);
        printf("竞猜次数为：%d\n",cishu);
        again:printf("还要再来一次吗？（Y or N）\n");
        scanf("%c",&b);
        scanf("%c",&b);
        if(b=='Y'||b=='y')
        {
            a=1;
            system("cls");
        }
        else
        a=0;
    }while(a);
    return(0);
}

