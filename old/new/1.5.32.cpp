#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	double sum=1.0;
	
	for(int i=1;i<=n;i++)
	{
		long long sum1=1;
		for(int m=1;m<=i;m++)
		{
			sum1*=m;
		}
		sum+=1.0/sum1;
	}
	
	printf("%.10lf",sum);
	
	
	
	
	
	
	
	return 0;
}
