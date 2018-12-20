#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float a,b,c,p,s;
	printf("请输入三角形三条边的长度：\n");
	printf("请输入a：\n");
	scanf("%f",&a);
	printf("请输入b：\n");
	scanf("%f",&b);
	printf("请输入c：\n");
	scanf("%f",&c);
    if((a+b>c)&&(a+c>b)&&(b+c>a))
    {
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));//海伦公式求面积
        printf("三角形的面积是：%f\n",s);
    }
    else
    {
        printf("三角形不成立\n");
    }
    system("pause");
}

