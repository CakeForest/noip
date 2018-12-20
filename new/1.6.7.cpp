#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[1200]={0},b[1200]={0};
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	
	
	
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i]*b[i];
	}
	printf("%lld",sum);
	
	
	
	
	
	
	
	
	return 0;
}