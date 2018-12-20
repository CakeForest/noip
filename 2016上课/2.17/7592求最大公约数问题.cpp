#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int work(int a,int b)
{
	int max=a>b?a:b;
	int min=a>b?b:a;
	return max%min==0?min:work(min,max%min);
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",work(a,b));
	return 0;
}
