#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,a[10020];
	int aim;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&aim);
	
	for(int i=1;i<=n;i++)
	{
		if(aim==a[i])
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}