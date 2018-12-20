#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a[5];
	int *p=a;
	for(int i=0;i<=4;i++)
		scanf("%d",p++);
	p--;
	
	for(int i=0;i<=4;i++)
		printf("%d ",*p--);
	

	
	return 0;
}
