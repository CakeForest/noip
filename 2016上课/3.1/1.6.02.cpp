#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int sum=0,max;
	int a[10];
	int *p=a;
	for(int i=0;i<=9;i++)
		scanf("%d",p++);
	p--;
	scanf("%d",&max);
	max+=30;
	for(int i=0;i<=9;i++)
	{
		if(*p<=max)
			sum++;
		p--;
	}
	printf("%d",sum);
	
	return 0;
}
