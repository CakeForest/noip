#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float a,b,c,p,s;
	printf("�����������������ߵĳ��ȣ�\n");
	printf("������a��\n");
	scanf("%f",&a);
	printf("������b��\n");
	scanf("%f",&b);
	printf("������c��\n");
	scanf("%f",&c);
    if((a+b>c)&&(a+c>b)&&(b+c>a))
    {
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));//���׹�ʽ�����
        printf("�����ε�����ǣ�%f\n",s);
    }
    else
    {
        printf("�����β�����\n");
    }
    system("pause");
}

