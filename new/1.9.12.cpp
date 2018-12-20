#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,j;
	scanf("%d",&n);
	int now,sum=1;
	int max=-1;
	scanf("%d",&j);
	now=j;
	
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&j);
		if(j==now)
			sum++;
		else
		{
			now=j;
			sum=1;
		}
		if(sum>max)
			max=sum;
	}
	
	printf("%d",max);
	
	return 0;
}