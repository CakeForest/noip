#include<stdio.h>
#include<stdlib.h>

int main()
{
    int y;
    printf("请输入年份\n");
    scanf("%d",&y);
    if((y%4==0)&&(y%100!=0)||(y%400==0))
    {
        printf("%d年是闰年\n",y);
    }
    else
    {
        printf("%d年不是闰年\n",y);
    }
    system("pause"); 
}
