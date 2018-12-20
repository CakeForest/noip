#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int result[100];
int a(int input1,long input2);
int main()
{
    printf("请输入要转换的进制数和数据\n");
	int jinzhi=0;
    long shuju=0;
	scanf("%d %d",&jinzhi,&shuju);
    int output=a(jinzhi,shuju);
	printf("\n10进制转%d进制   原数据:%d\n结果:",jinzhi,shuju);
    for(;output>=1;output--)
    {
    	printf("%d",result[output]);
	}
    printf("\n\n");
	system("pause");




}

int a(int input1,long input2)//input1 欲转换成的进制数,   input2 十进制数据 
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
