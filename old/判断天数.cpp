#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("�������£��жϴ��µ�����\n");
    int year,month;
    printf("���������\n");
    scanf("%d",&year);
    printf("�������·�\n");
    scanf("%d",&month);
    switch(month)
    {
         case 1:
         case 3:
         case 5:
         case 7:   
         case 8:
         case 10:
         case 12:printf("��31��\n");break;
         case 4:
         case 6:
         case 9:
         case 11:printf("��30��\n");break;
         case 2:printf("��%d��\n",(year%4==0)&&(year%100!=0)||(year%400==0)? 29:28);break;
         default:printf("�������\n");
    }
    system("pause"); 
}
