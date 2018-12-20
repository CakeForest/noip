#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n,num[120];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	int m;
	scanf("%d",&m);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(num[i]==m)
			sum++;
	}
	printf("%d",sum);
	
	
	return 0;
}