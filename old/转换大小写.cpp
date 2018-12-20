#include<stdio.h>
#include<stdlib.h>
int main()
{
    char a;
    printf("请输入一个大写字母按回车键结束\n");
    a=getchar();
    putchar(a+32);
    printf("\n");
    system("pause");
}
