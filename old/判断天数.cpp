#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("输入年月，判断此月的天数\n");
    int year,month;
    printf("请输入年份\n");
    scanf("%d",&year);
    printf("请输入月份\n");
    scanf("%d",&month);
    switch(month)
    {
         case 1:
         case 3:
         case 5:
         case 7:   
         case 8:
         case 10:
         case 12:printf("有31天\n");break;
         case 4:
         case 6:
         case 9:
         case 11:printf("有30天\n");break;
         case 2:printf("有%d天\n",(year%4==0)&&(year%100!=0)||(year%400==0)? 29:28);break;
         default:printf("输入错误\n");
    }
    system("pause"); 
}
