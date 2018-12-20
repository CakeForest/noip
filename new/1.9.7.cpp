#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,a[300];
	scanf("%d",&n);
	int max=-1000001;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
		if(a[i]>max)
			max=a[i];
	}
	
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=max)	
			sum+=a[i];
	}
	
	printf("%lld",sum);
	
	
	return 0;
}