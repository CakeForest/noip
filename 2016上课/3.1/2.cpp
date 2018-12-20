#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int px(int *a,int *b,int *c)
{
	int p;
	if(*a>*b)
	{
		p=*a;
		*a=*b;
		*b=p;
	}
	if(*b>*c)
	{
		p=*b;
		*b=*c;
		*c=p;
	}
	if(*a>*c)
	{
		p=*a;
		*a=*c;
		*c=p;
	}
	
	
}

int main()
{
	int a=-5,b=7,c=0;
	printf("previous:%d %d %d\n",a,b,c);
	px(&a,&b,&c);
	printf("now:%d %d %d",a,b,c);
	
	return 0;
}
