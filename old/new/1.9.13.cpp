#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,j;
	scanf("%d",&n);
	int a[200]={0};
	int b[20020]={0};
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&j);
		if(a[j]==0)
		{
			b[sum]=j;
			sum++;
		}
		a[j]++;
	}
	
	for(int i=0;i<sum;i++)
	{
		printf("%d",b[i]);
		if(i!=sum-1)
			printf(" ");
	}
	
	return 0;
}