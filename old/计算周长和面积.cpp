#include<stdio.h>
#include<stdlib.h>

int main()
{
    float a,b,c,d;
    printf("欢迎使用本软件\n");
    printf("请输入长方形的长和宽，中间以逗号隔开\n");
    scanf("%f,%f",&a,&b);
    c = a*b;
    d = 2*(a+b);
    printf("这个长方形的面积是：%f\n",c);
    printf("这个长方形的周长是：%f\n",d);
    system("pause");
}
