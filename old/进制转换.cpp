#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int result[100];
int a(int input1,long input2);
int main()
{
    printf("������Ҫת���Ľ�����������\n");
	int jinzhi=0;
    long shuju=0;
	scanf("%d %d",&jinzhi,&shuju);
    int output=a(jinzhi,shuju);
	printf("\n10����ת%d����   ԭ����:%d\n���:",jinzhi,shuju);
    for(;output>=1;output--)
    {
    	printf("%d",result[output]);
	}
    printf("\n\n");
	system("pause");




}

int a(int input1,long input2)//input1 ��ת���ɵĽ�����,   input2 ʮ�������� 
{
	long sum=input2;
	int i;
	for(i=1;sum>=input1;i++)
	{
		int yushu=sum%input1;
		sum=sum/input1;
		result[i]=yushu;
	}
	result[i]=sum;
	return i;
}
