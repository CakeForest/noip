#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int num[120];
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	
	for(int i=n;i>=1;i--)
	{
		printf("%d",num[i]);
		if(i!=1)
			printf(" ");
	}
	
	return 0;
}