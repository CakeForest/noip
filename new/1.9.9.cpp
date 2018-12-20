#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,a[10020]={0};
	scanf("%d",&n);
	int x,max=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]++;
		max=x>max?x:max;
	}
	
	for(int i=0;i<=max;i++)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
}