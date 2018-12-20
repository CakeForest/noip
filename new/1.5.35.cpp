#include<stdio.h>
#include<stdlib.h>
#include<cstring>

int sum=0;
void judge(int n)
{
	if(n>=10)
	{
		judge(n%10);
		judge(n/10);
	}
	else
	{
		if(n==1)
			sum++;
	}
}

int main()
{


	
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		judge(i);
	}
	printf("%d",sum);

	return 0;
}
