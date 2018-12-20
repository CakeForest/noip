#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n;
	int a[20000]={0};
	scanf("%d",&n);
	int j=2;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(a[i]==0)
		{
			while(i*j<=n)
			{
				a[i*j]=1;
				j++;
			}
			j=2;
		}
	}
	
	int sum=0;
	for(int i=2;i<=n-2;i++)
	{
		if(a[i]+a[i+2]==0)
		{
			sum++;
			printf("%d %d\n",i,i+2);
		}
	}
	if(sum==0)
		printf("empty");
	
	return 0;
}