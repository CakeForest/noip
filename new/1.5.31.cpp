#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long sum=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long sum1=1;
		for(int m=1;m<=i;m++)
		{
			sum1*=m;
		}
		sum+=sum1;
	}
	
	printf("%lld",sum);
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
